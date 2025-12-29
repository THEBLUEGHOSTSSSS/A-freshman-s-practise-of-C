#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(NULL));
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;
    int correct_answer = num1 * num2;
    int student_answer;
    
    printf("%d * %d = ?\n", num1, num2);
    
    while (scanf("%d", &student_answer) == 1) {
        if (student_answer == correct_answer) {
            printf("Right!\n");
            break;
        } else {
            printf("Wrong! Please try again.\n");
            printf("%d * %d = ?\n", num1, num2);
        }
    }
    
    return 0;
}