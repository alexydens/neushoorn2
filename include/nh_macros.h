/* Include guard */
#ifndef NH_MACROS_H
#define NH_MACROS_H

/* Project headers */
#include "nh_consts.h"

/* Convert degrees to radians */
#define NH_DEGTORAD(x)        ((x) * NH_PI / 180.0f)
/* Convert radians to degrees */
#define NH_RADTODEG(x)        ((x) * 180.0f / NH_PI)

/* Get the number of elements in an array */
#define NH_ARRLEN(x)          (sizeof(x) / sizeof(x[0]))
/* Get an index of an array from an x and a y */
#define NH_INDEX_XY(x, y, w)  ((y) * (w) + (x))

/* Get the minimum of two values */
#define NH_MIN(x, y)          ((x) < (y) ? (x) : (y))
/* Get the maximum of two values */
#define NH_MAX(x, y)          ((x) > (y) ? (x) : (y))

/* Swap two values */
#define NH_SWAP(x, y)         do {\
    __typeof(x) _tmp = (x);       \
    (x) = (y);                    \
    (y) = _tmp;                   \
  } while (0)

/* Clamp a value between two bounds */
#define NH_CLAMP(x, min, max) ((x) < (min) ?\
    (min) : ((x) > (max) ? (max) : (x)))
/* Get the sign of a number */
#define NH_SIGN(x)            ((x) < 0 ? -1 : 1)
/* Get the absolute value of a number */
#define NH_ABS(x)             ((x) < 0 ? -(x) : (x))
/* Linear interpolation */
#define NH_LERP(x, y, t)      ((x) + ((y) - (x)) * (t))

/* const char* from boolean */
#define NH_BOOLSTR(x)         ((x) ? "true" : "false")

/* Assertions */
#ifdef DEBUG
#ifdef NH_INCLUDE_STDLIB
#include <stdlib.h>
#define NH_ASSERT(x)          do{if (!(x)) exit(-1); }while(0);
#else
#define NH_ASSERT(x)          do{if (!(x)) *((u8*)0) = 0;}while(0);
#endif
#else
#define NH_ASSERT(x)          ((void)(x))
#endif


#endif /* NH_MACROS_H */
