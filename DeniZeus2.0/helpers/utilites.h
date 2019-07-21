#ifndef UTILS
#define UTILS

#include <Windows.h>
#include <sstream>
#include <thread>
#include <DirectXMath.h>

#define RAD2DEG(x) DirectX::XMConvertToDegrees(x)
#define DEG2RAD(x) DirectX::XMConvertToRadians(x)
#define M_PI 3.14159265358979323846
#define PI_F	((float)(M_PI)) 
#define PLAYER_ON_FLOOR (1 << 0)
constexpr int MULTIPLAYER_BACKUP = 150;

class QAngle
{
public:
	QAngle(void)
	{
		Init();
	}
	QAngle(float X, float Y, float Z)
	{
		Init(X, Y, Z);
	}
	QAngle(const float* clr)
	{
		Init(clr[0], clr[1], clr[2]);
	}

	void Init(float ix = 0.0f, float iy = 0.0f, float iz = 0.0f)
	{
		pitch = ix;
		yaw = iy;
		roll = iz;
	}

	float operator[](int i) const
	{
		return ((float*)this)[i];
	}
	float& operator[](int i)
	{
		return ((float*)this)[i];
	}

	QAngle& operator+=(const QAngle& v)
	{
		pitch += v.pitch; yaw += v.yaw; roll += v.roll;
		return *this;
	}
	QAngle& operator-=(const QAngle& v)
	{
		pitch -= v.pitch; yaw -= v.yaw; roll -= v.roll;
		return *this;
	}
	QAngle& operator*=(float fl)
	{
		pitch *= fl;
		yaw *= fl;
		roll *= fl;
		return *this;
	}
	QAngle& operator*=(const QAngle& v)
	{
		pitch *= v.pitch;
		yaw *= v.yaw;
		roll *= v.roll;
		return *this;
	}
	QAngle& operator/=(const QAngle& v)
	{
		pitch /= v.pitch;
		yaw /= v.yaw;
		roll /= v.roll;
		return *this;
	}
	QAngle& operator+=(float fl)
	{
		pitch += fl;
		yaw += fl;
		roll += fl;
		return *this;
	}
	QAngle& operator/=(float fl)
	{
		pitch /= fl;
		yaw /= fl;
		roll /= fl;
		return *this;
	}
	QAngle& operator-=(float fl)
	{
		pitch -= fl;
		yaw -= fl;
		roll -= fl;
		return *this;
	}

	QAngle& operator=(const QAngle& vOther)
	{
		pitch = vOther.pitch; yaw = vOther.yaw; roll = vOther.roll;
		return *this;
	}

	QAngle operator-(void) const
	{
		return QAngle(-pitch, -yaw, -roll);
	}
	QAngle operator+(const QAngle& v) const
	{
		return QAngle(pitch + v.pitch, yaw + v.yaw, roll + v.roll);
	}
	QAngle operator-(const QAngle& v) const
	{
		return QAngle(pitch - v.pitch, yaw - v.yaw, roll - v.roll);
	}
	QAngle operator*(float fl) const
	{
		return QAngle(pitch * fl, yaw * fl, roll * fl);
	}
	QAngle operator*(const QAngle& v) const
	{
		return QAngle(pitch * v.pitch, yaw * v.yaw, roll * v.roll);
	}
	QAngle operator/(float fl) const
	{
		return QAngle(pitch / fl, yaw / fl, roll / fl);
	}
	QAngle operator/(const QAngle& v) const
	{
		return QAngle(pitch / v.pitch, yaw / v.yaw, roll / v.roll);
	}

	float Length() const
	{
		return sqrt(pitch * pitch + yaw * yaw + roll * roll);
	}
	float LengthSqr(void) const
	{
		return (pitch * pitch + yaw * yaw + roll * roll);
	}
	bool IsZero(float tolerance = 0.01f) const
	{
		return (pitch > -tolerance && pitch < tolerance &&
			yaw > -tolerance && yaw < tolerance &&
			roll > -tolerance && roll < tolerance);
	}

	float Normalize() const
	{
		QAngle res = *this;
		float l = res.Length();
		if (l != 0.0f)
		{
			res /= l;
		}
		else
		{
			res[0] = res[1] = res[2] = 0.0f;
		}
		return l;
	}

