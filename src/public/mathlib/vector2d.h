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

#ifndef VECTOR2D_H
#define VECTOR2D_H


//=========================================================
// 2DVector - used for many pathfinding and many other 
// operations that are treated as planar rather than 3d.
//=========================================================
class Vector2D
{
public:
	inline Vector2D(void);
	inline Vector2D(float X, float Y);
	inline Vector2D operator+(const Vector2D& v) const;
	inline Vector2D operator-(const Vector2D& v) const;
	inline Vector2D operator*(float fl)	const;
	inline Vector2D operator/(float fl) const;

	inline float Length(void) const;

	inline Vector2D Normalize(void) const;

	vec_t	x, y;
};

inline float DotProduct(const Vector2D& a, const Vector2D& b);
inline Vector2D operator*(float fl, const Vector2D& v);

#endif // VECTOR2D_H