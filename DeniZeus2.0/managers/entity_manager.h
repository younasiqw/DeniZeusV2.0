#pragma once
#include "../helpers/utilites.h"
#include "../managers/offset_manager.h"
#include "../managers/memory_manager.h"
#include "../managers/badresses_manager.h"

class sPlayer {
public:
	Vector origin = Vector(0.f, 0.f, 0.f);
	Vector bone_origin = Vector(0.f, 0.f, 0.f);
	QAngle view_angle = QAngle(0.f, 0.f, 0.f);
	int health = 0;
	int armor = 0;
	int team_id = 0;
	int glow_index = 0;
	int rank = 0;
	bool is_spotted = 0;
	bool is_jumping = 0;
	bool is_dormant = 0;
	bool is_chammed = 0;
	int index = 0;
	DWORD base = 0;

	Vector get_bone(int i) {
		Vector bonevec;
		DWORD adrBone = csgo.ReadMemory<DWORD>(base + Offsets::Netvars::m_dwBoneMatrix);
		sBone bone = csgo.ReadMemory<sBone>(adrBone + (0x30 * i));
		bonevec.x = bone.x; bonevec.y = bone.y; bonevec.z = bone.z;
		return bonevec;
	}

	player_info get_player_info() {
		
		return csgo.ReadMemory<player_info>(csgo.ReadMemory<uintptr_t>(csgo.ReadMemory<uintptr_t>(csgo.ReadMemory<uintptr_t>(Bases::PlayerInfoBase + 0x40) + 0xC) + 0x28 + (index * 0x34)));
	}

};

namespace player {
	sPlayer local;
	sPlayer other[32];
}

inline void update_Players() {
	while (true) {
		player::local.base = Bases::dwLocalPlayer;
		player::local.glow_index = 0;
		player::local.health = csgo.ReadMemory<int>(Bases::dwLocalPlayer + Offsets::Netvars::m_iHealth);
		player::local.is_jumping = !(csgo.ReadMemory<int>(Bases::dwLocalPlayer + Offsets::Netvars::m_fFlags) & PLAYER_ON_FLOOR);
		player::local.is_spotted = 0;
		player::local.origin = csgo.ReadMemory<Vector>(Bases::dwLocalPlayer + Offsets::Netvars::m_vecOrigin);
		player::local.origin += csgo.ReadMemory<Vector>(Bases::dwLocalPlayer + Offsets::Netvars::m_vecViewOffset);
		player::local.rank = csgo.ReadMemory<int>(Bases::dwLocalPlayer + Offsets::Netvars::m_rank);
		player::local.team_id = csgo.ReadMemory<int>(Bases::dwLocalPlayer + Offsets::Netvars::m_iTeamNum);

		for (int i = 1; i <= Bases::GlobalVar.maxClients; i++)
		{
			DWORD player = csgo.ReadMemory<DWORD>(Offsets::Signatures::dwEntityList + ((i) * 0x10));

			player::other[i].index = i;

			if (player == Bases::dwLocalPlayer || !player)
				continue;

			player::other[i].base = player;
			player::other[i].is_dormant = csgo.ReadMemory<bool>(player + Offsets::Netvars::m_bDormant);
			player::other[i].glow_index = csgo.ReadMemory<int>(player + Offsets::Netvars::m_iGlowIndex);
			player::other[i].is_jumping = !(csgo.ReadMemory<bool>(player + Offsets::Netvars::m_fFlags) & PLAYER_ON_FLOOR);
			player::other[i].origin = csgo.ReadMemory<Vector>(player + Offsets::Netvars::m_vecOrigin);

#ifdef _DEBUG //WE CANT FIND VISIBILITY CHECK ADDRESSES ON DEBUG MODE
			player::other[i].is_spotted = ((csgo.ReadMemory<int>(player + Offsets::Netvars::m_bSpottedByMask) & (1 << (csgo.ReadMemory<int>(Bases::dwLocalPlayer + 0x64) - 1))) > 0);
#else		
			player::other[i].is_spotted = csgo.IsVisible(player::other[i].glow_index);
#endif
			
			player::other[i].rank = csgo.ReadMemory<int>(player + Offsets::Netvars::m_rank);
			player::other[i].health = csgo.ReadMemory<int>(player + Offsets::Netvars::m_iHealth);
			player::other[i].armor = csgo.ReadMemory<int>(player + Offsets::Netvars::m_ArmorValue);
			player::other[i].team_id = csgo.ReadMemory<int>(player + Offsets::Netvars::m_iTeamNum);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}