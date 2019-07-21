#pragma once
#include "../helpers/utilites.h"
#include "../helpers/netvar_scanner.h"
#include "../managers/entity_manager.h"
#include "../managers/config_manager.h"
#include "../managers/badresses_manager.h"

QAngle old_recoil(0.f, 0.f, 0.f);

inline void loop_Aimbot() {
	while (1) {
		

		if ((Bases::State == 6) && (config::aimbot::aimbot_type == AimbotType::AIM_ALWAYS ? true : config::aimbot::aimbot_type == AimbotType::AIM_FIRE ? key_pressed(VK_LBUTTON) : config::aimbot::aimbot_type == AimbotType::AIM_KEYPRESSED ? key_pressed(config::aimbot::aimbot_key) : (key_pressed(config::aimbot::aimbot_key) || key_pressed(VK_LBUTTON)))) {

			QAngle recoil = csgo.ReadMemory<QAngle>(Bases::dwLocalPlayer + Offsets::Netvars::m_aimPunchAngle);
			recoil *= (config::aimbot::recoil_percent / 90.f) * 2.f;

			sPlayer closest;
			float distance = config::aimbot::aimbot_fov;

			player::local.view_angle = csgo.ReadMemory<QAngle>(Bases::dwClientState + Offsets::Signatures::ClientState::ViewAngles);

			for (int i = 1; i <= Bases::GlobalVar.maxClients; i++)
			{
				if (!player::other[i].base)
					continue;

				if (player::other[i].is_dormant)
					continue;

				if (player::other[i].health > 0 && player::other[i].is_spotted && (config::aimbot::aimbot_friendly_fire ? true : player::other[i].team_id != player::local.team_id) && (config::aimbot::aimbot_when_jump ? true : !player::other[i].is_jumping)) {
					Vector bonevec = player::other[i].get_bone(config::aimbot::aimbot_bone);

					float pdist = GetFOV(player::local.view_angle, CalcAngle(player::local.origin, bonevec));

					if (pdist < distance) {
						distance = pdist;
						player::other[i].bone_origin = bonevec;
						closest = player::other[i];
					}
				}
			}
			
			if (closest.base != 0) {
				QAngle AimAngle = CalcAngle(player::local.origin, closest.bone_origin);
				AimAngle = Smooth(config::aimbot::aimbot_smoothness, player::local.view_angle, AimAngle - recoil);
				Normalize3(AimAngle);
				ClampAngles(AimAngle);
				csgo.WriteMemory<QAngle>(Bases::dwClientState + Offsets::Signatures::ClientState::ViewAngles, AimAngle);
			}

			

		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}