	float pitch;
	float yaw;
	float roll;
};

inline QAngle operator*(float lhs, const QAngle& rhs)
{
	return rhs * lhs;
}
inline QAngle operator/(float lhs, const QAngle& rhs)
{
	return rhs / lhs;
}

#include <sstream>

class Vector
{
public:
	Vector(void)
	{
		Invalidate();
	}
	Vector(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = Z;
	}
	Vector(const float* clr)
	{
		x = clr[0];
		y = clr[1];
		z = clr[2];
	}

	void Init(float ix = 0.0f, float iy = 0.0f, float iz = 0.0f)
	{
		x = ix; y = iy; z = iz;
	}
	bool IsValid() const
	{
		return std::isfinite<float>(x) && std::isfinite<float>(y) && std::isfinite<float>(z);
	}
	void Invalidate()
	{
		x = y = z = std::numeric_limits<float>::infinity();
	}

	float& operator[](int i)
	{
		return ((float*)this)[i];
	}
	float operator[](int i) const
	{
		return ((float*)this)[i];
	}

	void Zero()
	{
		x = y = z = 0.0f;
	}

	bool operator==(const Vector& src) const
	{
		return (src.x == x) && (src.y == y) && (src.z == z);
	}
	bool operator!=(const Vector& src) const
	{
		return (src.x != x) || (src.y != y) || (src.z != z);
	}

	Vector& operator+=(const Vector& v)
	{
		x += v.x; y += v.y; z += v.z;
		return *this;
	}
	Vector& operator-=(const Vector& v)
	{
		x -= v.x; y -= v.y; z -= v.z;
		return *this;
	}
	Vector& operator*=(float fl)
	{
		x *= fl;
		y *= fl;
		z *= fl;
		return *this;
	}
	Vector& operator*=(const Vector& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return *this;
	}
	Vector& operator/=(const Vector& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
		return *this;
	}
	Vector& operator+=(float fl)
	{
		x += fl;
		y += fl;
		z += fl;
		return *this;
	}
	Vector& operator/=(float fl)
	{
		x /= fl;
		y /= fl;
		z /= fl;
		return *this;
	}
	Vector& operator-=(float fl)
	{
		x -= fl;
		y -= fl;
		z -= fl;
		return *this;
	}

	void NormalizeInPlace()
	{
		*this = Normalized();
	}
	Vector Normalized() const
	{
		Vector res = *this;
		float l = res.Length();
		if (l != 0.0f) {
			res /= l;
		}
		else {
			res.x = res.y = res.z = 0.0f;
		}
		return res;
	}

	float DistTo(const Vector& vOther) const
	{
		Vector delta;

		delta.x = x - vOther.x;
		delta.y = y - vOther.y;
		delta.z = z - vOther.z;

		return delta.Length();
	}
	float DistToSqr(const Vector& vOther) const
	{
		Vector delta;

		delta.x = x - vOther.x;
		delta.y = y - vOther.y;
		delta.z = z - vOther.z;

		return delta.LengthSqr();
	}
	float Dot(const Vector& vOther) const
	{
		return (x * vOther.x + y * vOther.y + z * vOther.z);
	}
	float Length() const
	{
		return sqrt(x * x + y * y + z * z);
	}
	float LengthSqr(void) const
	{
		return (x * x + y * y + z * z);
	}
	float Length2D() const
	{
		return sqrt(x * x + y * y);
	}

	Vector& operator=(const Vector& vOther)
	{
		x = vOther.x; y = vOther.y; z = vOther.z;
		return *this;
	}

	Vector operator-(void) const
	{
		return Vector(-x, -y, -z);
	}
	Vector operator+(const Vector& v) const
	{
		return Vector(x + v.x, y + v.y, z + v.z);
	}
	Vector operator-(const Vector& v) const
	{
		return Vector(x - v.x, y - v.y, z - v.z);
	}
	Vector operator*(float fl) const
	{
		return Vector(x * fl, y * fl, z * fl);
	}
	Vector operator*(const Vector& v) const
	{
		return Vector(x * v.x, y * v.y, z * v.z);
	}
	Vector operator/(float fl) const
	{
		return Vector(x / fl, y / fl, z / fl);
	}
	Vector operator/(const Vector& v) const
	{
		return Vector(x / v.x, y / v.y, z / v.z);
	}

