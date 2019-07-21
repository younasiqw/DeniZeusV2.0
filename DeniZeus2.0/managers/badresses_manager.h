#pragma once
#include "../helpers/utilites.h"
#include "../helpers/esp_helpers.h"
#include "../managers/offset_manager.h"
#include "../managers/memory_manager.h"



namespace Bases {
	int State;
	DWORD dwClientState;
	DWORD dwGlowObjectManager;
	DWORD dwLocalPlayer;
	DWORD flSensorTimerColor;
	DWORD PlayerInfoBase;
	CGlobalVarsBase GlobalVar;
}

inline void start_Chams() {
	DWORD thisPtr = (int)(Offsets::Signatures::model_ambient_min - 0x2c);
	DWORD xored = *(DWORD*)& config::chams::chams_brightness ^ thisPtr;
	csgo.WriteMemory(Offsets::Signatures::model_ambient_min, xored);
}

inline void loop_Night_Mode() {
	DWORD thisPtr = (int)(Offsets::Signatures::mat_force_tonemap_scale);
	DWORD xored = *(DWORD*)& config::night_mode::night_mode_tone ^ thisPtr;
	csgo.WriteMemory(Offsets::Signatures::mat_force_tonemap_scale + 0x2C, xored);
} 

inline void night_mode_fix() {
	float zero = 0.f;
	DWORD thisPtr = (int)(Offsets::Signatures::mat_force_tonemap_scale);
	DWORD xored = *(DWORD*)& zero ^ thisPtr;
	csgo.WriteMemory(Offsets::Signatures::mat_force_tonemap_scale + 0x2C, xored);
}

inline void update_Base() {
	while (true) {
		Bases::GlobalVar = csgo.ReadMemory<CGlobalVarsBase>(Offsets::Signatures::dwGlobalVars);
		Bases::dwClientState = csgo.ReadMemory<DWORD>(Offsets::Signatures::dwClientState);
		Bases::dwGlowObjectManager = csgo.ReadMemory<DWORD>(Offsets::Signatures::dwGlowObjectManager);
		Bases::dwLocalPlayer = csgo.ReadMemory<DWORD>(Offsets::Signatures::dwLocalPlayer);
		Bases::State = csgo.ReadMemory<bool>(Bases::dwClientState + Offsets::Signatures::ClientState::State);
		Bases::PlayerInfoBase = csgo.ReadMemory<DWORD>(Bases::dwClientState + Offsets::Signatures::ClientState::PlayerInfo);
		if (config::chams::chams_enabled)
			start_Chams();

		if (config::night_mode::night_mode_enabled && Bases::State == 6)
			loop_Night_Mode();
		else
			night_mode_fix();

		screen_width = csgo.ReadMemory<int>(Offsets::Signatures::dwScreenSize);
		screen_height = csgo.ReadMemory<int>(Offsets::Signatures::dwScreenSize + 4);


		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
}