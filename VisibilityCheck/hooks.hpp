#pragma once

#include "valve_sdk/csgostructs.hpp"
#include "helpers/vfunc_hook.hpp"
#include <d3d9.h>

namespace index
{
    constexpr auto CreateMove               = 22;
}

namespace Hooks
{
    void Initialize();
    void Shutdown();

    inline vfunc_hook hlclient_hook;

    void __stdcall hkCreateMove(int sequence_number, float input_sample_frametime, bool active, bool& bSendPacket);
	void __fastcall hkCreateMove_Proxy(void* _this, int, int sequence_number, float input_sample_frametime, bool active);
}