	float x, y, z;
};

inline Vector operator*(float lhs, const Vector& rhs)
{
	return rhs * lhs;
}
inline Vector operator/(float lhs, const Vector& rhs)
{
	return rhs / lhs;
}

class __declspec(align(16)) VectorAligned : public Vector
{
public:
	inline VectorAligned(void) {};
	inline VectorAligned(float X, float Y, float Z)
	{
		Init(X, Y, Z);
	}

public:
	explicit VectorAligned(const Vector& vOther)
	{
		Init(vOther.x, vOther.y, vOther.z);
	}

	VectorAligned& operator=(const Vector& vOther)
	{
		Init(vOther.x, vOther.y, vOther.z);
		return *this;
	}

	VectorAligned& operator=(const VectorAligned& vOther)
	{
		Init(vOther.x, vOther.y, vOther.z);
		return *this;
	}

	float w;
};


class CUserCmd {
public:
	int     command_number;     // 0x04 For matching server and client commands for debugging
	int     tick_count;         // 0x08 the tick the client created this command
	QAngle  viewangles;         // 0x0C Player instantaneous view angles.
	Vector  aimdirection;       // 0x18
	float   forwardmove;        // 0x24
	float   sidemove;           // 0x28
	float   upmove;             // 0x2C
	int     buttons;            // 0x30 Attack button states
	char    impulse;            // 0x34
	int     weaponselect;       // 0x38 Current weapon id
	int     weaponsubtype;      // 0x3C
	int     random_seed;        // 0x40 For shared random functions
	short   mousedx;            // 0x44 mouse accum in x from create move
	short   mousedy;            // 0x46 mouse accum in y from create move
	bool    hasbeenpredicted;   // 0x48 Client only, tracks whether we've predicted this command at least once
	char    pad_0x4C[0x18];     // 0x4C Current sizeof( usercmd ) =  100  = 0x64
};

typedef unsigned long CRC32_t;

class CVerifiedUserCmd
{
public:
    CUserCmd m_cmd;
	CRC32_t  m_crc;
};

class CInput
{
public:
	char                pad_0x00[0x0C];
	bool                m_trackir_available;
	bool                m_mouse_initiated;
	bool                m_mouse_active;
	bool                m_fJoystickAdvancedInit;
	char                pad_0x08[0x2C];
	void*				m_pKeys;
	char                pad_0x38[0x6C];
	bool                m_fCameraInterceptingMouse;
	bool                m_fCameraInThirdPerson;
	bool                m_fCameraMovingWithMouse;
	Vector				m_vecCameraOffset;
	bool                m_fCameraDistanceMove;
	int                 m_nCameraOldX;
	int                 m_nCameraOldY;
	int                 m_nCameraX;
	int                 m_nCameraY;
	bool                m_CameraIsOrthographic;
	Vector              m_angPreviousViewAngles;
	Vector              m_angPreviousViewAnglesTilt;
	float               m_flLastForwardMove;
	int                 m_nClearInputState;
	char                pad_0xE4[0x8];
	unsigned int		m_pCommands;
	unsigned int	    m_pVerifiedCommands;
};

class CGlobalVarsBase
{
public:
	float     realtime;                     // 0x0000
	int       framecount;                   // 0x0004
	float     absoluteframetime;            // 0x0008
	float     absoluteframestarttimestddev; // 0x000C
	float     curtime;                      // 0x0010
	float     frametime;                    // 0x0014
	int       maxClients;                   // 0x0018
	int       tickcount;                    // 0x001C
	float     interval_per_tick;            // 0x0020
	float     interpolation_amount;         // 0x0024
	int       simTicksThisFrame;            // 0x0028
	int       network_protocol;             // 0x002C
	void*	  pSaveData;                    // 0x0030
	bool      m_bClient;                    // 0x0031
	bool      m_bRemoteClient;              // 0x0032

private:
	// 100 (i.e., tickcount is rounded down to this base and then the "delta" from this base is networked
	int       nTimestampNetworkingBase;
	// 32 (entindex() % nTimestampRandomizeWindow ) is subtracted from gpGlobals->tickcount to Set the networking basis, prevents
	//  all of the entities from forcing a new PackedEntity on the same tick (i.e., prevents them from getting lockstepped on this)
	int       nTimestampRandomizeWindow;
};

