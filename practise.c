#include<stdio.h>
#include<string.h>
char *str_reverse(char *str) {
    int n = strlen(str);
    for(int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    return str;
}
#define MAXTITL 41
#define MAXAUTL 31
int main() {
    char title[MAXTITL];
    char author[MAXAUTL];
    printf("Enter book title: ");
    fgets(title, MAXTITL, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character
    printf("Enter author name: ");
    fgets(author, MAXAUTL, stdin);
    author[strcspn(author, "\n")] = 0; // Remove newline character
    str_reverse(title);
    str_reverse(author);
    printf("Reversed Title: %s\n", title);
    printf("Reversed Author: %s\n", author);
    return 0;
}