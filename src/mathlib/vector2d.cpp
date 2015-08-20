#include "mathlib.h"
#include "vector2d.h"

#ifdef VECTOR_PARANOIA
#define CHECK_VALID( _v)	Assert( (_v).IsValid() )
#else
#ifdef GNUC
#define CHECK_VALID( _v)
#else
#define CHECK_VALID( _v)	0
#endif
#endif

inline Vector2D::Vector2D(void) 
{

}

inline Vector2D::Vector2D(float X, float Y)
{ 
	x = X;
	y = Y; 
}

inline Vector2D Vector2D::operator + (const Vector2D& v) const
{
	return Vector2D(x + v.x, y + v.y);
}

inline Vector2D Vector2D::operator-(const Vector2D& v) const
{
	return Vector2D(x - v.x, y - v.y);
}

inline Vector2D Vector2D::operator*(float fl) const
{
	return Vector2D(x*fl, y*fl);
}

inline Vector2D Vector2D::operator/(float fl) const
{
	return Vector2D(x / fl, y / fl);
}

inline float Vector2D::Length(void)	const
{
	return sqrt(x*x + y*y);
}

inline Vector2D Vector2D::Normalize(void) const
{
	Vector2D vec2;

	float flLen = Length();
	if (flLen == 0)
	{
		return Vector2D(0, 0);
	}
	else
	{
		flLen = 1 / flLen;
		return Vector2D(x * flLen, y * flLen);
	}
}

inline float DotProduct(const Vector2D& a, const Vector2D& b)
{
	return(a.x*b.x + a.y*b.y);
}

inline Vector2D operator*(float fl, const Vector2D& v)
{
	return v * fl;
}
