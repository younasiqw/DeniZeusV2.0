#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>
#include <tchar.h>
#include <iterator>

union hex_float {
	float a;
	DWORD bytes;
};
union hex_dword {
	unsigned int a;
	char bytes[4];
};

std::string client_name("client_panorama.dll");
std::string engine_name("engine.dll");
std::string visibilty_check_name("VisibilityCheck.dll");

struct Vec {
	float x, y, z;
};

enum SCAN_MODE {
	CLIENT_SCAN,
	ENGINE_SCAN,
	VISIBLE_SCAN
};

class MemoryEditor
{
private:
	bool init = false;
	DWORD dwPID;
	DWORD dwVisibleCheck;
public:
	bool visible_check_init = false;
	HANDLE hProcess;
	DWORD dwClient;
	DWORD dwEngine;

	MemoryEditor() {
		std::cout << "Waiting csgo.exe..." << std::endl;
		do {
			Sleep(100);
			dwPID = GetProcessIdByProcessName("csgo.exe");
		} while (!dwPID);

		std::cout << "Waiting " << client_name << "..." << std::endl;
		do {
			Sleep(100);
			dwClient = GetModuleBaseAddress(dwPID, client_name.c_str());
		} while (!dwClient);

		std::cout << "Waiting " << engine_name << "..." << std::endl;
		do {
			Sleep(100);
			dwEngine = GetModuleBaseAddress(dwPID, engine_name.c_str());
		} while (!dwEngine);
		

		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);

		

		if (hProcess != INVALID_HANDLE_VALUE) {
			init = true;
		}
		else {
			MessageBox(NULL, _T("Process can't be opened!\nYou opened with admin rights?"), _T("Error"), MB_OK | MB_ICONERROR);
			exit(EXIT_FAILURE);
		}
		
		//Visiblity Check injector
		if (GetModuleBaseAddress(dwPID, visibilty_check_name.c_str()) == 0) {
			std::cout << "Visible check loading..." << std::endl;
			std::string visibility_directory; char buffer[MAX_PATH];
			GetModuleFileName(NULL, buffer, MAX_PATH);
			std::string::size_type pos = std::string(buffer).find_last_of("\\/");
			visibility_directory = std::string(buffer).substr(0, pos) + "\\" + visibilty_check_name;
			long dll_size = visibility_directory.length() + 1;
			LPVOID dll_name_alloc = VirtualAllocEx(hProcess, NULL, dll_size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
			if (dll_name_alloc == NULL)
			{
				std::cout << "Visible check cannot loaded! Closing..." << std::endl;
				exit(EXIT_FAILURE);
			}
			int dll_name_stat = WriteProcessMemory(hProcess, dll_name_alloc, visibility_directory.c_str(), dll_size, 0);
			if (dll_name_stat == 0) {
				std::cout << "Visible check cannot loaded! Closing..." << std::endl;
				exit(EXIT_FAILURE);
			}

			LPTHREAD_START_ROUTINE load_library = (LPTHREAD_START_ROUTINE)GetProcAddress(LoadLibrary("kernel32"), "LoadLibraryA"); //VAC FOLLOWING YOU WEWOWEWO
			HANDLE return_value = CreateRemoteThread(hProcess, NULL, 0, load_library, dll_name_alloc, 0, NULL);
			if (return_value == NULL) {
				std::cout << "Visible check cannot loaded! Closing..." << std::endl;
				exit(EXIT_FAILURE);
			}
			Sleep(2000);
			std::cout << "Visible check loaded!" << std::endl;
		}
		else {
			std::cout << "Visible check already loaded. Skipping..." << std::endl;
		}
		//End

		std::cout << "Waiting " << visibilty_check_name << "..." << std::endl;
		do {
			Sleep(100);
			dwVisibleCheck = GetModuleBaseAddress(dwPID, visibilty_check_name.c_str());
		} while (!dwVisibleCheck);
	}

	template <typename datatype>
	datatype ReadMemory(DWORD address)
	{
		datatype buffer;
		ReadProcessMemory(hProcess, (LPCVOID)address, &buffer, sizeof(datatype), NULL);
		return buffer;
	}

