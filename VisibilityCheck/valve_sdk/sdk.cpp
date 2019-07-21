#include "sdk.hpp"

#include "../Helpers/Utils.hpp"

namespace Interfaces
{
    CreateInterfaceFn get_module_factory(HMODULE module)
    {
        return reinterpret_cast<CreateInterfaceFn>(GetProcAddress(module, "CreateInterface"));
    }

    template<typename T>
    T* get_interface(CreateInterfaceFn f, const char* szInterfaceVersion)
    {
        auto result = reinterpret_cast<T*>(f(szInterfaceVersion, nullptr));

        if(!result) {
            throw std::runtime_error(std::string("[get_interface] Failed to GetOffset interface: ") + szInterfaceVersion);
        }

        return result;
    }

    void Initialize()
    {
        auto engine			  = GetModuleHandleW(L"engine.dll");
        auto client			  = GetModuleHandleW(L"client_panorama.dll");
        auto engineFactory    = get_module_factory(engine);
        auto clientFactory    = get_module_factory(client);
        
        g_CHLClient           = get_interface  <IBaseClientDLL>      (clientFactory   , "VClient018");
        g_EntityList          = get_interface  <IClientEntityList>   (clientFactory   , "VClientEntityList003");
        g_EngineClient        = get_interface  <IVEngineClient>      (engineFactory   , "VEngineClient014");
        g_EngineTrace         = get_interface  <IEngineTrace>        (engineFactory   , "EngineTraceClient004");
		g_MdlInfo			  = get_interface  <IVModelInfoClient>   (engineFactory   , "VModelInfoClient004");

		
		
		g_GlobalVars	  =   **(CGlobalVarsBase * **)((*(DWORD * *)g_CHLClient)[0] + 0x1B);
		g_ClientState     =   **(CClientState***)(Utils::PatternScan(engine, "A1 ? ? ? ? 8B 80 ? ? ? ? C3") + 1);
		g_LocalPlayer	  =    *(C_LocalPlayer*)(Utils::PatternScan(client, "8B 0D ? ? ? ? 83 FF FF 74 07") + 2);
    }
}
