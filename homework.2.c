#include <stdio.h>

int main() {
    long long sum = 0;
    long long factorial = 1;  // 0! = 1
    
    printf("计算1到10的阶乘和：\n");
    printf("--------------------\n");
    
    for (int i = 1; i <= 10; i++) {
        factorial *= i;  // i! = (i-1)! * i
        sum += factorial;
        
        printf("%d! = %lld\n", i, factorial);
    }
    
    printf("--------------------\n");
    printf("总和 = %lld\n", sum);
    
    return 0;
}