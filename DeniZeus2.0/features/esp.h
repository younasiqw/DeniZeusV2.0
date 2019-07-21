#pragma once
#include "../helpers/utilites.h"
#include "../helpers/netvar_scanner.h"
#include "../helpers/esp_helpers.h"
#include "../managers/badresses_manager.h"
#include "../managers/entity_manager.h"
#include "../managers/config_manager.h"

static bool screen_transform(const Vector& in, Vector& out)
{
		VMatrix w2sMatrix = csgo.ReadMemory<VMatrix>(Offsets::Signatures::dwViewMatrix);
		out.x = w2sMatrix.m[0][0] * in.x + w2sMatrix.m[0][1] * in.y + w2sMatrix.m[0][2] * in.z + w2sMatrix.m[0][3];
		out.y = w2sMatrix.m[1][0] * in.x + w2sMatrix.m[1][1] * in.y + w2sMatrix.m[1][2] * in.z + w2sMatrix.m[1][3];
		out.z = 0.0f;

		float w = w2sMatrix.m[3][0] * in.x + w2sMatrix.m[3][1] * in.y + w2sMatrix.m[3][2] * in.z + w2sMatrix.m[3][3];

		if (w < 0.001f) {
			out.x *= 100000;
			out.y *= 100000;
			return false;
		}

		out.x /= w;
		out.y /= w;

		return true;
}

void VectorTransform(const Vector& in1, const matrix3x4_t& in2, Vector& out)
{
	out[0] = in1.Dot(in2[0]) + in2[0][3];
	out[1] = in1.Dot(in2[1]) + in2[1][3];
	out[2] = in1.Dot(in2[2]) + in2[2][3];
}

inline bool WorldToScreen(const Vector& in, Vector& out)
{
	if (screen_transform(in, out)) {
		out.x = (screen_width / 2.0f) + (out.x * screen_width) / 2.0f;
		out.y = (screen_height / 2.0f) - (out.y * screen_height) / 2.0f;
		return true;
	}
	return false;
}

RECT CalcBox(sPlayer ent)
{
	RECT rect{};

	matrix3x4_t trans = csgo.ReadMemory<matrix3x4_t>(ent.base + Offsets::Netvars::m_rgflCoordinateFrame);

	Vector min = csgo.ReadMemory<Vector>(ent.base + Offsets::Netvars::m_Collision + Offsets::Netvars::m_vecMins);
	Vector max = csgo.ReadMemory<Vector>(ent.base + Offsets::Netvars::m_Collision + Offsets::Netvars::m_vecMaxs);

	Vector points[] = {
		Vector(min.x, min.y, min.z),
		Vector(min.x, max.y, min.z),
		Vector(max.x, max.y, min.z),
		Vector(max.x, min.y, min.z),
		Vector(max.x, max.y, max.z),
		Vector(min.x, max.y, max.z),
		Vector(min.x, min.y, max.z),
		Vector(max.x, min.y, max.z)
	};

	Vector pointsTransformed[8];
	for (int i = 0; i < 8; i++) {
		VectorTransform(points[i], trans, pointsTransformed[i]);
	}

	Vector screen_points[8] = {};

	for (int i = 0; i < 8; i++) {
		if (!WorldToScreen(pointsTransformed[i], screen_points[i]))
			return rect;
	}

	auto left = screen_points[0].x;
	auto top = screen_points[0].y;
	auto right = screen_points[0].x;
	auto bottom = screen_points[0].y;

	for (int i = 1; i < 8; i++) {
		if (left > screen_points[i].x)
			left = screen_points[i].x;
		if (top < screen_points[i].y)
			top = screen_points[i].y;
		if (right < screen_points[i].x)
			right = screen_points[i].x;
		if (bottom > screen_points[i].y)
			bottom = screen_points[i].y;
	}
	return RECT{ (long)left, (long)top, (long)right, (long)bottom };
}