enum AimbotType {
	AIM_ALWAYS,
	AIM_KEYPRESSED,
	AIM_FIRE,
	AIM_KEYPRESS_OR_FIRE
};



inline QAngle CalcAngle(const Vector& src, const Vector& dst)
{
	QAngle vAngle;
	Vector delta((src.x - dst.x), (src.y - dst.y), (src.z - dst.z));
	double hyp = sqrt(delta.x * delta.x + delta.y * delta.y);

	vAngle.pitch = float(atanf(float(delta.z / hyp)) * 57.295779513082f);
	vAngle.yaw = float(atanf(float(delta.y / delta.x)) * 57.295779513082f);
	vAngle.roll = 0.0f;

	if (delta.x >= 0.0)
		vAngle.yaw += 180.0f;

	return vAngle;
}

inline void AngleVectors(const QAngle& angles, Vector& forward)
{
	float	sp, sy, cp, cy;

	DirectX::XMScalarSinCos(&sp, &cp, DEG2RAD(angles[0]));
	DirectX::XMScalarSinCos(&sy, &cy, DEG2RAD(angles[1]));

	forward.x = cp * cy;
	forward.y = cp * sy;
	forward.z = -sp;
}

inline void VectorAngles(const Vector& forward, QAngle& angles)
{
	float	tmp, yaw, pitch;

	if (forward[1] == 0 && forward[0] == 0) {
		yaw = 0;
		if (forward[2] > 0)
			pitch = 270;
		else
			pitch = 90;
	}
	else {
		yaw = (atan2(forward[1], forward[0]) * 180 / DirectX::XM_PI);
		if (yaw < 0)
			yaw += 360;

		tmp = sqrt(forward[0] * forward[0] + forward[1] * forward[1]);
		pitch = (atan2(-forward[2], tmp) * 180 / DirectX::XM_PI);
		if (pitch < 0)
			pitch += 360;
	}

	angles[0] = pitch;
	angles[1] = yaw;
	angles[2] = 0;
}

template<class T>
inline void Normalize3(T& vec)
{
	for (auto i = 0; i < 2; i++) {
		while (vec[i] < -180.0f) vec[i] += 360.0f;
		while (vec[i] > 180.0f) vec[i] -= 360.0f;
	}
	vec[2] = 0.f;
}

inline void ClampAngles(QAngle& angles)
{
	if (angles.pitch > 89.0f) angles.pitch = 89.0f;
	else if (angles.pitch < -89.0f) angles.pitch = -89.0f;

	if (angles.yaw > 180.0f) angles.yaw = 180.0f;
	else if (angles.yaw < -180.0f) angles.yaw = -180.0f;

	angles.roll = 0;

}

inline QAngle Smooth(float smooth, QAngle currentAngle, QAngle aimAngle)
{
	QAngle angle;
	QAngle dest = angle;
	if (smooth > 0)
	{
		QAngle delta;
		delta.yaw = currentAngle.yaw - aimAngle.yaw;
		delta.pitch = currentAngle.pitch - aimAngle.pitch;
		Normalize3(delta);
		ClampAngles(delta);
		dest.yaw = currentAngle.yaw - delta.yaw / (smooth);
		dest.pitch = currentAngle.pitch - delta.pitch / (smooth);
		Normalize3(dest);
		ClampAngles(dest);
	}

	angle = dest;

	return angle;

}

#pragma once

#include <limits>

struct cplane_t
{
	Vector normal;
	float dist;
	uint8_t type;   // for fast side tests
	uint8_t signbits;  // signx + (signy<<1) + (signz<<1)
	uint8_t pad[2];

};

