#include <stdio.h>

// 函数声明
double calculateSum(int n);

int main() {
    int n;
    double result;
    
    // 输入n
   
    scanf("%d", &n);
    
    // 验证输入
    if (n <= 0) {
        printf("错误：请输入一个正整数！\n");
        return 1;
    }
    
    // 调用计算函数
    result = calculateSum(n);
    
    // 输出结果
    printf("%.6f\n", result);
    
    return 0;
}

// 计算函数：根据n的奇偶性计算不同的和
double calculateSum(int n) {
    double sum = 0.0;
    
    if (n % 2 == 0) {  // n为偶数
        printf("1/2＋1/4＋…＋1/%d=", n);
        for (int i = 2; i <= n; i += 2) {
            sum += 1.0 / i;
            
        }
    } else {  // n为奇数
        printf("1/1＋1/3＋…＋1/%d=", n);
        for (int i = 1; i <= n; i += 2) {
            sum += 1.0 / i;
            
        }
    }
    
    return sum;
}