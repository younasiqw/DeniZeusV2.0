#pragma once
#include "../managers/memory_manager.h"



class CRecvTable
{
public:
	class CRecvProp
	{
	public:
		const char* GetVarName()
		{
			DWORD offset = csgo.ReadMemory<DWORD>((DWORD)this);
			char varName[128];
			csgo.ReadMemoryEx<char[128]>(offset, sizeof(varName), varName);
			return varName;
		}

		int GetOffset()
		{
			return csgo.ReadMemory<int>((DWORD)this + 0x2C);
		}
		CRecvTable* GetDataTable()
		{
			return csgo.ReadMemory<CRecvTable*>((DWORD)this + 0x28);
		}
	};

	const char* GetTableName()
	{
		DWORD offset = csgo.ReadMemory<DWORD>((DWORD)this + 0xC);
		char tableName[128];
		csgo.ReadMemoryEx<char[128]>(offset, sizeof(tableName), tableName);
		return tableName;
	}

	int GetMaxProp()
	{
		return csgo.ReadMemory<int>((DWORD)this + 0x4);
	}

	CRecvProp* GetProperty(int iIndex)
	{
		return (CRecvProp*)(csgo.ReadMemory<DWORD>((DWORD)this) + 0x3C * iIndex);
	}

};

class ClientClass
{
public:
	const char* GetNetworkName()
	{
		DWORD offset = csgo.ReadMemory<DWORD>((DWORD)this + 0x8);
		char networkName[128];
		csgo.ReadMemoryEx<char[128]>(offset, sizeof(networkName), networkName);
		return networkName;
	}

	ClientClass* GetNextClass()
	{
		return csgo.ReadMemory<ClientClass*>((DWORD)this + 0x10);
	}

	CRecvTable* GetTable()
	{
		return csgo.ReadMemory<CRecvTable*>((DWORD)this + 0xC);
	}
};

DWORD inline NetVar(const char* szClassName, const char* szNetVar)
{
	static DWORD dwWorld = csgo.SigScanner(SCAN_MODE::CLIENT_SCAN, (char*)"DT_TEWorldDecal", (char*)"xxxxxxxxxxxxxxx");
	static DWORD dwClasses = csgo.ReadMemory<DWORD>(csgo.SigScanner(SCAN_MODE::CLIENT_SCAN, (char*)&dwWorld, (char*)"xxxx") + 0x2B);
	ClientClass* pClass = (ClientClass*)dwClasses;

	if (!pClass)
	{
		return NULL;
	}

	for (; pClass; pClass = pClass->GetNextClass())
	{
		if(strcmp("m_vecMins", szNetVar) && strcmp("m_vecMaxs", szNetVar) && strcmp("m_Collision", szNetVar) && strcmp("m_CollisionGroup", szNetVar))
		if (strcmp(szClassName, pClass->GetTable()->GetTableName()))
			continue;

		for (int i = 0; i < pClass->GetTable()->GetMaxProp(); i++)
		{
			CRecvTable::CRecvProp* pRecvProp = pClass->GetTable()->GetProperty(i);

			if (isdigit(pRecvProp->GetVarName()[0]))
				continue;

			if (!strcmp(pRecvProp->GetVarName(), szNetVar))
			{
				return pRecvProp->GetOffset();
			}

			if (!pRecvProp->GetDataTable())
				continue;

			for (int j = 0; j < pRecvProp->GetDataTable()->GetMaxProp(); ++j)
			{
				CRecvTable::CRecvProp* pRecvProp2 = pRecvProp->GetDataTable()->GetProperty(j);

				if (isdigit(pRecvProp2->GetVarName()[0]))
					continue;

				if (!strcmp(pRecvProp2->GetVarName(), szNetVar))
				{
					return pRecvProp2->GetOffset();
				}

				if (!pRecvProp2->GetDataTable())
					continue;

				for (int k = 0; k < pRecvProp2->GetDataTable()->GetMaxProp(); ++k)
				{
					CRecvTable::CRecvProp* pRecvProp3 = pRecvProp2->GetDataTable()->GetProperty(k);

					if (isdigit(pRecvProp3->GetVarName()[0]))
						continue;

					if (!strcmp(pRecvProp3->GetVarName(), szNetVar))
					{
						return pRecvProp3->GetOffset();
					}
				}
			}
		}
	}

	return 0;
}