#include "hooks.hpp"
#include <intrin.h>  

#include "players.hpp"

#include "helpers/utils.hpp"
#pragma intrinsic(_ReturnAddress)  

namespace Hooks {

	void Initialize()
	{
		hlclient_hook.setup(g_CHLClient);
		hlclient_hook.hook_index(index::CreateMove, hkCreateMove_Proxy);
	}
	//--------------------------------------------------------------------------------
	void Shutdown()
	{
		hlclient_hook.unhook_all();
	}
	//--------------------------------------------------------------------------------
	void __stdcall hkCreateMove(int sequence_number, float input_sample_frametime, bool active, bool& bSendPacket)
	{
		static auto oCreateMove = hlclient_hook.get_original<decltype(&hkCreateMove_Proxy)>(index::CreateMove);

		oCreateMove(g_CHLClient, 0, sequence_number, input_sample_frametime, active);

		for (int i = 1; i < g_GlobalVars->maxClients; i++)
		{
			C_BasePlayer* entity = (C_BasePlayer*)(g_EntityList->GetClientEntity(i));	

			if (!entity)
				continue;

			if (entity == g_LocalPlayer)
				continue;

			if (!entity->IsPlayer())
				continue;

			if (entity->IsDormant() || !entity->IsAlive()) {
				is_visible[entity->GetGlowIndex()] = false;
				continue;
			}

			is_visible[entity->GetGlowIndex()] = g_LocalPlayer->CanSeePlayer(entity, Hitboxes::HITBOX_CHEST);
		}
	}
	//--------------------------------------------------------------------------------
	__declspec(naked) void __fastcall hkCreateMove_Proxy(void* _this, int, int sequence_number, float input_sample_frametime, bool active)
	{
		__asm
		{
			push ebp
			mov  ebp, esp
			push ebx
			lea  ecx, [esp]
			push ecx
			push dword ptr[active]
			push dword ptr[input_sample_frametime]
			push dword ptr[sequence_number]
			call Hooks::hkCreateMove
			pop  ebx
			pop  ebp
			retn 0Ch
		}
	}
}
