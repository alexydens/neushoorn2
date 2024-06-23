/* Include guard */
#ifndef NH_STRING_H
#define NH_STRING_H

/* Project headers */
#include "nh_base.h"
#include "nh_arena.h"
#include "nh_memory.h"
#ifdef NH_INCLUDE_STDLIB
#include "nh_fileio.h"
#endif

/* String view struct */
typedef struct nh_str_t {
  u8 *start;
  usize size;
} nh_str_t;

/* Create a string view from a literal */
static nh_str_t nh_str_create(nh_arena_t *arena, const char *cstr) {
  nh_str_t str;
  usize size = 0;
  char *curr = (char*)cstr;
  while (*curr) {
    size++;
    curr++;
  }
  str.start = nh_arena_alloc(arena, size + 1);
  str.size = size + 1;
  curr = (char*)cstr;
  for (usize i = 0; i < size; i++) {
    str.start[i] = *curr;
    curr++;
  }
  str.start[size] = 0;
  return str;
}
/* Create a char * from a string view */
static char *nh_str_to_cstr(nh_arena_t *arena, nh_str_t str) {
  char *cstr = (char *)nh_arena_alloc(arena, str.size + 1);
  for (usize i = 0; i < str.size; i++) {
    cstr[i] = str.start[i];
  }
  cstr[str.size] = 0;
  return cstr;
}
#ifdef NH_INCLUDE_STDLIB
/* Create a string view with the contents of a file */
static nh_str_t nh_str_from_file(nh_arena_t *arena, const char *path) {
  nh_str_t str;
  usize size = nh_file_size(path);
  str.start = nh_arena_alloc(arena, size);
  NH_ASSERT(size == nh_read_file(path, str.start));
  return str;
}
#endif
/* Create 1 string view by copying another */
static nh_str_t nh_str_copy(nh_arena_t *arena, nh_str_t str) {
  nh_str_t copy;
  copy.start = nh_arena_alloc(arena, str.size);
  copy.size = str.size;
  for (usize i = 0; i < str.size; i++) {
    copy.start[i] = str.start[i];
  }
  return copy;
}
/* Concatenate 2 string views to form a new one */
static nh_str_t nh_str_cat(nh_arena_t *arena, nh_str_t str1, nh_str_t str2) {
  nh_str_t str;
  str.size = str1.size + str2.size;
  str.start = nh_arena_alloc(arena, str.size);
  for (usize i = 0; i < str1.size; i++) {
    str.start[i] = str1.start[i];
  }
  for (usize i = 0; i < str2.size; i++) {
    str.start[i + str1.size] = str2.start[i];
  }
  return str;
}

/* Split a string view into multiple string views */
static nh_str_t *nh_str_split(nh_arena_t *arena, nh_str_t str, u8 delim) {
  usize count = 0;
  for (usize i = 0; i < str.size; i++) {
    if (str.start[i] == delim) {
      count++;
    }
  }
  nh_str_t *result =
    (nh_str_t*)nh_arena_alloc(arena, sizeof(nh_str_t) * (count + 1));
  usize count2 = 0;
  for (usize i = 0; i < str.size; i++) {
    if (str.start[i] == delim) {
      result[count2].start = str.start;
      result[count2].size = i;
      count2++;
      str.start += i + 1;
      i = 0;
    }
  }
  result[count2].start = str.start;
  result[count2].size = str.size;
  return result;
}

/* Check if two string views contain the same data */
static bool nh_str_eq(nh_str_t str1, nh_str_t str2) {
  if (str1.size != str2.size) {
    return false;
  }
  for (usize i = 0; i < str1.size; i++) {
    if (str1.start[i] != str2.start[i]) {
      return false;
    }
  }
  return true;
}

/* Check if str2 is in str1 in any position */
static bool nh_str_in(nh_str_t str1, nh_str_t str2) {
  for (usize i = 0; i <= str1.size - str2.size; i++) {
    nh_str_t str;
    str.start = str1.start + i;
    str.size = str2.size;
    if (nh_str_eq(str, str2)) {
      return true;
    }
  }
  return false;
}

/* Convert all characters in a string to uppercase */
static void nh_str_to_upper(nh_str_t *str) {
  for (usize i = 0; i < str->size; i++) {
    if (str->start[i] >= 'a' && str->start[i] <= 'z') {
      str->start[i] -= 'a' - 'A';
    }
  }
} 
/* Convert all characters in a string to lowercase */
static void nh_str_to_lower(nh_str_t *str) {
  for (usize i = 0; i < str->size; i++) {
    if (str->start[i] >= 'A' && str->start[i] <= 'Z') {
      str->start[i] += 'a' - 'A';
    }
  }
}

#endif /* NH_STRING_H */
