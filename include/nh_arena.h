/* Include guard */
#ifndef NH_ARENA_H
#define NH_ARENA_H

/* Project headers */
#include "nh_base.h"

/* A linear allocator type */
typedef struct nh_arena_t {
  u8 *start;
  u8 *current;
  usize size;
} nh_arena_t;

/*
 * Create a linear allocator:
 * - size: the size, in bytes, of the allocator.
 * - start: the starting address of a pre-allocated buffer for it.
 */
static nh_arena_t nh_arena_create(usize size, u8 *start) {
  nh_arena_t arena;
  NH_ASSERT(start);
  NH_ASSERT(size);
  arena.start = start;
  arena.size = size;
  arena.current = start;
  return arena;
}
/* Free a linear allocator */
static void nh_arena_free(nh_arena_t *arena) {
  NH_ASSERT(arena);
  arena->start = NULL;
  arena->current = NULL;
  arena->size = 0;
}
/* Allocate size bytes on a linear allocator (if out of memory, return NULL) */
static u8 *nh_arena_alloc(nh_arena_t *arena, usize size) {
  u8 *result;
  NH_ASSERT(arena);
  NH_ASSERT(size);
  if (arena->current + size > arena->start + arena->size) {
    return NULL;
  }
  result = arena->current;
  arena->current += size;
  return result;
}

#endif /* NH_ARENA_H */
