#include <stdio.h>

int main() {
    int score;
    
    
    scanf("%d", &score);
    
    // 验证成绩范围
    if (score < 0 || score > 100) {
        printf("Score is error!\n");
        return 1;
    }
    
    // 使用switch语句判断等级
    char grade;
    switch (score / 10) {
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'E';
            break;
    }
    
    printf("%c\n", grade);
    
    return 0;
}