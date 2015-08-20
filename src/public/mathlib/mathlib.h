
#ifndef MATHLIB_H
#define MATHLIB_H


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <assert.h>

#ifndef VEC_DOUBLE_T
typedef float		vec_t;
#else
typedef double		vec_t;
#endif

#include "vector.h"

typedef Vector		vec3_t;
typedef Vector2D	vec2_t;



#endif // MATHLIB_H