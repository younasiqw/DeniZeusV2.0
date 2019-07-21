#pragma once

#define NOMINMAX
#include <Windows.h>

#include "Misc/Enums.hpp"
#include "Misc/vfunc.hpp"

#include "Math/VMatrix.hpp"
#include "Math/QAngle.hpp"
#include "Math/Vector.hpp"
#include "Misc/Studio.hpp"

#include "Interfaces/IAppSystem.hpp"
#include "Interfaces/IBaseClientDll.hpp"
#include "Interfaces/IClientEntity.hpp"
#include "Interfaces/IClientEntityList.hpp"
#include "Interfaces/IEngineTrace.hpp"
#include "Interfaces/IVEngineClient.hpp"
#include "Interfaces/IVModelInfoClient.hpp"
#include "Interfaces/IPrediction.hpp"
#include "Interfaces/CClientState.hpp"
#include "Misc/datamap.hpp"

#include "netvars.hpp"

struct IDirect3DDevice9;

namespace Interfaces
{
    void Initialize();
}

inline IVEngineClient*       g_EngineClient;
inline IBaseClientDLL*       g_CHLClient;
inline IClientEntityList*    g_EntityList;
inline CGlobalVarsBase*      g_GlobalVars;
inline IEngineTrace*         g_EngineTrace;
inline CClientState*         g_ClientState;
inline IVModelInfoClient*    g_MdlInfo;
inline DWORD*				 dwEntityList;
template<typename... Args>
void ConMsg(const char* pMsg, Args... args)
{
    static auto import = (void(*)(const char*, ...))GetProcAddress(GetModuleHandleW(L"tier0.dll"), "?ConMsg@@YAXPBDZZ");
    return import(pMsg, args...);
}

#include "Misc/EHandle.hpp"

class C_LocalPlayer
{
    friend bool operator==(const C_LocalPlayer& lhs, void* rhs);
public:
    C_LocalPlayer() : m_local(nullptr) {}

    operator bool() const { return *m_local != nullptr; }
    operator C_BasePlayer*() const { return *m_local; }

    C_BasePlayer* operator->() { return *m_local; }

private:
    C_BasePlayer** m_local;
};

inline C_LocalPlayer g_LocalPlayer;

