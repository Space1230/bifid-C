#include "hashmap.h"

#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

int max_height = 5;
int max_width = 5;

void square_location_print(square_location loc) {
    printf("height: %d, width: %d\n", loc.height, loc.width);
}

// hashmap is a double ptr, because we want to modify the ptr in main
// but our key doesn't change
void hashmap_fill(hashmap_entry **hashmap, const char* key, int key_length) {
  hashmap_entry current_entry;

  int height = 1;
  int width = 1;

  for (int i = 0; i < key_length; i++) {
      char parsed_char = parse_char(key[i]);

      // get rid of invalid char
      if (parsed_char == ' ') continue;

      // calculate flattened index of key
      int key_index = max_width * (height - 1) + (width - 1);

      // creates new entry
      hashmap_entry entry = {parsed_char, {height, width}};

      // adds entry to hashmap
      hmputs(*hashmap, entry);


      // looping our height and width
      if (width == max_width) {
        height++;
        width = 1;
      } else {
          width++;
      }
  }
}

void hashmap_print(const hashmap_entry *hashmap) {
  for (int i = 0; i < hmlen(hashmap); i++) {
      printf("height: %d, width: %d, key: %c\n", hashmap[i].loc.height, hashmap[i].loc.width, hashmap[i].key);
  }
}

square_location hashmap_get_location(hashmap_entry* hashmap, char key) {
    return hmgets(hashmap, key).loc;
}

char hashmap_get_key_at_location(hashmap_entry *hashmap, square_location loc) {
  int key_index = max_width * (loc.height - 1) + (loc.width - 1);
  return hashmap[key_index].key;
}
