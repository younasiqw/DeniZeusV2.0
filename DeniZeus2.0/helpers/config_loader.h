#pragma once
#include <filesystem>
#include <fstream> 
#include <iostream>
#include "utilites.h"
#include "../managers/config_manager.h"
#include "../helpers/json.h"

using json = nlohmann::json;

inline void load_Configs() {
	if (std::filesystem::exists("config.dcf")) {
		std::ifstream cfile("config.dcf");
		try
		{
		json loadconfig = json::parse(cfile);

		//Glow
		config::glow::glow_enabled = loadconfig["glow"]["glow_enabled"].get<bool>();
		config::glow::glow_static = loadconfig["glow"]["glow_static"].get<bool>();
		config::glow::glow_ally = loadconfig["glow"]["glow_ally"].get<bool>();
		config::glow::glow_enemy = loadconfig["glow"]["glow_enemy"].get<bool>();
		config::glow::glow_static = loadconfig["glow"]["glow_static"].get<bool>();
		config::glow::glow_dynamic_alpha = loadconfig["glow"]["glow_dynamic_alpha"].get<float>();

		//Aimbot
		config::aimbot::aimbot_bone = loadconfig["aimbot"]["aimbot_bone"].get<int>();
		config::aimbot::aimbot_key = loadconfig["aimbot"]["aimbot_key"].get<int>();
		config::aimbot::aimbot_type = loadconfig["aimbot"]["aimbot_type"].get<int>();
		config::aimbot::aimbot_enabled = loadconfig["aimbot"]["aimbot_enabled"].get<bool>();
		config::aimbot::aimbot_friendly_fire = loadconfig["aimbot"]["aimbot_friendly_fire"].get<bool>();
		config::aimbot::aimbot_when_jump = loadconfig["aimbot"]["aimbot_when_jump"].get<bool>();
		config::aimbot::aimbot_smoothness = loadconfig["aimbot"]["aimbot_smoothness"].get<float>();
		config::aimbot::aimbot_fov = loadconfig["aimbot"]["aimbot_fov"].get<float>();
		config::aimbot::recoil_percent = loadconfig["aimbot"]["recoil_percent"].get<float>();

		//ESP
		config::esp::esp_enabled = loadconfig["esp"]["esp_enabled"].get<bool>();
		config::esp::esp_name_and_rank = loadconfig["esp"]["esp_name_and_rank"].get<bool>();
		config::esp::esp_health = loadconfig["esp"]["esp_health"].get<bool>();
		config::esp::esp_armor = loadconfig["esp"]["esp_armor"].get<bool>();
		config::esp::esp_ally = loadconfig["esp"]["esp_ally"].get<bool>();
		config::esp::esp_enemy = loadconfig["esp"]["esp_enemy"].get<bool>();
		config::esp::esp_box_color.r = loadconfig["esp"]["esp_box_color"]["r"].get<int>();
		config::esp::esp_box_color.g = loadconfig["esp"]["esp_box_color"]["g"].get<int>();
		config::esp::esp_box_color.b = loadconfig["esp"]["esp_box_color"]["b"].get<int>();
		config::esp::esp_health_color.r = loadconfig["esp"]["esp_health_color"]["r"].get<int>();
		config::esp::esp_health_color.g = loadconfig["esp"]["esp_health_color"]["g"].get<int>();
		config::esp::esp_health_color.b = loadconfig["esp"]["esp_health_color"]["b"].get<int>();
		config::esp::esp_armor_color.r = loadconfig["esp"]["esp_armor_color"]["r"].get<int>();
		config::esp::esp_armor_color.g = loadconfig["esp"]["esp_armor_color"]["g"].get<int>();
		config::esp::esp_armor_color.b = loadconfig["esp"]["esp_armor_color"]["b"].get<int>();

		//Bhop
		config::bhop::bhop_enabled = loadconfig["bhop"]["bhop_enabled"].get<bool>();
		config::bhop::bhop_humanization = loadconfig["bhop"]["bhop_humanization"].get<bool>();
		config::bhop::bhop_hit_chance = loadconfig["bhop"]["bhop_hit_chance"].get<float>();

		//Chams
		config::chams::chams_enabled = loadconfig["chams"]["chams_enabled"].get<bool>();
		config::chams::chams_ally = loadconfig["chams"]["chams_ally"].get<bool>();
		config::chams::chams_enemy = loadconfig["chams"]["chams_enemy"].get<bool>();
		config::chams::chams_ally_color.r = loadconfig["chams"]["chams_ally_color"]["r"].get<int>();
		config::chams::chams_ally_color.g = loadconfig["chams"]["chams_ally_color"]["g"].get<int>();
		config::chams::chams_ally_color.b = loadconfig["chams"]["chams_ally_color"]["b"].get<int>();
		config::chams::chams_enemy_color.r = loadconfig["chams"]["chams_enemy_color"]["r"].get<int>();
		config::chams::chams_enemy_color.g = loadconfig["chams"]["chams_enemy_color"]["g"].get<int>();
		config::chams::chams_enemy_color.b = loadconfig["chams"]["chams_enemy_color"]["b"].get<int>();
		config::chams::chams_brightness = loadconfig["chams"]["chams_brightness"].get<float>();

		//Night mode
		config::night_mode::night_mode_enabled = loadconfig["night_mode"]["night_mode_enabled"].get<bool>();
		config::night_mode::night_mode_tone = loadconfig["night_mode"]["night_mode_tone"].get<float>();

		//Flash reducer
		config::flash_reducer::flash_reducer_enabled = loadconfig["flash_reducer"]["flash_reducer_enabled"].get<bool>();
		config::flash_reducer::flash_reducer_percent = loadconfig["flash_reducer"]["flash_reducer_percent"].get<float>();

		}
		catch (const std::exception&)
		{
			std::cout << "Error occurred on loading config!" << std::endl;
		}
		
	}
	else {
		std::cout << "Config file not found!" << std::endl;
	}
}