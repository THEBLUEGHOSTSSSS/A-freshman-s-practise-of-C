#include <stdio.h>

int main() {
    int numbers[7];
    
    // 输入7个整数
    for (int i = 0; i < 7; i++) {
        scanf("%d", &numbers[i]);
    }
    
    // 查找最大值和最小值的位置
    int max_index = 0, min_index = 0;
    for (int i = 1; i < 7; i++) {
        if (numbers[i] > numbers[max_index]) {
            max_index = i;
        }
        if (numbers[i] < numbers[min_index]) {
            min_index = i;
        }
    }
    
    // 交换最小值和第一个数
    if (min_index != 0) {
        int temp = numbers[0];
        numbers[0] = numbers[min_index];
        numbers[min_index] = temp;
        
        // 如果最大值在位置0，更新其位置
        if (max_index == 0) {
            max_index = min_index;
        }
        // 如果最大值在min_index位置，更新其位置
        else if (max_index == min_index) {
            max_index = 0;
        }
    }
    
    // 交换最大值和最后一个数
    if (max_index != 6) {
        int temp = numbers[6];
        numbers[6] = numbers[max_index];
        numbers[max_index] = temp;
    }
    
    // 输出最终结果
    for (int i = 0; i < 7; i++) {
        printf("%d ", numbers[i]);
    }
    
    return 0;
}