#define NOMINMAX
#include <Windows.h>

#include "valve_sdk/sdk.hpp"
#include "helpers/utils.hpp"

#include "hooks.hpp"

#include "players.hpp"

LPVOID basic;

extern "C" __declspec(dllexport) bool isVisible(int i) {
	
	return is_visible[i];
}

extern "C" __declspec(dllexport) int VisiblePayload() {
	return isVisible(0) ? 100 : 50;
}

extern "C" __declspec(dllexport) void Unload() {
	FreeLibraryAndExitThread(static_cast<HMODULE>(basic), 1);
}

DWORD WINAPI OnDllAttach(LPVOID base)
{
	basic = base;

    if(Utils::WaitForModules(10000, { L"client_panorama.dll", L"engine.dll"}) == WAIT_TIMEOUT) {
        // One or more modules were not loaded in time
        return FALSE;
    }

    try {
        Interfaces::Initialize();

        NetvarSys::Get().Initialize();

        Hooks::Initialize();

    } catch(const std::exception) {

        FreeLibraryAndExitThread(static_cast<HMODULE>(base), 1);

    }

    return TRUE;
}

BOOL WINAPI OnDllDetach()
{
    Hooks::Shutdown();
    return TRUE;
}

BOOL WINAPI DllMain(
    _In_      HINSTANCE hinstDll,
    _In_      DWORD     fdwReason,
    _In_opt_  LPVOID    lpvReserved
)
{
    switch(fdwReason) {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(hinstDll);
            CreateThread(nullptr, 0, OnDllAttach, hinstDll, 0, nullptr);
            return TRUE;
        case DLL_PROCESS_DETACH:
            if(lpvReserved == nullptr)
                return OnDllDetach();
            return TRUE;
        default:
            return TRUE;
    }
}
