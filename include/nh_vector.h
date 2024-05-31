/* Include guard */
#ifndef NH_VECTOR_H
#define NH_VECTOR_H

/* Project headers */
#include "nh_base.h"

/* Vector (2D, float) */
typedef struct nh_vec2_t {
  f32 x;
  f32 y;
} nh_vec2_t;
/* Vector (2D, int) */
typedef struct nh_vec2i_t {
  i32 x;
  i32 y;
} nh_vec2i_t;

/* Vector (3D, float) */
typedef struct nh_vec3_t {
  f32 x;
  f32 y;
  f32 z;
} nh_vec3_t;
/* Vector (3D, int) */
typedef struct nh_vec3i_t {
  i32 x;
  i32 y;
  i32 z;
} nh_vec3i_t;

/* Vector (4D, float) */
typedef struct nh_vec4_t {
  f32 x;
  f32 y;
  f32 z;
  f32 w;
} nh_vec4_t;
/* Vector (4D, int) */
typedef struct nh_vec4i_t {
  i32 x;
  i32 y;
  i32 z;
  i32 w;
} nh_vec4i_t;

/* Create a 2D vector */
#define NH_VEC2(x, y)         ((nh_vec2_t){(x), (y)})
/* Create a 2D vector (int) */
#define NH_VEC2I(x, y)        ((nh_vec2i_t){(x), (y)})
/* Create a 3D vector */
#define NH_VEC3(x, y, z)      ((nh_vec3_t){(x), (y), (z)})
/* Create a 3D vector (int) */
#define NH_VEC3I(x, y, z)     ((nh_vec3i_t){(x), (y), (z)})
/* Create a 4D vector */
#define NH_VEC4(x, y, z, w)   ((nh_vec4_t){(x), (y), (z), (w)})
/* Create a 4D vector (int) */
#define NH_VEC4I(x, y, z, w)  ((nh_vec4i_t){(x), (y), (z), (w)})

/* Dot product of two 2D vectors */
#define NH_DOT2(v1, v2)       ((v1).x * (v2).x  \
                              + (v1).y * (v2).y)
/* Dot product of two 3D vectors */
#define NH_DOT3(v1, v2)       ((v1).x * (v2).x  \
                              + (v1).y * (v2).y \
                              + (v1).z * (v2).z)
/* Dot product of two 4D vectors */
#define NH_DOT4(v1, v2)       ((v1).x * (v2).x  \
                              + (v1).y * (v2).y \
                              + (v1).z * (v2).z \
                              + (v1).w * (v2).w)

/* Cross product of two 3D vectors (must be casted) */
#define NH_CROSS3(v1, v2)     ((t){(v1).y * (v2).z - (v1).z * (v2).y, \
                                   (v1).z * (v2).x - (v1).x * (v2).z, \
                                   (v1).x * (v2).y - (v1).y * (v2).x})

/* Add two 2D vectors (must be casted) */
#define NH_ADD2(v1, v2)       ({(v1).x + (v2).x,  \
                              (v1).y + (v2).y})
/* Add two 3D vectors (must be casted) */
#define NH_ADD3(v1, v2)       ({(v1).x + (v2).x,  \
                              (v1).y + (v2).y,    \
                              (v1).z + (v2).z})
/* Add two 4D vectors (must be casted) */
#define NH_ADD4(v1, v2)       ({(v1).x + (v2).x,  \
                              (v1).y + (v2).y,    \
                              (v1).z + (v2).z,    \
                              (v1).w + (v2).w})

/* Add a scalar to a 2D vector (must be casted) */
#define NH_ADD2_S(v, s)       ({(v).x + s, \
                              (v).y + s})
/* Add a scalar to a 3D vector (must be casted) */
#define NH_ADD3_S(v, s)       ({(v).x + s, \
                              (v).y + s,   \
                              (v).z + s})
/* Add a scalar to a 4D vector (must be casted) */
#define NH_ADD4_S(v, s)       ({(v).x + s, \
                              (v).y + s,   \
                              (v).z + s,   \
                              (v).w + s})

/* Multiply a 2D vector by a scalar (must be casted) */
#define NH_MUL2_S(v, s)       ({(v).x * s, \
                              (v).y * s})
/* Multiply a 3D vector by a scalar (must be casted) */
#define NH_MUL3_S(v, s)       ({(v).x * s, \
                              (v).y * s,   \
                              (v).z * s})
/* Multiply a 4D vector by a scalar (must be casted) */
#define NH_MUL4_S(v, s)       ({(v).x * s, \
                              (v).y * s,   \
                              (v).z * s,   \
                              (v).w * s})

/* Functions that require stdlib.h */
#ifdef NH_INCLUDE_STDLIB

/* Length of a 2D vector */
#define NH_LEN2(v)            sqrt(NH_DOT2(v, v))
/* Length of a 3D vector */
#define NH_LEN3(v)            sqrt(NH_DOT3(v, v))
/* Length of a 4D vector */
#define NH_LEN4(v)            sqrt(NH_DOT4(v, v))

/* Normalize a 2D vector */
#define NH_NORMALIZE2(v)      ((nh_vec2_t){(v).x / NH_LEN2(v), \
                              (v).y / NH_LEN2(v)})
/* Normalize a 3D vector */
#define NH_NORMALIZE3(v)      ((nh_vec3_t){(v).x / NH_LEN3(v), \
                              (v).y / NH_LEN3(v), \
                              (v).z / NH_LEN3(v)})
/* Normalize a 4D vector */
#define NH_NORMALIZE4(v)      ((nh_vec4_t){(v).x / NH_LEN4(v), \
                              (v).y / NH_LEN4(v), \
                              (v).z / NH_LEN4(v), \
                              (v).w / NH_LEN4(v)})

#endif

#endif /* NH_VECTOR_H */
