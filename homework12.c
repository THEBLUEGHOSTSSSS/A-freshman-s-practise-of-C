#include <stdio.h>

int main() {

    int numbers[] = {3, -30, 20, 6, 77, 2, 0, -4, -7, 99};
    int count = sizeof(numbers) / sizeof(numbers[0]);  
    
    int max = numbers[0];
    int min = numbers[0];
    
  
    for (int i = 1; i < count; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    
    // 输出结果
    printf("最大值：%d\n", max);
    printf("最小值：%d\n", min);
    
    return 0;
}