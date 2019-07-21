#pragma once
#include "../helpers/utilites.h"
#include "../managers/entity_manager.h"
#include "../managers/config_manager.h"
#include "../managers/badresses_manager.h"

inline void loop_FlashReducer() {
	while (true) {
		if(player::local.base != 0)
		if (player::local.health > 0) {
			if (csgo.ReadMemory<float>(player::local.base + Offsets::Netvars::m_flFlashMaxAlpha) > 0.f) {
				csgo.WriteMemory(player::local.base + Offsets::Netvars::m_flFlashMaxAlpha, 255.f * (abs(config::flash_reducer::flash_reducer_percent - 100.f) / 100.f));
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}