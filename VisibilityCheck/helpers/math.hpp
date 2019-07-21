#pragma once

#include "../valve_sdk/sdk.hpp"

#include <DirectXMath.h>

#define RAD2DEG(x) DirectX::XMConvertToDegrees(x)
#define DEG2RAD(x) DirectX::XMConvertToRadians(x)
#define M_PI 3.14159265358979323846
#define PI_F	((float)(M_PI)) 

namespace Math
{
	template<class T>
	void Normalize3(T& vec)
	{
		for (auto i = 0; i < 2; i++) {
			while (vec[i] < -180.0f) vec[i] += 360.0f;
			while (vec[i] >  180.0f) vec[i] -= 360.0f;
		}
		vec[2] = 0.f;
	}
    void VectorTransform(const Vector& in1, const matrix3x4_t& in2, Vector& out);
    bool WorldToScreen(const Vector& in, Vector& out);
}