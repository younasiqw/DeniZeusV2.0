#pragma once
#include "../helpers/netvar_scanner.h"
#include "../managers/memory_manager.h"

namespace Offsets {
	
	namespace Signatures {

		DWORD dwClientState;
		DWORD dwEntityList;
		DWORD dwForceAttack;
		DWORD dwForceJump;
		DWORD dwGameDir;
		DWORD dwInput;
		DWORD dwGlowObjectManager;
		DWORD dwLocalPlayer;
		DWORD dwPlayerResource;
		DWORD dwRadarBase;
		DWORD dwGlobalVars;
		DWORD dwbSendPackets;
		DWORD dwViewMatrix;
		DWORD dwScreenSize;
		DWORD model_ambient_min;
		DWORD mat_force_tonemap_scale;

		namespace ClientState {
			DWORD ViewAngles;
			DWORD State;
			DWORD PlayerInfo;
			DWORD m_iChokedCommands;
		}

	}

	namespace Netvars {

		DWORD m_bDormant;
		DWORD m_iAccount;
		DWORD m_ArmorValue;
		DWORD m_aimPunchAngle;
		DWORD m_bHasDefuser;
		DWORD m_bSpotted;
		DWORD m_bSpottedByMask;
		DWORD m_dwBoneMatrix;
		DWORD m_fFlags;
		DWORD m_flFallbackWear;
		DWORD m_flFlashMaxAlpha;
		DWORD m_hActiveWeapon;
		DWORD m_hMyWeapons;
		DWORD m_iCrosshairId;
		DWORD m_iEntityQuality;
		DWORD m_iFOVStart;
		DWORD m_iFOV;
		DWORD m_iGlowIndex;
		DWORD m_iHealth;
		DWORD m_iItemDefinitionIndex;
		DWORD m_iItemIDHigh;
		DWORD m_iTeamNum;
		DWORD m_nFallbackPaintKit;
		DWORD m_nFallbackSeed;
		DWORD m_vecOrigin;
		DWORD m_clrRender;
		DWORD m_rank;
		DWORD m_vecViewOffset;
		DWORD m_hViewModel;
		DWORD m_vecMins;
		DWORD m_vecMaxs;
		DWORD m_Collision;
		DWORD m_rgflCoordinateFrame;
		DWORD m_flDetectedByEnemySensorTime;

	}
}

