#include <stdio.h>

// 子函数：逆序输出数组
void reversePrint(int arr[], int size) {
    printf("逆序输出结果为: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numbers[5];
    
    printf("请输入5个不同的整数：\n");
    
    // 输入5个不同的整数
    for (int i = 0; i < 5; i++) {
        printf("请输入第%d个整数: ", i + 1);
        scanf("%d", &numbers[i]);
        
        // 检查是否重复（可选，根据题目要求）
        for (int j = 0; j < i; j++) {
            if (numbers[i] == numbers[j]) {
                printf("输入重复，请重新输入一个不同的整数: ");
                i--;  // 重新输入当前这个位置
                break;
            }
        }
    }
    
    printf("\n原始数组: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // 调用子函数逆序输出
    reversePrint(numbers, 5);
    
    return 0;
}