class matrix3x4_t
{
public:
	matrix3x4_t() {}
	matrix3x4_t(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23)
	{
		m_flMatVal[0][0] = m00; m_flMatVal[0][1] = m01; m_flMatVal[0][2] = m02; m_flMatVal[0][3] = m03;
		m_flMatVal[1][0] = m10; m_flMatVal[1][1] = m11; m_flMatVal[1][2] = m12; m_flMatVal[1][3] = m13;
		m_flMatVal[2][0] = m20; m_flMatVal[2][1] = m21; m_flMatVal[2][2] = m22; m_flMatVal[2][3] = m23;
	}
	//-----------------------------------------------------------------------------
	// Creates a matrix where the X axis = forward
	// the Y axis = left, and the Z axis = up
	//-----------------------------------------------------------------------------
	void Init(const Vector& xAxis, const Vector& yAxis, const Vector& zAxis, const Vector& vecOrigin)
	{
		m_flMatVal[0][0] = xAxis.x; m_flMatVal[0][1] = yAxis.x; m_flMatVal[0][2] = zAxis.x; m_flMatVal[0][3] = vecOrigin.x;
		m_flMatVal[1][0] = xAxis.y; m_flMatVal[1][1] = yAxis.y; m_flMatVal[1][2] = zAxis.y; m_flMatVal[1][3] = vecOrigin.y;
		m_flMatVal[2][0] = xAxis.z; m_flMatVal[2][1] = yAxis.z; m_flMatVal[2][2] = zAxis.z; m_flMatVal[2][3] = vecOrigin.z;
	}

	//-----------------------------------------------------------------------------
	// Creates a matrix where the X axis = forward
	// the Y axis = left, and the Z axis = up
	//-----------------------------------------------------------------------------
	matrix3x4_t(const Vector& xAxis, const Vector& yAxis, const Vector& zAxis, const Vector& vecOrigin)
	{
		Init(xAxis, yAxis, zAxis, vecOrigin);
	}

	inline void SetOrigin(Vector const& p)
	{
		m_flMatVal[0][3] = p.x;
		m_flMatVal[1][3] = p.y;
		m_flMatVal[2][3] = p.z;
	}

	inline void Invalidate(void)
	{
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				m_flMatVal[i][j] = std::numeric_limits<float>::infinity();;
			}
		}
	}

	Vector GetXAxis()  const { return at(0); }
	Vector GetYAxis()  const { return at(1); }
	Vector GetZAxis()  const { return at(2); }
	Vector GetOrigin() const { return at(3); }

	Vector at(int i) const { return Vector{ m_flMatVal[0][i], m_flMatVal[1][i], m_flMatVal[2][i] }; }

	float* operator[](int i) { return m_flMatVal[i]; }
	const float* operator[](int i) const { return m_flMatVal[i]; }
	float* Base() { return &m_flMatVal[0][0]; }
	const float* Base() const { return &m_flMatVal[0][0]; }

	float m_flMatVal[3][4];
};

class VMatrix
{
public:
	float  m[4][4];
};



inline void AngleVectors(const QAngle& angles, Vector& forward, Vector& right, Vector& up)
{
	float sr, sp, sy, cr, cp, cy;

	DirectX::XMScalarSinCos(&sp, &cp, DEG2RAD(angles[0]));
	DirectX::XMScalarSinCos(&sy, &cy, DEG2RAD(angles[1]));
	DirectX::XMScalarSinCos(&sr, &cr, DEG2RAD(angles[2]));

	forward.x = (cp * cy);
	forward.y = (cp * sy);
	forward.z = (-sp);
	right.x = (-1 * sr * sp * cy + -1 * cr * -sy);
	right.y = (-1 * sr * sp * sy + -1 * cr * cy);
	right.z = (-1 * sr * cp);
	up.x = (cr * sp * cy + -sr * -sy);
	up.y = (cr * sp * sy + -sr * cy);
	up.z = (cr * cp);
}

inline float GetFOV(const QAngle& viewAngle, const QAngle& aimAngle)
{
	Vector ang, aim;

	AngleVectors(viewAngle, aim);
	AngleVectors(aimAngle, ang);

	return RAD2DEG(acos(aim.Dot(ang) / aim.LengthSqr()));
}

struct sGlow
{
	float r;
	float g;
	float b;
	float a;
	uint8_t unk1[16];
	bool m_bRenderWhenOccluded;
	bool m_bRenderWhenUnoccluded;
	bool m_bFullBloom;
};

struct sBone {
	byte padding[12];
	float x;
	byte padding2[12];
	float y;
	byte padding3[12];
	float z;

};



