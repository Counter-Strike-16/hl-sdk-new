/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
*
*	This product contains software technology licensed from Id
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc.
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/

#ifndef VECTOR_H
#define VECTOR_H

#include "vector2d.h"

//=========================================================
// 3D Vector
//=========================================================
class Vector						// same data-layout as engine's vec3_t,
{								//		which is a vec_t[3]
public:
	// Construction/destruction
	inline Vector(void);
	inline Vector(float X, float Y, float Z);
	inline Vector(const Vector& v);
	inline Vector(float rgfl[3]);

	// Operators
	inline Vector operator-(void) const;
	inline int operator==(const Vector& v) const;
	inline int operator!=(const Vector& v) const;
	inline Vector operator+(const Vector& v) const;
	inline Vector operator-(const Vector& v) const;
	inline Vector operator*(float fl) const;
	inline Vector operator/(float fl) const;

	// Methods
	inline void CopyToArray(float* rgfl) const;
	inline float Length(void) const;
	operator float *(); // Vectors will now automatically convert to float * when needed
	operator const float *() const; // Vectors will now automatically convert to float * when needed
	inline Vector Normalize(void) const;

	inline Vector2D Make2D(void) const;
	inline float Length2D(void) const;

	// Members
	vec_t x, y, z;
};

inline Vector operator*(float fl, const Vector& v);
inline float DotProduct(const Vector& a, const Vector& b);
inline Vector CrossProduct(const Vector& a, const Vector& b);


//-----------------------------------------------------------------------------
// Vector related operations
//-----------------------------------------------------------------------------

// Vector clear
inline void VectorClear(Vector& a);

// Copy
inline void VectorCopy(const Vector& src, Vector& dst);

inline void VectorAdd(const Vector&a, const Vector& b, Vector& c);
inline void VectorSubstract(const Vector&a, const Vector& b, Vector& c);
inline void VectorMultiply(const Vector&a, const vec_t b, Vector& c);
inline void VectorDivide(const Vector&a, const vec_t b, Vector& c);
inline void VectorScale(const Vector& in, vec_t scale, Vector& result);

#endif // VECTOR_H