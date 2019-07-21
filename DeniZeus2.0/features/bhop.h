#pragma once
#include <random>
#include <iostream>
#include "../helpers/utilites.h"
#include "../managers/entity_manager.h"
#include "../managers/config_manager.h"
#include "../managers/badresses_manager.h"

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<float> random(0.f, 100.f);

int hit_count = 0;
int reset_count = 0;

void inline loop_normal() {
	csgo.WriteMemory(Offsets::Signatures::dwForceJump, 6);
}

void inline loop_humanized() {
	//std::cout << std::to_string(abs(hit_count * (int)((100.f - config::bhop::bhop_hit_chance) / 5.f))) << std::endl;
	float randomized_bhop = random(gen);
	if (randomized_bhop > config::bhop::bhop_hit_chance) {
		hit_count++;
	}
	csgo.WriteMemory(Offsets::Signatures::dwForceJump, 6);

	
	
}

inline void loop_Bhop() {
	while (1) {
		if ((Bases::State == 6)) {
			player::local.is_jumping = !(csgo.ReadMemory<int>(Bases::dwLocalPlayer + Offsets::Netvars::m_fFlags) & PLAYER_ON_FLOOR);
			if (key_pressed(VK_SPACE)) {
				if (!player::local.is_jumping) {

					if (config::bhop::bhop_humanization)
					{
						loop_humanized();
					}
					else
					{
						loop_normal();
					}
				}
			}
			else {
				hit_count = 1;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(config::bhop::bhop_humanization ? abs(hit_count * (int)((100.f - config::bhop::bhop_hit_chance)/5.f)) : 5));
	}
}