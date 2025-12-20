#include<stdio.h>

void write() {
    
    FILE *fp = fopen("abc.txt", "w");  
    if (fp == NULL) {
        return;  
    }
    
    
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        fputc(ch, fp);
    }
    
    fclose(fp);  
}

void read() {
    
    FILE *fp = fopen("abc.txt", "r");  
    if (fp == NULL) {
        return;  
    }
    
    
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    
    fclose(fp);  
}

int main() {   
    write();  
    read();   
    return 0;
}