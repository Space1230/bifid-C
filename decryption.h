#include "hashmap.h"
#include "main.h"

/*
** do decryption logic
**
** basically, we need to do the reverse.
**
** we need to put the key into the hashmap (easy)
** we need to transform the string into locs (easy)
** we may need a new process locs function (unknown)
** we need to tranform the locs into string (easy)
**
** 0123456789 <- plain text
**
** 0 2 4 6 8
** 1 3 5 7 9
**
** 0246813579 <- cyphertext
**
** height = index
** width = index + 5
*/

void decryption_process_locs(square_location *locs, int loc_size,
                  square_location *new_locs) {

  int* flat_locs = (int*) locs;

  for (int i = 0; i < loc_size; i++) {
    new_locs[i].height = flat_locs[i];
    new_locs[i].width = flat_locs[i + loc_size];
  }
}

// maybe rename this
// this is kinda parsing locs from the string
// all this code is shared with the enrypter
//
// or we could just not care...

void decrypt(char *n_plaintext, int n_plaintext_len, char* n_key, int n_key_len, char *n_cyphertext, int n_cyphertext_len) {
    // TODO ensure lengths

    hashmap_entry* hashmap = NULL;
    hashmap_fill(&hashmap, n_key, n_key_len);


    square_location locs[BLOCK_SIZE];
    int locs_index = 0;
    square_location new_locs[BLOCK_SIZE];

    int plaintext_index = 0;

    for (int i = 0; i < n_cyphertext_len; i++) {
      // process each block
      if (locs_index == BLOCK_SIZE) {
        decryption_process_locs(locs, BLOCK_SIZE, new_locs);

        // save new locs to the cyphertext
        for (int j = 0; j < BLOCK_SIZE; j++) {
            char item = hashmap_get_key_at_location(hashmap, new_locs[j]);
            n_plaintext[plaintext_index++] = item;
        }

        locs_index = 0;
      }

      // get rid of unwanted chars and lowercase stuff
      char parsed_char = parse_char(n_cyphertext[i]);
      if (parsed_char == ' ')
        continue;

      // get the location of the char
      square_location loc = hashmap_get_location(hashmap, parsed_char);
      locs[locs_index++] = loc;
    }

    int loc_size = locs_index; // this is because of ++, this is here for clarity

    // add the loc stragglers
    decryption_process_locs(locs, loc_size, new_locs);

    for (int i = 0; i < loc_size; i++) {
        char item = hashmap_get_key_at_location(hashmap, new_locs[i]);
        n_plaintext[plaintext_index++] = item;
    }

    // ending the string
    n_plaintext[plaintext_index] = '\0';
}
