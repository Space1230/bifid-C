/*
** This is a wrapper around the notings hashmap
*/
#include <stdio.h>
#include "stb_ds.h"
#include "char_utils.h"

#ifndef ENCRYPTION_HASHMAP_H_
#define ENCRYPTION_HASHMAP_H_

// location (stores where it is in the table)
typedef struct {
  int height;
  int width;
} square_location;

void square_location_print(square_location loc);

// hashmap entry
typedef struct {
  char key;
  square_location loc;
} hashmap_entry;

// hashmap functions are implemented in the c file to prevent problems
// with importing our header only library

// hashmap is a double ptr, because we want to modify the ptr in main
// but our key doesn't change
void hashmap_fill(hashmap_entry **hashmap, const char* key, int key_length);
void hashmap_print(const hashmap_entry *hashmap);
square_location hashmap_get_location(hashmap_entry* hashmap, char key);
char hashmap_get_key_at_location(hashmap_entry *hashmap, square_location loc);

#endif // ENCRYPTION_HASHMAP_H_
