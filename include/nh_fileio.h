/* Include guard */
#ifndef NH_FILEIO_H
#define NH_FILEIO_H

/* Project headers */
#include "nh_base.h"

/* Needs stdlib */
#ifndef NH_INCLUDE_STDLIB
#error "Requires the C stdlibrary. To allow include, define NH_INCLUDE_STDLIB."
#else

/* Stdlib headers */
#include <stdio.h>

/* Get file size (+1 for null-terminator) */
usize nh_file_size(const char *path) {
  usize size = 0;
  FILE *file = fopen(path, "r");
  NH_ASSERT(file);
  fseek(file, 0, SEEK_END);
  size = ftell(file) + 1;
  fseek(file, 0, SEEK_SET);
  return size;
}
/* Read full file into buffer (with null terminator) */
usize nh_read_file(const char *path, u8 *buffer) {
  usize size = 0;
  FILE *file = fopen(path, "r");
  NH_ASSERT(file);
  fseek(file, 0, SEEK_END);
  size = ftell(file);
  fseek(file, 0, SEEK_SET);
  if (buffer) {
    NH_ASSERT((unsigned long)size == fread(buffer, 1, size, file));
    buffer[size] = '\0';
  }
  fclose(file);
  return size + 1;
}
/* Write full buffer to file */
void nh_write_file(const char *path, const u8 *buffer, usize size) {
  FILE *file = fopen(path, "w");
  NH_ASSERT(file);
  NH_ASSERT(fwrite(buffer, 1, size, file));
  fclose(file);
}
/* Append full buffer to file */
void nh_append_file(const char *path, const u8 *buffer, usize size) {
  FILE *file = fopen(path, "a");
  NH_ASSERT(file);
  NH_ASSERT(fwrite(buffer, 1, size, file));
  fclose(file);
}

#endif /* NH_INCLUDE_STDLIB */
#endif /* NH_FILEIO_H */
