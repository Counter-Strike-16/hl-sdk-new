
#include "mathlib.h"
#include "vector.h"

#ifdef VECTOR_PARANOIA
#define CHECK_VALID( _v)	Assert( (_v).IsValid() )
#else
#ifdef GNUC
#define CHECK_VALID( _v)
#else
#define CHECK_VALID( _v)	0
#endif
#endif

inline Vector::Vector(void)
{

}

inline  Vector::Vector(float X, float Y, float Z)
{
	x = X;
	y = Y;
	z = Z;
}

inline  Vector::Vector(const Vector& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

inline  Vector::Vector(float rgfl[3])
{
	x = rgfl[0];
	y = rgfl[1];
	z = rgfl[2];
}

// Operators
inline Vector Vector::operator-(void) const
{
	return Vector(-x, -y, -z);
}

inline int Vector::operator==(const Vector& v) const
{
	return x == v.x && y == v.y && z == v.z;
}

inline int Vector::operator!=(const Vector& v) const
{
	return !(*this == v);
}

inline Vector Vector::operator+(const Vector& v) const
{
	return Vector(x + v.x, y + v.y, z + v.z);
}

inline Vector Vector::operator-(const Vector& v) const
{
	return Vector(x - v.x, y - v.y, z - v.z);
}

inline Vector Vector::operator*(float fl) const	
{
	return Vector(x*fl, y*fl, z*fl);
}

inline Vector Vector::operator/(float fl) const
{
	return Vector(x / fl, y / fl, z / fl);
}

// Methods
inline void Vector::CopyToArray(float* rgfl) const
{
	rgfl[0] = x, rgfl[1] = y, rgfl[2] = z;
}

inline float Vector::Length(void) const	
{
	return sqrt(x*x + y*y + z*z);
}

Vector::operator float *()
{
	return &x;
}

Vector::operator const float *() const 
{
	return &x; 
}

inline Vector Vector::Normalize(void) const
{
	float flLen = Length();
	if (flLen == 0) return Vector(0, 0, 1); // ????
	flLen = 1 / flLen;
	return Vector(x * flLen, y * flLen, z * flLen);
}

inline Vector2D Vector::Make2D(void) const
{
	Vector2D	Vec2;

	Vec2.x = x;
	Vec2.y = y;

	return Vec2;
}

inline float Vector::Length2D(void) const
{
	return sqrt(x*x + y*y);
}

inline Vector operator*(float fl, const Vector& v)
{
	return v * fl;
}

inline float DotProduct(const Vector& a, const Vector& b)
{
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}

inline Vector CrossProduct(const Vector& a, const Vector& b)
{
	return Vector(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}


//-----------------------------------------------------------------------------
// Vector related operations
//-----------------------------------------------------------------------------
inline void VectorClear(Vector& a)
{
	a.x = a.y = a.z = 0.0f;
}

//-----------------------------------------------------------------------------
// Copy
//-----------------------------------------------------------------------------
inline void VectorCopy(const Vector& src, Vector& dst)
{
	CHECK_VALID(src);
	dst.x = src.x;
	dst.y = src.y;
	dst.z = src.z;
}

inline void VectorAdd(const Vector&a, const Vector& b, Vector& c)
{
	CHECK_VALID(a);
	CHECK_VALID(b);
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
}

inline void VectorSubstract(const Vector&a, const Vector& b, Vector& c)
{
	CHECK_VALID(a);
	CHECK_VALID(b);
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
}

inline void VectorMultiply(const Vector&a, vec_t b, Vector& c)
{
	CHECK_VALID(a);
	assert(isfinite(b));
	c.x = a.x * b;
	c.y = a.y * b;
	c.z = a.z * b;
}


// for backwards compatability
inline void VectorScale(const Vector& in, vec_t scale, Vector& result)
{
	VectorMultiply(in, scale, result);
}

inline void VectorDivide(const Vector&a, vec_t b, Vector& c)
{
	CHECK_VALID(a);
	assert(b != 0.0f);
	vec_t oob = 1.0f / b;
	c.x = a.x * oob;
	c.y = a.y * oob;
	c.z = a.z * oob;
}