void inline Dump_Offsets() {

	DWORD sig;

	//SIG SCAN

	sig = csgo.SigScanner(SCAN_MODE::ENGINE_SCAN, (char*)"g_ClientDLL->Init", (char*)"xxxxxxxxxxxxxxxxx");
	sig = csgo.SigScanner(SCAN_MODE::ENGINE_SCAN, (char*)&sig, (char*)"xxxx") + 0x12;
	Offsets::Signatures::dwGlobalVars = csgo.ReadMemory <DWORD>(sig);

	sig = csgo.IDAPattern(SCAN_MODE::ENGINE_SCAN, "A1 ? ? ? ? 33 D2 6A 00 6A 00 33 C9 89 B0");
	Offsets::Signatures::dwClientState = csgo.ReadMemory<DWORD>(sig + 1 /*Offset + 1*/);

	sig = csgo.IDAPattern(SCAN_MODE::ENGINE_SCAN, "F3 0F 11 80 ? ? ? ? D9 46 04 D9 05");
	Offsets::Signatures::ClientState::ViewAngles = csgo.ReadMemory<DWORD>(sig + 4 /*Offset + 4*/);

	sig = csgo.IDAPattern(SCAN_MODE::ENGINE_SCAN, "8B 89 ? ? ? ? 85 C9 0F 84 ? ? ? ? 8B 01");
	Offsets::Signatures::ClientState::PlayerInfo = csgo.ReadMemory<DWORD>(sig + 2 /*Offset + 2*/);
	
	sig = csgo.IDAPattern(SCAN_MODE::ENGINE_SCAN, "8B 8F ? ? ? ? 8B 87 ? ? ? ? 41");
	Offsets::Signatures::ClientState::m_iChokedCommands = csgo.ReadMemory<DWORD>(sig + 2 /*Offset + 2*/);
	
	sig = csgo.IDAPattern(SCAN_MODE::ENGINE_SCAN, "83 B8 ? ? ? ? ? 0F 94 C0 C3");
	Offsets::Signatures::ClientState::State = csgo.ReadMemory<DWORD>(sig + 2 /*Offset + 2*/);
	
	sig = csgo.IDAPattern(SCAN_MODE::CLIENT_SCAN, "BB ? ? ? ? 83 FF 01 0F 8C ? ? ? ? 3B F8");
	Offsets::Signatures::dwEntityList = csgo.ReadMemory<DWORD>(sig + 1 /*Offset + 1*/);
	
	sig = csgo.IDAPattern(SCAN_MODE::CLIENT_SCAN, "89 0D ? ? ? ? 8B 0D ? ? ? ? 8B F2 8B C1 83 CE 04");
	Offsets::Signatures::dwForceAttack = csgo.ReadMemory<DWORD>(sig + 2 /*Offset + 2*/);
	
	sig = csgo.IDAPattern(SCAN_MODE::CLIENT_SCAN, "8B 0D ? ? ? ? 8B D6 8B C1 83 CA 02");
	Offsets::Signatures::dwForceJump = csgo.ReadMemory<DWORD>(sig + 2 /*Offset + 2*/);
	
	sig = csgo.IDAPattern(SCAN_MODE::ENGINE_SCAN, "68 ? ? ? ? 8D 85 ? ? ? ? 50 68 ? ? ? ? 68");
	Offsets::Signatures::dwGameDir = csgo.ReadMemory<DWORD>(sig + 1 /*Offset + 1*/);
		
	sig = csgo.IDAPattern(SCAN_MODE::ENGINE_SCAN, "A1 ? ? ? ? 03 44 24 ? 89 44 24");
	Offsets::Signatures::dwScreenSize = csgo.ReadMemory<DWORD>(sig + 1 /*Offset + 1*/);
		
	sig = csgo.IDAPattern(SCAN_MODE::CLIENT_SCAN, "0F 10 05 ? ? ? ? 8D 85 ? ? ? ? B9");
	Offsets::Signatures::dwViewMatrix = csgo.ReadMemory<DWORD>(sig + 3 /*Offset + 3*/) + 0xB0 /*Extra + 176*/;
		
	sig = csgo.IDAPattern(SCAN_MODE::ENGINE_SCAN, "B3 01 8B 01 8B 40 10 FF D0 84 C0 74 0F 80 BF ? ? ? ? ? 0F 84");
	Offsets::Signatures::dwbSendPackets = csgo.ReadMemory<DWORD>(sig) + 1  /*Extra + 1*/;
	
	sig = csgo.IDAPattern(SCAN_MODE::CLIENT_SCAN, "A1 ? ? ? ? A8 01 75 4B");
	Offsets::Signatures::dwGlowObjectManager = csgo.ReadMemory<DWORD>(sig + 1 /*Offset + 1*/) + 4 /*Extra + 4*/;
	
	sig = csgo.IDAPattern(SCAN_MODE::CLIENT_SCAN, "8D 34 85 ? ? ? ? 89 15 ? ? ? ? 8B 41 08 8B 48 04 83 F9 FF");
	Offsets::Signatures::dwLocalPlayer = csgo.ReadMemory<DWORD>(sig + 3 /*Offset + 3*/) + 4 /*Extra + 4*/;
	
	sig = csgo.IDAPattern(SCAN_MODE::CLIENT_SCAN, "B9 ? ? ? ? F3 0F 11 04 24 FF 50 10");
	Offsets::Signatures::dwInput = csgo.ReadMemory<DWORD>(sig + 1 /*Offset + 1*/);

	sig = csgo.IDAPattern(SCAN_MODE::CLIENT_SCAN, "8B 3D ? ? ? ? 85 FF 0F 84 ? ? ? ? 81 C7");
	Offsets::Signatures::dwPlayerResource = csgo.ReadMemory<DWORD>(sig + 2 /*Offset + 2*/);

	sig = csgo.IDAPattern(SCAN_MODE::ENGINE_SCAN, "F3 0F 10 0D ? ? ? ? F3 0F 11 4C 24 ? 8B 44 24 20 35 ? ? ? ? 89 44 24 0C");
	Offsets::Signatures::model_ambient_min = csgo.ReadMemory<DWORD>(sig + 4 /*Offset + 4*/);
	
	sig = csgo.IDAPattern(SCAN_MODE::CLIENT_SCAN, "A1 ? ? ? ? 8B 0C B0 8B 01 FF 50 ? 46 3B 35 ? ? ? ? 7C EA 8B 0D");
	Offsets::Signatures::dwRadarBase = csgo.ReadMemory<DWORD>(sig + 1 /*Offset + 1*/);
	
	sig = csgo.IDAPattern(SCAN_MODE::CLIENT_SCAN, "8B 0D ? ? ? ? 81 F9 ? ? ? ? 75 2B");
	Offsets::Signatures::mat_force_tonemap_scale = csgo.ReadMemory<DWORD>(csgo.ReadMemory<DWORD>(sig + 2 /*Offset + 2*/));
	
	sig = csgo.IDAPattern(SCAN_MODE::CLIENT_SCAN, "8A 81 ? ? ? ? C3 32 C0");
	Offsets::Netvars::m_bDormant = csgo.ReadMemory<DWORD>(sig + 2 /*Offset + 2*/) + 8 /*Extra + 8*/;
	
	//SIG SCAN END

	//NETVAR SCAN

	Offsets::Netvars::m_iTeamNum = NetVar("DT_BaseEntity", "m_iTeamNum");
	Offsets::Netvars::m_ArmorValue = NetVar("DT_CSPlayer", "m_ArmorValue");
	Offsets::Netvars::m_aimPunchAngle = NetVar("DT_BasePlayer", "m_Local") + NetVar("DT_BasePlayer", "m_aimPunchAngle");
	Offsets::Netvars::m_bHasDefuser = NetVar("DT_CSPlayer", "m_bHasDefuser");
	Offsets::Netvars::m_bSpotted = NetVar("DT_BaseEntity", "m_bSpotted");
	Offsets::Netvars::m_bSpottedByMask = NetVar("DT_BaseEntity", "m_bSpottedByMask");
	Offsets::Netvars::m_dwBoneMatrix = NetVar("DT_BaseAnimating", "m_nForceBone") + 28;
	Offsets::Netvars::m_fFlags = NetVar("DT_CSPlayer", "m_fFlags");
	Offsets::Netvars::m_flFallbackWear = NetVar("DT_BaseAttributableItem", "m_flFallbackWear");
	Offsets::Netvars::m_flFlashMaxAlpha = NetVar("DT_CSPlayer", "m_flFlashMaxAlpha");
	Offsets::Netvars::m_hActiveWeapon = NetVar("DT_BasePlayer", "m_hActiveWeapon");
	Offsets::Netvars::m_hMyWeapons = NetVar("DT_BasePlayer", "m_hActiveWeapon") - 256;
	Offsets::Netvars::m_iCrosshairId = NetVar("DT_CSPlayer", "m_bHasDefuser") + 92;
	Offsets::Netvars::m_iEntityQuality = NetVar("DT_BaseAttributableItem", "m_iEntityQuality");
	Offsets::Netvars::m_iFOVStart = NetVar("DT_CSPlayer", "m_iFOVStart");
	Offsets::Netvars::m_iFOV = NetVar("DT_CSPlayer", "m_iFOV");
	Offsets::Netvars::m_iGlowIndex = NetVar("DT_CSPlayer", "m_flFlashDuration") + 24;
	Offsets::Netvars::m_iHealth = NetVar("DT_BasePlayer", "m_iHealth");
	Offsets::Netvars::m_iItemDefinitionIndex = NetVar("DT_BaseAttributableItem", "m_iItemDefinitionIndex");
	Offsets::Netvars::m_iItemIDHigh = NetVar("DT_BaseAttributableItem", "m_iItemIDHigh");
	Offsets::Netvars::m_nFallbackPaintKit = NetVar("DT_BaseAttributableItem", "m_nFallbackPaintKit");
	Offsets::Netvars::m_nFallbackSeed = NetVar("DT_BaseAttributableItem", "m_nFallbackSeed");
	Offsets::Netvars::m_vecOrigin = NetVar("DT_CSPlayer", "m_vecOrigin");
	Offsets::Netvars::m_clrRender = NetVar("DT_BaseEntity", "m_clrRender");
	Offsets::Netvars::m_rank = NetVar("DT_CSPlayer", "m_rank");
	Offsets::Netvars::m_flDetectedByEnemySensorTime = NetVar("DT_CSPlayer", "m_flDetectedByEnemySensorTime");
	Offsets::Netvars::m_vecViewOffset = NetVar("DT_CSPlayer", "m_vecViewOffset[0]");
	Offsets::Netvars::m_iAccount = NetVar("DT_CSPlayer", "m_iAccount");
	Offsets::Netvars::m_hViewModel= NetVar("DT_BasePlayer", "m_hViewModel[0]");
	Offsets::Netvars::m_rgflCoordinateFrame = NetVar("DT_CSPlayer", "m_CollisionGroup") - 0x30;
	Offsets::Netvars::m_vecMaxs = NetVar("BLALALA", "m_vecMaxs");    // I disabled class check for these
	Offsets::Netvars::m_vecMins = NetVar("BLALALA", "m_vecMins");    // because my netvar scanner shit coded...
	Offsets::Netvars::m_Collision = NetVar("BLALALA", "m_Collision");

	//NETVAR SCAN END


#ifdef _DEBUG
	std::cout << std::endl;
	std::cout << "========== SIGNATURES ==========" << std::endl;
	std::cout << std::endl;
	std::cout << "dwClientState: " << std::hex << std::uppercase << Offsets::Signatures::dwClientState << std::endl;
	std::cout << "dwClientState_ViewAngles: " << std::hex << std::uppercase << Offsets::Signatures::ClientState::ViewAngles << std::endl;
	std::cout << "dwClientState_State: " << std::hex << std::uppercase << Offsets::Signatures::ClientState::State << std::endl;
	std::cout << "dwClientState_PlayerInfo: " << std::hex << std::uppercase << Offsets::Signatures::ClientState::PlayerInfo << std::endl;
	std::cout << "m_iChokedCommands: " << std::hex << std::uppercase << Offsets::Signatures::ClientState::m_iChokedCommands << std::endl;
	std::cout << "dwEntityList: " << std::hex << std::uppercase << Offsets::Signatures::dwEntityList << std::endl;
	std::cout << "dwForceAttack: " << std::hex << std::uppercase << Offsets::Signatures::dwForceAttack << std::endl;
	std::cout << "dwbSendPackets: " << std::hex << std::uppercase << Offsets::Signatures::dwbSendPackets << std::endl;
	std::cout << "dwForceJump: " << std::hex << std::uppercase << Offsets::Signatures::dwForceJump << std::endl;
	std::cout << "dwGameDir: " << std::hex << std::uppercase << Offsets::Signatures::dwGameDir << std::endl;
	std::cout << "dwInput: " << std::hex << std::uppercase << Offsets::Signatures::dwInput << std::endl;
	std::cout << "dwGlowObjectManager: " << std::hex << std::uppercase << Offsets::Signatures::dwGlowObjectManager << std::endl;
	std::cout << "dwLocalPlayer: " << std::hex << std::uppercase << Offsets::Signatures::dwLocalPlayer << std::endl;
	std::cout << "dwPlayerResource: " << std::hex << std::uppercase << Offsets::Signatures::dwPlayerResource << std::endl;
	std::cout << "dwRadarBase: " << std::hex << std::uppercase << Offsets::Signatures::dwRadarBase << std::endl;
	std::cout << "dwGlobalVars: " << std::hex << std::uppercase << Offsets::Signatures::dwGlobalVars << std::endl;
	std::cout << "dwViewMatrix: " << std::hex << std::uppercase << Offsets::Signatures::dwViewMatrix << std::endl;
	std::cout << "dwScreenSize: " << std::hex << std::uppercase << Offsets::Signatures::dwScreenSize << std::endl;
	std::cout << "model_ambient_min: " << std::hex << std::uppercase << Offsets::Signatures::model_ambient_min << std::endl;
	std::cout << "mat_force_tonemap_scale: " << std::hex << std::uppercase << Offsets::Signatures::mat_force_tonemap_scale << std::endl;
	std::cout << "============ NETVARS ===========" << std::endl;
	std::cout << std::endl;
	std::cout << "m_bDormant: " << std::hex << std::uppercase << Offsets::Netvars::m_bDormant << std::endl;
	std::cout << "m_aimPunchAngle: " << std::hex << std::uppercase << Offsets::Netvars::m_aimPunchAngle << std::endl;
	std::cout << "m_ArmorValue: " << std::hex << std::uppercase << Offsets::Netvars::m_ArmorValue << std::endl;
	std::cout << "m_bHasDefuser: " << std::hex << std::uppercase << Offsets::Netvars::m_bHasDefuser << std::endl;
	std::cout << "m_bSpotted: " << std::hex << std::uppercase << Offsets::Netvars::m_bSpotted << std::endl;
	std::cout << "m_bSpottedByMask: " << std::hex << std::uppercase << Offsets::Netvars::m_bSpottedByMask << std::endl;
	std::cout << "m_clrRender: " << std::hex << std::uppercase << Offsets::Netvars::m_clrRender << std::endl;
	std::cout << "m_dwBoneMatrix: " << std::hex << std::uppercase << Offsets::Netvars::m_dwBoneMatrix << std::endl;
	std::cout << "m_fFlags: " << std::hex << std::uppercase << Offsets::Netvars::m_fFlags << std::endl;
	std::cout << "m_flFallbackWear: " << std::hex << std::uppercase << Offsets::Netvars::m_flFallbackWear << std::endl;
	std::cout << "m_flFlashMaxAlpha: " << std::hex << std::uppercase << Offsets::Netvars::m_flFlashMaxAlpha << std::endl;
	std::cout << "m_hActiveWeapon: " << std::hex << std::uppercase << Offsets::Netvars::m_hActiveWeapon << std::endl;
	std::cout << "m_hMyWeapons: " << std::hex << std::uppercase << Offsets::Netvars::m_hMyWeapons << std::endl;
	std::cout << "m_iCrosshairId: " << std::hex << std::uppercase << Offsets::Netvars::m_iCrosshairId << std::endl;
	std::cout << "m_iEntityQuality: " << std::hex << std::uppercase << Offsets::Netvars::m_iEntityQuality << std::endl;
	std::cout << "m_iFOV: " << std::hex << std::uppercase << Offsets::Netvars::m_iFOV << std::endl;
	std::cout << "m_iFOVStart: " << std::hex << std::uppercase << Offsets::Netvars::m_iFOVStart << std::endl;
	std::cout << "m_iGlowIndex: " << std::hex << std::uppercase << Offsets::Netvars::m_iGlowIndex << std::endl;
	std::cout << "m_iHealth: " << std::hex << std::uppercase << Offsets::Netvars::m_iHealth << std::endl;
	std::cout << "m_iItemDefinitionIndex: " << std::hex << std::uppercase << Offsets::Netvars::m_iItemDefinitionIndex << std::endl;
	std::cout << "m_iItemIDHigh: " << std::hex << std::uppercase << Offsets::Netvars::m_iItemIDHigh << std::endl;
	std::cout << "m_iTeamNum: " << std::hex << std::uppercase << Offsets::Netvars::m_iTeamNum << std::endl;
	std::cout << "m_nFallbackPaintKit: " << std::hex << std::uppercase << Offsets::Netvars::m_nFallbackPaintKit << std::endl;
	std::cout << "m_nFallbackSeed: " << std::hex << std::uppercase << Offsets::Netvars::m_nFallbackSeed << std::endl;
	std::cout << "m_vecOrigin: " << std::hex << std::uppercase << Offsets::Netvars::m_vecOrigin << std::endl;
	std::cout << "m_rank: " << std::hex << std::uppercase << Offsets::Netvars::m_rank << std::endl;
	std::cout << "m_flDetectedByEnemySensorTime: " << std::hex << std::uppercase << Offsets::Netvars::m_flDetectedByEnemySensorTime << std::endl;
	std::cout << "m_iAccount: " << std::hex << std::uppercase << Offsets::Netvars::m_iAccount << std::endl;
	std::cout << "m_hViewModel: " << std::hex << std::uppercase << Offsets::Netvars::m_hViewModel<< std::endl;
	std::cout << "m_vecMins: " << std::hex << std::uppercase << Offsets::Netvars::m_vecMins << std::endl;
	std::cout << "m_vecMaxs: " << std::hex << std::uppercase << Offsets::Netvars::m_vecMaxs << std::endl;
	std::cout << "m_Collision: " << std::hex << std::uppercase << Offsets::Netvars::m_Collision << std::endl;
	std::cout << "m_rgflCoordinateFrame: " << std::hex << std::uppercase << Offsets::Netvars::m_rgflCoordinateFrame << std::endl;

#endif


}