	template <typename datatype>
	void ReadMemoryEx(DWORD address, unsigned int size, datatype &buffer)
	{
		ReadProcessMemory(hProcess, (LPCVOID)address, &buffer, size, NULL);
	}

	template <typename datatype>
	void WriteMemory(DWORD address, datatype value)
	{
		WriteProcessMemory(hProcess, (LPVOID)address, &value, sizeof(value), NULL);
	}

	DWORD GetProcessIdByProcessName(const char* processName)
	{
		DWORD pID = NULL;
		HANDLE ss = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
		if (ss != INVALID_HANDLE_VALUE)
		{
			PROCESSENTRY32 pe;
			pe.dwSize = sizeof(PROCESSENTRY32);
			do
			{
				if (!strcmp(pe.szExeFile, processName))
				{
					pID = pe.th32ProcessID;
				}
			} while (Process32Next(ss, &pe));
			CloseHandle(ss);
		}
		return pID;
	}

	DWORD GetModuleBaseAddress(DWORD pID, const char* moduleName)
	{
		DWORD ModuleBaseAddress = NULL;

		HANDLE ss = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID);
		if (ss != INVALID_HANDLE_VALUE)
		{
			MODULEENTRY32 me;
			me.dwSize = sizeof(MODULEENTRY32);

			if (Module32First(ss, &me))
			{
				do
				{
					if (!strcmp(me.szModule, moduleName))
					{
						ModuleBaseAddress = (DWORD)me.modBaseAddr;
						break;
					}
				} while (Module32Next(ss, &me));
			}
			CloseHandle(ss);
		}
		return ModuleBaseAddress;
	}

	MODULEENTRY32 GetModule(DWORD pID, const char* moduleName)
	{
		MODULEENTRY32 ModuleBaseAddress = *new MODULEENTRY32();

		HANDLE ss = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID);
		if (ss != INVALID_HANDLE_VALUE)
		{
			MODULEENTRY32 me;
			me.dwSize = sizeof(MODULEENTRY32);

			if (Module32First(ss, &me))
			{
				do
				{
					if (!strcmp(me.szModule, moduleName))
					{
						ModuleBaseAddress = me;
						break;
					}
				} while (Module32Next(ss, &me));
			}
			CloseHandle(ss);
		}
		return ModuleBaseAddress;
	}

	uintptr_t IDAPattern(SCAN_MODE module, std::string pattern) {
		std::istringstream pattern_part(pattern);
		std::vector<std::string> parts(std::istream_iterator<std::string>{pattern_part}, std::istream_iterator<std::string>());
		std::vector<char> r_pattern;
		std::vector<char> r_mask;

		for (std::vector<std::string>::iterator itr = parts.begin(); itr != parts.end(); itr++) {
			if (*itr != "?") {
				int li_hex = std::stoi(*itr, nullptr, 16);
				r_pattern.push_back((char)li_hex);
				r_mask.push_back('x');
			}
			else {
				r_pattern.push_back(0);
				r_mask.push_back('?');
			}
		}

		return SigScannerIDA(module, r_pattern, r_mask);

	}

	uintptr_t FindPatternIDA(char* base, unsigned int size, std::vector<char> pattern, std::vector<char> mask)
	{
		size_t patternLength = mask.size();

		for (uintptr_t i = 0; i < size - patternLength; i++)
		{
			bool found = true;
			for (uintptr_t j = 0; j < patternLength; j++)
			{
				if (mask[j] != '?' && pattern[j] != *(char*)(base + i + j))
				{
					found = false;
					break;
				}
			}

			if (found)
			{
				return (uintptr_t)base + i;
			}
		}
		return 0;
	}

	uintptr_t FindPattern(char* base, unsigned int size, char* pattern, char* mask)
	{
		size_t patternLength = strlen(mask);

		for (uintptr_t i = 0; i < size - patternLength; i++)
		{
			bool found = true;
			for (uintptr_t j = 0; j < patternLength; j++)
			{
				if (mask[j] != '?' && pattern[j] != *(char*)(base + i + j))
				{
					found = false;
					break;
				}
			}

			if (found)
			{
				return (uintptr_t)base + i;
			}
		}
		return 0;
	}

	uintptr_t SigScannerIDA(SCAN_MODE module, std::vector<char> pattern, std::vector<char> mask)
	{
		MODULEENTRY32 modEntry = *new MODULEENTRY32();
		if (module == SCAN_MODE::CLIENT_SCAN) 
		{
			modEntry = GetModule(GetProcessId(hProcess), client_name.c_str());
		}
		else if(module == SCAN_MODE::ENGINE_SCAN) 
		{
			modEntry = GetModule(GetProcessId(hProcess), engine_name.c_str());
		}
		else if (module == SCAN_MODE::VISIBLE_SCAN) {
			modEntry = GetModule(GetProcessId(hProcess), visibilty_check_name.c_str());
		}
		
		uintptr_t start = (uintptr_t)modEntry.modBaseAddr;
		uintptr_t end = start + modEntry.modBaseSize;

		uintptr_t currentChunk = start;
		SIZE_T bytesRead;

		while (currentChunk < end)
		{
			DWORD oldprotect;
			VirtualProtectEx(hProcess, (void*)currentChunk, 4096, PROCESS_VM_READ | PROCESS_VM_WRITE, &oldprotect);

			byte buffer[4096];
			ReadProcessMemory(hProcess, (void*)currentChunk, &buffer, 4096, &bytesRead);

			VirtualProtectEx(hProcess, (void*)currentChunk, 4096, oldprotect, NULL);

			if (bytesRead == 0)
			{
				return 0;
			}

			uintptr_t InternalAddress = FindPatternIDA((char*)& buffer, bytesRead, pattern, mask);

			
			if (InternalAddress != 0)
			{
				uintptr_t offsetFromBuffer = InternalAddress - (uintptr_t)& buffer;
				return currentChunk + offsetFromBuffer;
			}

			else
			{
				currentChunk = currentChunk + bytesRead;
			}

		}
		return 0;
	}

	bool IsVisible(int i) {		
		static bool once = false;
		static DWORD adr_scan = IDAPattern(SCAN_MODE::VISIBLE_SCAN, "55 8B EC 8B 45 08 8A 80");

		if (!once) {
			adr_scan = ReadMemory<DWORD>(adr_scan + 0x10 + 0x2);
			once = true;
		}

		bool exitcode = ReadMemory<bool>(adr_scan + i);

		return exitcode;

	}

	uintptr_t SigScanner(SCAN_MODE module, char* pattern, char* mask)
	{
		MODULEENTRY32 modEntry;
		if (module == SCAN_MODE::CLIENT_SCAN) 
		{
			modEntry = GetModule(GetProcessId(hProcess), client_name.c_str());
		}
		else if(module == SCAN_MODE::ENGINE_SCAN) 
		{
			modEntry = GetModule(GetProcessId(hProcess), engine_name.c_str());
		}
		
		uintptr_t start = (uintptr_t)modEntry.modBaseAddr;
		uintptr_t end = start + modEntry.modBaseSize;

		uintptr_t currentChunk = start;
		SIZE_T bytesRead;

		while (currentChunk < end)
		{
			DWORD oldprotect;
			VirtualProtectEx(hProcess, (void*)currentChunk, 4096, PROCESS_VM_READ | PROCESS_VM_WRITE, &oldprotect);

			byte buffer[4096];
			ReadProcessMemory(hProcess, (void*)currentChunk, &buffer, 4096, &bytesRead);

			VirtualProtectEx(hProcess, (void*)currentChunk, 4096, oldprotect, NULL);

			if (bytesRead == 0)
			{
				return 0;
			}

			uintptr_t InternalAddress = FindPattern((char*)& buffer, bytesRead, pattern, mask);

			
			if (InternalAddress != 0)
			{
				uintptr_t offsetFromBuffer = InternalAddress - (uintptr_t)& buffer;
				return currentChunk + offsetFromBuffer;
			}

			else
			{
				currentChunk = currentChunk + bytesRead;
			}

		}
		return 0;
	}

};

MemoryEditor csgo;