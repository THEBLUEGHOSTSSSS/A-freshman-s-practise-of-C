#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(int n);
void clearInputBuffer();

int main() {
    int number;
    char choice;
    
    printf("==========Factorial Calculator==========\n");
    
    do {
        printf("\nPlease enter a non-negative integer (0-20): ");
        if (scanf("%d", &number) != 1) {
            printf("ERROR! Your number is not valid\n");
            clearInputBuffer();
            continue;
        }
        
        if (number < 0) {
            printf("Error: Factorial can only be calculated for non-negative integers!\n");
        } else if (number > 20) {
            printf("Error: Please enter an integer less than or equal to 20 (to prevent overflow)!\n");
        } else {
            unsigned long long result = factorial(number);
            printf("%d! = %llu\n", number, result);
            printf("Computational process: ");
            for (int i = number; i >= 1; i--) {
                printf("%d", i);     
                if (i > 1) {
                    printf(" x ");
                }
            }
            printf(" = %llu\n", result);
        }
        
        printf("Do you want to continue the calculation? (Y/N): ");
        scanf(" %c", &choice);
        clearInputBuffer();
        
    } while (choice == 'Y' || choice == 'y');  
    
    printf("\nThank you for using the factorial calculator!\n");
    return 0;
}

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        
    }
    
}