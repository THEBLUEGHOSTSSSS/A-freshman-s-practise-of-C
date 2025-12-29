#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
void encrypt(char str[], int key) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i])) {
            char base = islower(str[i]) ? 'a' : 'A';
            str[i] = (str[i] - base + key) % 26 + base;
        }
    }
}
void decrypt(char str[], int key) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i])) {
            char base = islower(str[i]) ? 'a' : 'A';
            str[i] = (str[i] - base - key + 26) % 26 + base;
        }
    }
}
int main() {
    char str[MAX];
    int key, choice;
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character
    printf("Enter key (shift value): ");
    scanf("%d", &key);
    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);
    if(choice == 1) {
        encrypt(str, key);
        printf("Encrypted string: %s\n", str);
    } else if(choice == 2) {
        decrypt(str, key);
        printf("Decrypted string: %s\n", str);
    } else {
        printf("Invalid choice!\n");
    }
    return 0;
}
