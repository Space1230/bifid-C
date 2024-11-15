
#include "encryption_hashmap.h"

#ifndef ENCRYPTION_H_
#define ENCRYPTION_H_

#define LOCS_LEN 5

square_location test_locs[] = { {0, 1}, {2, 3}, {4, 5}, {6, 7}, {8, 9} };

/*
 * This will turn our block of locs to new locs which we can then
 * use our square on to get our new values
*/
void process_locs(square_location *locs, int loc_size,
                  square_location *new_locs) {

  // for the next math to work, we need to interpret our position
  // in the array as a flat array of ints. Luckily, we can do this
  // in C! Yay!
  int* flat_locs = (int*) locs;

  // for 5 locs, say we have:
  // 0 2 4 6 8
  // 1 3 5 7 9
  //
  // 02468 13579
  //
  // height: 04837 = (index * 4) % 9
  // width: 26159 = (index * 4) + 2 % 9
  //
  // where index is the new number
  //
  // this holds except for the last item in the array,
  // so we need to have an exception at index 4 for width

  // this math is important cause it allows us to skip
  // a for loop (this might not sound like much, but
  // it may be in the future)

  int last_flat_index = loc_size * 2 - 1;
  int last_loc_index = loc_size - 1;

  // It works for 3 items as well
  // 0 2 4
  // 1 3 5
  //
  // 024 135
  //
  // height: 043 = (index * 4) % 5
  // width: 215 = (index * 4) + 2 % 5

  for (int i = 0; i < loc_size; i++) {
    int height_index = (i * 4) % last_flat_index;
    int width_index = ((i * 4) + 2) % last_flat_index;

    if (i == last_loc_index) {width_index = last_flat_index;}

    new_locs[i].height = flat_locs[height_index];
    new_locs[i].width = flat_locs[width_index];
  }
}

void encrypt(char *plaintext, int plaintext_len, char* key, int key_len, char *cyphertext) {
    // TODO ensure lengths

    hashmap_entry* hashmap = NULL;
    hashmap_fill(&hashmap, key, key_len);


    square_location locs[LOCS_LEN];
    int locs_index = 0;
    square_location new_locs[LOCS_LEN];

    int cyphertext_index = 0;

    for (int i = 0; i < plaintext_len; i++) {
      // process each block
      if (locs_index == 5) {
        process_locs(locs, 5, new_locs);

        // save new locs to the cyphertext
        for (int j = 0; j < 5; j++) {
            char item = hashmap_get_key_at_location(hashmap, new_locs[j]);
            cyphertext[cyphertext_index++] = item;
        }

        locs_index = 0;
      }

      // get rid of unwanted chars and lowercase stuff
      char parsed_char = parse_char(plaintext[i]);
      if (parsed_char == ' ')
        continue;

      // get the location of the char
      square_location loc = hashmap_get_location(hashmap, parsed_char);
      locs[locs_index++] = loc;
    }

    int loc_size = locs_index; // this is because of ++, this is here for clarity

    // add the loc stragglers
    process_locs(locs, loc_size, new_locs);

    for (int i = 0; i < loc_size; i++) {
        char item = hashmap_get_key_at_location(hashmap, new_locs[i]);
        cyphertext[cyphertext_index++] = item;
    }

    // ending the string
    cyphertext[cyphertext_index] = '\0';
}

#endif // ENCRYPTION_H_
