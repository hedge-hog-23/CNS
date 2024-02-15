#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *string = malloc(255 * sizeof(char)); // initially 255 => dynamic memory allocation
    scanf("%[^\n]s", string);
    string[strlen(string)] = '\0';  // add a null char at end
    char s[strlen(string) + 1];
    
    //encryption
    
    int ct = 0;
    for (int i = 0; i < strlen(string); i += 2) {
        s[ct] = string[i];
        ct++;
    }

    for (int i = 1; i < strlen(string); i += 2) {
        s[ct] = string[i];
        ct++;
    }

    s[ct] = '\0';

    printf("Encrypted string : %s\n", s);


    // Decryption
    
    int ct1 = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (i % 2 == 0)
            string[ct1] = s[i];
        ct1+=2;
    }

    for (int i = 1; i < strlen(s); i++) {
        if (i % 2 == 1){
            string[ct1] = s[i];
        ct1+=2;
        }
    }

    // string[ct1] = '\0';

    printf("Decrypted string : %s\n", string);
}
