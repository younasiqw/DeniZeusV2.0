#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <future>
#include "helpers/utilites.h"
#include "helpers/config_loader.h"
#include "helpers/netvar_scanner.h"
#include "managers/memory_manager.h"
#include "managers/offset_manager.h"
#include "managers/config_manager.h"
#include "managers/entity_manager.h"

#include "features/esp.h"
#include "features/glow.h"
#include "features/bhop.h"
#include "features/chams.h"
#include "features/aimbot.h"
#include "features/flash_reducer.h"

#include "overlay/main.h"


int main()
{

#ifdef SPEED_TEST_VISIBLE
	while (true)
	{
		clock_t start, end;
		start = clock();
		for (size_t i = 0; i < 1000; i++)
		{
			csgo.IsVisible(i);
		}
		end = clock();
		std::cout << "Time required for execution: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds." << "\n\n";
	}
#endif

	Dump_Offsets();

	load_Configs();

	auto tUB = std::async(std::launch::async, update_Base);
	auto tUP = std::async(std::launch::async, update_Players);

	std::future<int> tO;
	if(config::esp::esp_enabled)
		tO = std::async(std::launch::async, OverlayCreate);
	std::future<void> tG;
	if (config::glow::glow_enabled)
		tG = std::async(std::launch::async, loop_Glow);
	std::future<void> tC;
	if (config::chams::chams_enabled)
		tC = std::async(std::launch::async, loop_Chams);
	std::future<void> tA;
	if (config::aimbot::aimbot_enabled)
		tA = std::async(std::launch::async, loop_Aimbot);
	std::future<void> tB;
	if (config::bhop::bhop_enabled)
		tB = std::async(std::launch::async, loop_Bhop);
	std::future<void> tE;
	if (config::esp::esp_enabled)
		tE = std::async(std::launch::async, loop_ESP);
	std::future<void> tFR;
	if (config::flash_reducer::flash_reducer_enabled)
		tFR = std::async(std::launch::async, loop_FlashReducer);

	tUB.get(), tUP.get(), tG.get(), tA.get(), tB.get(), tC.get(), tE.get(), tO.get(), tFR.get();

	system("pause");
}
