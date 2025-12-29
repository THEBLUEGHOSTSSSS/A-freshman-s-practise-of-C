#include <stdio.h>


int find_max_recursive(int num, int current_max) {
 
    if (num == 0) {
        return current_max;
    }
    
    int digit = num % 10;
    
    
    if (digit > current_max) {
        current_max = digit;
    }
    

    return find_max_recursive(num / 10, current_max);
}

int main() {
    int num, max_digit;
    
    
    scanf("%d", &num);
    

    if (num < 0) {
        num = -num;
    }
    
    if (num == 0) {
        max_digit = 0;
    } else {
        
        int initial_max = num % 10;
        max_digit = find_max_recursive(num / 10, initial_max);
    }
    
     printf("数%d的位数中最大的为：%d\n", num, max_digit);
    
    return 0;
}