/* Include guard */
#ifndef NH_TYPES_H
#define NH_TYPES_H

/* If using stdlib headers */
#ifdef NH_INCLUDE_STDLIB
/* Stdlib headers */
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
/* Unsigned integers */
typedef uint8_t             u8;
typedef uint16_t            u16;
typedef uint32_t            u32;
typedef uint64_t            u64;
typedef size_t              usize;
/* Signed integers */
typedef int8_t              i8;
typedef int16_t             i16;
typedef int32_t             i32;
typedef int64_t             i64;
typedef i64                 isize;
#else
/* Unsigned integers */
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;
typedef u64                 usize;
/* Signed integers */
typedef signed char         i8;
typedef signed short        i16;
typedef signed int          i32;
typedef signed long long    i64;
typedef i64                 isize;
/* Booleans */
typedef u8                  bool;
#define true                1
#define false               0
#endif

/* Floats */
typedef float               f32;
typedef double              f64;

#endif /* NH_TYPES_H */
