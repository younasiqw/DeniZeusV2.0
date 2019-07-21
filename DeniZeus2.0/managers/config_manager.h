#pragma once
#include "../helpers/utilites.h"

namespace config {
	namespace aimbot {
		int aimbot_bone = 7;
		int aimbot_key = 5;
		int aimbot_type = AimbotType::AIM_KEYPRESS_OR_FIRE;
		bool aimbot_enabled = true;
		bool aimbot_friendly_fire = false;
		bool aimbot_when_jump = false;
		float aimbot_smoothness = 50.f;
		float aimbot_fov = 30.f;
		float recoil_percent = 100.f;
	}
	
	namespace glow {
		bool glow_enabled = true;
		bool glow_enemy = true;
		bool glow_ally = false;
		bool glow_static = false;
		float glow_dynamic_alpha = 0.7f;
	}

	namespace bhop {
		bool bhop_enabled = true;
		bool bhop_humanization = true;
		float bhop_hit_chance = 20.f;
	}

	namespace chams {
		bool chams_enabled = true;
		bool chams_ally = false;
		bool chams_enemy = true;
		Color chams_ally_color(0, 255, 0);
		Color chams_enemy_color(255,0, 0);
		float chams_brightness = 10.f;
	}

	namespace night_mode {
		bool night_mode_enabled = true;
		float night_mode_tone = 0.2f;
	}

	namespace flash_reducer {
		bool flash_reducer_enabled = true;
		float flash_reducer_percent = 50.f;
	}

	namespace esp {
		bool esp_enabled = true;
		bool esp_name_and_rank = true;
		bool esp_health = true;
		bool esp_armor = true;
		bool esp_ally = false;
		bool esp_enemy = true;
		Color    esp_box_color(255, 0, 0);
		Color esp_health_color(0, 255, 0);
		Color  esp_armor_color(0, 0, 255);
	}

}