const char* CompRanks[19] =
{
		"U",
		"S 1",
		"S 2",
		"S 3",
		"S 4",
		"S E",
		"S E M",
		"G N 1",
		"G N 2",
		"G N 3",
		"G N M",
		"M G 1",
		"M G 2",
		"M G E",
		"D M G",
		"L E",
		"L E M",
		"S M F C",
		"G E"
};


inline void loop_ESP() {
	while (1)
	{
		esp_boxes.resize(Bases::GlobalVar.maxClients + 1);
		esp_names.resize(Bases::GlobalVar.maxClients + 1);
		esp_health.resize(Bases::GlobalVar.maxClients + 1);
		esp_armor.resize(Bases::GlobalVar.maxClients + 1);
		if (Bases::State == 6) {
			for (int i = 1; i <= Bases::GlobalVar.maxClients; i++)
			{
				if (!player::other[i].base && player::other[i].base == player::local.base) {
					esp_boxes.at(i).enabled = false;
					continue;
				}

				if (player::other[i].is_dormant) {
					esp_boxes.at(i).enabled = false;
					continue;
				}

				if (player::other[i].health <= 0) {
					esp_boxes.at(i).enabled = false;
					continue;
				}

				if (player::other[i].team_id == player::local.team_id) {
					if (!config::esp::esp_ally) {
						esp_boxes.at(i).enabled = false;
						continue;
					}
				}
				else {
					if (!config::esp::esp_enemy) {
						esp_boxes.at(i).enabled = false;
						continue;
					}
				}

				ESP_Box    box;
				ESP_Name   name;
				ESP_Health health;
				ESP_Health armor;

				box.origin = CalcBox(player::other[i]);
				box.clr = config::esp::esp_box_color;
				box.enabled = true;

				if (config::esp::esp_name_and_rank)
					if (box.origin.left != 0 || box.origin.bottom != 0) {
						name.coor.x = (float)box.origin.left;
						name.coor.y = (float)box.origin.bottom;
						name.name = (std::string(player::other[i].get_player_info().szName) + " | " + std::string(CompRanks[player::other[i].rank]));
						name.enabled = true;
					}

				if (config::esp::esp_health)
					if (box.origin.left != 0 || box.origin.bottom != 0) {
						health.coor.x = (float)box.origin.left - (((float)box.origin.right - (float)box.origin.left) > 1000.f ? 1000.f : ((float)box.origin.right - (float)box.origin.left)) / 5.f;
						health.coor.y = (float)box.origin.bottom;
						health.size.x = (((float)box.origin.right - (float)box.origin.left) > 1000.f ? 1000.f : ((float)box.origin.right - (float)box.origin.left)) / 10.f;
						health.size.y = (float)box.origin.top - (float)box.origin.bottom;
						health.health = player::other[i].health;
						health.clr = config::esp::esp_health_color;
						health.enabled = true;
					}

				if (config::esp::esp_armor)
					if (box.origin.left != 0 || box.origin.bottom != 0) {
						armor.coor.x = (float)box.origin.right + (((float)box.origin.right - (float)box.origin.left) > 1000.f ? 1000.f : ((float)box.origin.right - (float)box.origin.left)) / 8.f;
						armor.coor.y = (float)box.origin.bottom;
						armor.size.x = (((float)box.origin.right - (float)box.origin.left) > 1000.f ? 1000.f : ((float)box.origin.right - (float)box.origin.left)) / 10.f;
						armor.size.y = (float)box.origin.top - (float)box.origin.bottom;
						armor.health = player::other[i].armor;
						armor.clr = config::esp::esp_armor_color;
						armor.enabled = true;
					}


				esp_boxes.at(i) = box;
				esp_names.at(i) = name;
				esp_health.at(i) = health;
				esp_armor.at(i) = armor;

			}
		} else {
			esp_boxes.clear();
			esp_names.clear();
			esp_health.clear();
			esp_armor.clear();
		}
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}