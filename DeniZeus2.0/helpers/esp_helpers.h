#pragma once
#include "../helpers/utilites.h"
#include <vector>

struct ESP_Box {
	bool enabled;
	RECT origin;
	Color clr;
};

struct ESP_Health {
	bool enabled;
	Vector coor;
	Vector size;
	int health;
	Color clr;
};

struct ESP_Name {
	bool enabled;
	Vector coor;
	std::string name;
};

inline float screen_width;
inline float screen_height;

inline std::vector<ESP_Box> esp_boxes;
inline std::vector<ESP_Name> esp_names;
inline std::vector<ESP_Health> esp_health;
inline std::vector<ESP_Health> esp_armor;