inline float FASTSQRT(float x)
{
	unsigned int i = *(unsigned int*)& x;

	i += 127 << 23;
	// approximation of square root
	i >>= 1;
	return *(float*)& i;
}

float VectorDistance(const Vector& v1, const Vector& v2)
{
	return FASTSQRT(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2));
}

class Color
{
public:
	Color(void)
	{
		Invalidate();
	}
	Color(int R, int G, int B, int A)
	{
		r = R;
		g = G;
		b = B;
		a = A;
	}
	
	Color(int R, int G, int B)
	{
		r = R;
		g = G;
		b = B;
		a = 255;
	}
	Color(const float* clr)
	{
		r = clr[0];
		g = clr[1];
		b = clr[2];
		a = clr[3];
	}

	void Init(int ir = 0, int ig = 0, int ib = 0, int ia = 0)
	{
		r = ir; g = ig; b = ib; a = ia;
	}
	void Invalidate()
	{
		r = g = b = a = std::numeric_limits<int>::infinity();
	}

	int& operator[](int i)
	{
		return ((int*)this)[i];
	}
	int operator[](int i) const
	{
		return ((int*)this)[i];
	}

	void Zero()
	{
		r = g = b = a = 0;
	}

	bool operator==(const Color& src) const
	{
		return (src.r == r) && (src.g == g) && (src.b == b) && (src.a == a);
	}
	bool operator!=(const Color& src) const
	{
		return (src.r != r) || (src.g != g) || (src.b != b) || (src.a != a);
	}

	Color& operator+=(const Color& v)
	{
		r += v.r; g += v.g; b += v.b; a += v.a;
		return *this;
	}
	Color& operator-=(const Color& v)
	{
		r -= v.r; g -= v.g; b -= v.b; a -= v.a;
		return *this;
	}
	Color& operator*=(int fl)
	{
		r *= fl;
		g *= fl;
		b *= fl;
		a *= fl;
		return *this;
	}
	Color& operator*=(const Color& v)
	{
		r *= v.r;
		g *= v.g;
		b *= v.b;
		a *= v.a;
		return *this;
	}
	Color& operator/=(const Color& v)
	{
		r /= v.r;
		g /= v.g;
		b /= v.b;
		a /= v.a;
		return *this;
	}
	Color& operator+=(int fl)
	{
		r += fl;
		g += fl;
		b += fl;
		a += fl;
		return *this;
	}
	Color& operator/=(int fl)
	{
		r /= fl;
		g /= fl;
		b /= fl;
		a /= fl;
		return *this;
	}
	Color& operator-=(int fl)
	{
		r -= fl;
		g -= fl;
		b -= fl;
		a -= fl;
		return *this;
	}
	Color& operator=(const Color& vOther)
	{
		r = vOther.r; g = vOther.g; b = vOther.b; a = vOther.a;
		return *this;
	}

	int r, g, b, a;
};

enum BoneIDS {
	pelvis = 0,
	spine_0 = 3,
	spine_1 = 4,
	spine_2 = 5,
	spine_3 = 6,
	neck = 7,
	head = 8,
	clavicle_l = 9,
	clavicle_r = 37,
	arm_upper_l = 10,
	arm_upper_r = 38,
	hand_l = 12,
	hand_r = 40,
	lfoot_lock = 69,
	rfoot_lock = 76

};

struct player_info {
	__int64         unknown;
	union {
		__int64       steamID64;
		struct {
			__int32     xuid_low;
			__int32     xuid_high;
		};
	};
	char            szName[128];
	int             userId;
	char            szSteamID[20];
	char            pad_0x00A8[0x10];
	unsigned long   iSteamID;
	char            szFriendsName[128];
	bool            fakeplayer;
	bool            ishltv;
	unsigned int    customfiles[4];
	unsigned char   filesdownloaded;
};

#include "../managers/config_manager.h"

inline bool key_pressed(int key) {
	short key_state = GetAsyncKeyState(key);
	static HWND csgo_window = FindWindowA(NULL, "Counter-Strike: Global Offensive");
	static HWND overlay_window = FindWindowA(NULL, "DeniZeus Overlay");
	HWND fore_ground = GetForegroundWindow();
	return ((key_state & 0x8000) || (key_state & 0x7FFF)) && (fore_ground == overlay_window || fore_ground == csgo_window);
}

#endif