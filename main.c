#include <stdio.h>

#include "encryption.h"
#include "decryption.h"

char test_key[] = "Phqgm Eayln Ofdxk Rcvsz Wbuti...////";
int test_key_len = sizeof(test_key) / sizeof(char);

char test_plaintext[] = "defend the east wall of the castle";
char test_plaintext_len = sizeof(test_plaintext) / sizeof(char);

hashmap_entry* hashmap = NULL;

/*
 * pass the plaintext and key for encryption
 * pass the cyphertext and key for decryption
 *
 * use argp
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
