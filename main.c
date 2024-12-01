#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

        char plaintext[512];
        printf("Please enter the text to encrypt: (512 character limit, no spaces) \n");
        scanf("%s", plaintext);
        int plaintext_len = strlen(plaintext);

        char key[26]; // = "PhqgmEaylnOfdxkRcvszWbuti...////"
        printf("Please enter the encryption key: (no spaces) \n");
        scanf("%s", key);
        int key_len = strlen(key);

        if (key_len < 25) {
            // the key is too short, add the rest of the alphabet to the end in alphabetical order
            char alphabet[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
            int alphabetlen = sizeof(alphabet) / sizeof(char);
            for (int i = 0; i < key_len; i++) {
                // find the index of the current character in alphabet
                int j=0;
                while((j<alphabetlen) && (alphabet[j] != key[i])) j++;

                // shift all elements of alphabet up to overwrite the current character
                // this makes sure a duplicate is not added with the other missing characters
                for (int k = j; k < alphabetlen-1; k++) { 
                    alphabet[k] = alphabet[k + 1];
                }
            }
            strcat(key, alphabet);
            key_len = strlen(key);
            printf("Key too short. Supplemented key: %s\n", key);
        }

        int BLOCK_SIZE;
        printf("Please enter the integer period: \n");
        scanf("%d", &BLOCK_SIZE);

        char cyphertext[plaintext_len];

        encrypt(plaintext, plaintext_len, key, key_len, cyphertext, BLOCK_SIZE);

    } else if (mode == 'd') {
        printf("Decrypting\n");

        char cyphertext[512];
        printf("Please enter the cypher to decrypt: (512 character limit, no spaces) \n");
        scanf("%s", cyphertext);
        int cyphertext_len = strlen(cyphertext);

        char key[26];
        printf("Please enter the decryption key: (no spaces) \n");
        scanf("%s", key);
        int key_len = strlen(key);

        if (key_len < 25) {
            // the key is too short, add the rest of the alphabet to the end in alphabetical order
            char alphabet[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
            int alphabetlen = sizeof(alphabet) / sizeof(char);
            for (int i = 0; i < key_len; i++) {
                // find the index of the current character in alphabet
                int j=0;
                while((j<alphabetlen) && (alphabet[j] != key[i])) j++;

                // shift all elements of alphabet up to overwrite the current character
                // this makes sure a duplicate is not added with the other missing characters
                for (int k = j; k < alphabetlen-1; k++) { 
                    alphabet[k] = alphabet[k + 1];
                }
            }
            strcat(key, alphabet);
            key_len = strlen(key);
            printf("Key too short. Supplemented key: %s\n", key);
        }

        int BLOCK_SIZE;
        printf("Please enter the integer period: \n");
        scanf("%d", &BLOCK_SIZE);

        char decrypted_text[cyphertext_len];

        decrypt(decrypted_text, key, key_len, cyphertext, cyphertext_len, BLOCK_SIZE);
        printf("%ld\n", strlen(cyphertext));

        printf("%s\n", decrypted_text);
    }
}
