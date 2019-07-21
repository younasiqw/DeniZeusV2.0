#pragma once
#include "../helpers/utilites.h"
#include "../managers/entity_manager.h"
#include "../managers/config_manager.h"
#include "../managers/badresses_manager.h"

struct Color_t {
	BYTE r, g, b;
};
bool init_ally;
bool init_enemy;

inline void loop_Chams() {
	while (1)
	{
		for (int i = 0; i < Bases::GlobalVar.maxClients; i++)
			{
				if (!player::other[i].base)
					continue;
				
				if (!(player::local.health > 0))
					continue;

				if (player::other[i].is_dormant)
					continue;

				if (player::other[i].team_id != player::local.team_id) {
					if (config::chams::chams_enemy) {
						static Color_t enemy_color; 
						if (!init_enemy) {
							enemy_color.r = config::chams::chams_enemy_color.r; enemy_color.g = config::chams::chams_enemy_color.g; enemy_color.b = config::chams::chams_enemy_color.b; 
							init_enemy = true;
						}
						csgo.WriteMemory(player::other[i].base + Offsets::Netvars::m_clrRender, enemy_color);
						player::other[i].is_chammed = true;
					}
					else if(player::other[i].is_chammed) {
						static BYTE rgb[3]; rgb[0] = rgb[1] = rgb[2] = 255;
						csgo.WriteMemory(player::other[i].base + Offsets::Netvars::m_clrRender, rgb);
						player::other[i].is_chammed = false;
					}
				}
				else {
					if (config::chams::chams_ally) {
						static Color_t ally_color; 
						if (!init_ally) {
							ally_color.r = config::chams::chams_ally_color.r; ally_color.g = config::chams::chams_ally_color.g; ally_color.b = config::chams::chams_ally_color.b; 
							init_ally = true;
						}
						csgo.WriteMemory(player::other[i].base + Offsets::Netvars::m_clrRender, ally_color);
						player::other[i].is_chammed = true;
					}
					else if (player::other[i].is_chammed) {
						static BYTE rgb[3]; rgb[0] = rgb[1] = rgb[2] = (BYTE)255;
						csgo.WriteMemory(player::other[i].base + Offsets::Netvars::m_clrRender, rgb);
						player::other[i].is_chammed = false;
					}
				}
			}
	}

	if (player::local.health > 0) {
		DWORD viewModelHandler = csgo.ReadMemory<DWORD>(player::local.base + Offsets::Netvars::m_hViewModel);
		DWORD viewModel = csgo.ReadMemory<DWORD>(Offsets::Signatures::dwEntityList + (((viewModelHandler & 0xFFF) - 1) * 16));
		Color_t arms_color; arms_color.r = arms_color.g = arms_color.b = (BYTE)(255.f / ((config::chams::chams_brightness - 0.8f) / 2.f));
		csgo.WriteMemory(viewModel + Offsets::Netvars::m_clrRender, arms_color);
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(200));
}