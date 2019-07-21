#include "csgostructs.hpp"
#include "../Helpers/Math.hpp"
#include "../Helpers/Utils.hpp"

bool C_BaseEntity::IsPlayer()
{
	//index: 152
	//ref: "effects/nightvision"
	//sig: 8B 92 ? ? ? ? FF D2 84 C0 0F 45 F7 85 F6
	return CallVFunction<bool(__thiscall*)(C_BaseEntity*)>(this, 155)(this);
}

Vector C_BasePlayer::GetEyePos()
{
	return m_vecOrigin() + m_vecViewOffset();
}

bool C_BasePlayer::IsAlive()
{
	return m_lifeState() == LIFE_ALIVE;
}

int C_BasePlayer::GetGlowIndex()
{
	static auto glow_ptr = NetvarSys::Get().GetOffset("DT_CSPlayer", "m_flFlashDuration");
	return *(int*)((uintptr_t)this + glow_ptr + 0x18);
}

Vector C_BasePlayer::GetHitboxPos(int hitbox_id)
{
	matrix3x4_t boneMatrix[MAXSTUDIOBONES];

	if (SetupBones(boneMatrix, MAXSTUDIOBONES, BONE_USED_BY_HITBOX, 0.0f)) {
		auto studio_model = g_MdlInfo->GetStudiomodel(GetModel());
		if (studio_model) {
			auto hitbox = studio_model->GetHitboxSet(0)->GetHitbox(hitbox_id);
			if (hitbox) {
				auto
					min = Vector{},
					max = Vector{};

				Math::VectorTransform(hitbox->bbmin, boneMatrix[hitbox->bone], min);
				Math::VectorTransform(hitbox->bbmax, boneMatrix[hitbox->bone], max);

				return (min + max) / 2.0f;
			}
		}
	}
	return Vector{};
}

Vector C_BasePlayer::GetBonePos(int bone)
{
	matrix3x4_t boneMatrix[MAXSTUDIOBONES];
	if (SetupBones(boneMatrix, MAXSTUDIOBONES, BONE_USED_BY_ANYTHING, 0.0f)) {
		return boneMatrix[bone].at(3);
	}
	return Vector{};
}

typedef bool(*td_LineGoesThroughSmoke)(Vector, Vector, int16_t);
static auto LineGoesThroughSmoke = Utils::PatternScan(GetModuleHandleA("client_panorama.dll"), "55 8B EC 83 EC 08 8B 15 ? ? ? ? 0F 57 C0");

bool isInSmoke(const Vector& vStartPos, const Vector& vEndPos) {
	return reinterpret_cast<td_LineGoesThroughSmoke>(LineGoesThroughSmoke)(vStartPos, vEndPos, 1);
}

bool C_BasePlayer::CanSeePlayer(C_BasePlayer* player, int hitbox)
{
	CGameTrace tr;
	Ray_t ray;
	CTraceFilter filter;
	filter.pSkip = this;

	auto endpos = player->GetHitboxPos(hitbox);

	ray.Init(GetEyePos(), endpos);
	g_EngineTrace->TraceRay(ray, MASK_SHOT | CONTENTS_GRATE, &filter, &tr);

	return (tr.hit_entity == player || tr.fraction > 0.97f) && !isInSmoke(GetEyePos(), endpos);
}
