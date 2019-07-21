#pragma once

#include "sdk.hpp"
#include <array>
#include "../helpers/utils.hpp"

#define NETVAR(type, name, table, netvar)                           \
    type& name##() const {                                          \
        static int _##name = NetvarSys::Get().GetOffset(table, netvar);     \
        return *(type*)((uintptr_t)this + _##name);                 \
    }

#define PNETVAR(type, name, table, netvar)                           \
    type* name##() const {                                          \
        static int _##name = NetvarSys::Get().GetOffset(table, netvar);     \
        return (type*)((uintptr_t)this + _##name);                 \
    }

#define NETPROP(name, table, netvar) static RecvProp* name() \
{ \
	static auto prop_ptr = NetvarSys::Get().GetNetvarProp(table,netvar); \
	return prop_ptr; \
}

struct datamap_t;
class AnimationLayer;
class CBasePlayerAnimState;
class CCSGOPlayerAnimState;
class C_BaseEntity;

class C_BaseEntity;

class C_BaseEntity : public IClientEntity
{
public:
	datamap_t *GetPredDescMap() {
		typedef datamap_t*(__thiscall *o_GetPredDescMap)(void*);
		return CallVFunction<o_GetPredDescMap>(this, 17)(this);
	}
	static __forceinline C_BaseEntity* GetEntityByIndex(int index) {
		return static_cast<C_BaseEntity*>(g_EntityList->GetClientEntity(index));
	}
	static __forceinline C_BaseEntity* get_entity_from_handle(CBaseHandle h) {
		return static_cast<C_BaseEntity*>(g_EntityList->GetClientEntityFromHandle(h));
	}

	NETVAR(int32_t, m_nModelIndex, "DT_BaseEntity", "m_nModelIndex");
	NETVAR(int32_t, m_iTeamNum, "DT_BaseEntity", "m_iTeamNum");
	NETVAR(Vector, m_vecOrigin, "DT_BaseEntity", "m_vecOrigin");
	NETVAR(Vector, m_vecAngles, "DT_BaseEntity", "m_vecAngles");
	NETVAR(bool, m_bShouldGlow, "DT_DynamicProp", "m_bShouldGlow");
	NETVAR(CHandle<C_BasePlayer>, m_hOwnerEntity, "DT_BaseEntity", "m_hOwnerEntity");
	NETVAR(bool, m_bSpotted, "DT_BaseEntity", "m_bSpotted");
	NETVAR(float_t, m_flC4Blow, "DT_PlantedC4", "m_flC4Blow");


	const matrix3x4_t& m_rgflCoordinateFrame()
	{
		static auto _m_rgflCoordinateFrame = NetvarSys::Get().GetOffset("DT_BaseEntity", "m_CollisionGroup") - 0x30;
		return *(matrix3x4_t*)((uintptr_t)this + _m_rgflCoordinateFrame);
	}

	bool IsPlayer();
	//bool isSpotted();
};

class C_BasePlayer : public C_BaseEntity
{
public:
	static __forceinline C_BasePlayer* GetPlayerByUserId(int id)
	{
		return static_cast<C_BasePlayer*>(GetEntityByIndex(g_EngineClient->GetPlayerForUserID(id)));
	}
	static __forceinline C_BasePlayer* GetPlayerByIndex(int i)
	{
		return static_cast<C_BasePlayer*>(GetEntityByIndex(i));
	}

	NETVAR(Vector, m_vecViewOffset, "DT_BasePlayer", "m_vecViewOffset[0]");
	NETVAR(int32_t, m_lifeState, "DT_BasePlayer", "m_lifeState");
	NETVAR(int32_t, m_nHitboxSet, "DT_BaseAnimating", "m_nHitboxSet");

	Vector        GetEyePos();
	int           GetGlowIndex();
	bool          IsAlive();
	Vector        GetHitboxPos(int hitbox_id);
	Vector        GetBonePos(int bone);
	bool          CanSeePlayer(C_BasePlayer* player, int hitbox);

};