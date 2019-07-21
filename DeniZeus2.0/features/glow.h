#pragma once
#include "../helpers/utilites.h"
#include "../helpers/netvar_scanner.h"
#include "../managers/entity_manager.h"
#include "../managers/config_manager.h"
#include "../managers/badresses_manager.h"

inline void loop_Glow() {
	while (1) {
		if ((config::glow::glow_ally || config::glow::glow_enemy) && (Bases::State == 6)) {
			for (int i = 1; i <= Bases::GlobalVar.maxClients; i++)
			{
				if (!player::other[i].base)
					continue;

				if (player::other[i].is_dormant)
					continue;

				if((player::other[i].team_id != player::local.team_id) ? config::glow::glow_enemy : config::glow::glow_ally) {
					if (player::other[i].health != 0 && !player::other[i].is_dormant && player::other[i].base != 0 && player::other[i].base != Bases::dwLocalPlayer) {
						if (!config::glow::glow_static) {
							DWORD entityadr = Bases::dwGlowObjectManager + ((player::other[i].glow_index) * 0x38) + 0x4;
							sGlow entity = csgo.ReadMemory<sGlow>(entityadr);
							entity.r = 1.f - (float)(player::other[i].health / 100.f);
							entity.g = (float)(player::other[i].health / 100.f);
							entity.b = 0.f;
							entity.a = config::glow::glow_dynamic_alpha;
							entity.m_bRenderWhenOccluded = true;
							csgo.WriteMemory<sGlow>(entityadr, entity);
						}
						else 
						{
							csgo.WriteMemory(player::other[i].base + Offsets::Netvars::m_flDetectedByEnemySensorTime, Bases::GlobalVar.curtime + 7.f);
						}
					}
				}
			}
		}
		else {
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(config::glow::glow_static ? 500 : 10));
	}
}