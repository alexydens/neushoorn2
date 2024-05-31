/* Include guard */
#ifndef NH_MEMORY_H
#define NH_MEMORY_H

/* Project headers */
#include "nh_base.h"

/* If stdlib included, just use stdlib versions. Otherwise implement them. */
#ifdef NH_INCLUDE_STDLIB

/* Stdlib headers */
#include <string.h>
/* Set size bytes of memory to val */
#define nh_memset(ptr, val, size)    memset(ptr, val, size)
/* Copy size bytes of memory from src to dest */
#define nh_memcpy(dest, src, size)   memcpy(dest, src, size)

#else
/* Set size bytes of memory to val */
void *nh_memset(void *ptr, u8 val, usize size) {
  u8 *curr = (u8*)ptr;
  for (usize i = 0; i < size; i++) {
    curr[i] = val;
  }
  return ptr;
}
/* Copy size bytes of memory from src to dest */
void *nh_memcpy(void *dest, const void *src, usize size) {
  u8 *curr_dest = (u8*)dest;
  const u8 *curr_src = (const u8*)src;
  for (usize i = 0; i < size; i++) {
    curr_dest[i] = curr_src[i];
  }
  return dest;
}
#endif

#endif /* NH_MEMORY_H */
