#include <stdio.h>

#include "encryption.h"
#include "decryption.h"

char test_key[] = "Phqgm Eayln Ofdxk Rcvsz Wbuti...////";
int test_key_len = sizeof(test_key) / sizeof(char);

char test_plaintext[] = "defend the east wall of the castle";
char test_plaintext_len = sizeof(test_plaintext) / sizeof(char);

hashmap_entry* hashmap = NULL;

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


int main() {
    char cyphertext[test_plaintext_len];
    encrypt(test_plaintext, test_plaintext_len, test_key, test_key_len, cyphertext);
    printf("%s\n", cyphertext);

    printf("\nnow onto decoding\n");

    char decrypted_text[test_plaintext_len];
    decrypt(decrypted_text, test_plaintext_len, test_key, test_key_len, cyphertext, test_plaintext_len);

    printf("%s\n", decrypted_text);
}
