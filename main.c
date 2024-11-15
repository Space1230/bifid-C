#include <stdio.h>

#include "encryption.h"

char test_key[] = "Phqgm Eayln Ofdxk Rcvsz Wbuti...////";
int test_key_len = sizeof(test_key) / sizeof(char);

char test_plaintext[] = "defend the east wall of the castle";
char test_plaintext_len = sizeof(test_plaintext) / sizeof(char);

hashmap_entry* hashmap = NULL;

/*
** do encryption logic
*/


int main() {
    char cyphertext[test_plaintext_len];
    encrypt(test_plaintext, test_plaintext_len, test_key, test_key_len, cyphertext);
    printf("%s\n", cyphertext);

}
