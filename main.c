#include <stdio.h>

#include "encryption.h"
#include "decryption.h"

hashmap_entry* hashmap = NULL;

/*
 * pass the plaintext and key for encryption
 * pass the cyphertext and key for decryption
 *
 */


int main() {
    char mode;
    printf("encrypt or dycrypt? (e/d) ");
    scanf("%s", &mode);
    if (mode == 'e') {
        printf("Encrypting: \n");

        char plaintext[];
        printf("Please enter the text to encrypt: \n");
        scanf("%s", &plaintext);
        int plaintext_len = sizeof(plaintext) / sizeof(char);

        char key[26]; // = "Phqgm Eayln Ofdxk Rcvsz Wbuti...////"
        printf("Please enter the encryption key: \n");
        scanf("%s", &key);
        int key_len = sizeof(key) / sizeof(char);

        const int BLOCK_SIZE;
        printf("Please enter the integer period: \n");
        scanf("%d", &BLOCK_SIZE);

        char cyphertext[plaintext_len];

        encrypt(plaintext, plaintext_len, key, key_len, cyphertext, BLOCK_SIZE);
        printf("%s\n", cyphertext);
    } else if (mode == 'd') {
        printf("Decrypting\n");

        char cyphertext[];
        printf("Please enter the cypher to decrypt: \n");
        scanf("%s", &cyphertext);
        int cyphertext_len = sizeof(cyphertext) / sizeof(char);

        char key[26];
        printf("Please enter the decryption key: \n");
        scanf("%s", &key);
        int key_len = sizeof(key) / sizeof(char);

        const int BLOCK_SIZE;
        printf("Please enter the integer period: \n");
        scanf("%d", &BLOCK_SIZE);

        char decrypted_text[cyphertext_len];

        decrypt(decrypted_text, key, key_len, cyphertext, cyphertext_len, BLOCK_SIZE);

        printf("%s\n", decrypted_text);
    }
}
