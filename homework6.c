#include <stdio.h>

// 统计字符串长度的函数
int len(char str[]) {
    int length = 0;
    
    // 遍历字符串，直到遇到结束符'\0'
    while (str[length] != '\0') {
        length++;
    }
    
    return length;
}

int main() {
    char str[100];  // 定义一个字符数组来存储字符串
    
    printf("请输入一个字符串：");
    
    // 从键盘输入字符串
    // 使用fgets可以安全读取字符串，避免缓冲区溢出
    fgets(str, sizeof(str), stdin);
    
    // 去除可能读取的换行符
    int i = 0;
    while (str[i] != '\n' && str[i] != '\0') {
        i++;
    }
    if (str[i] == '\n') {
        str[i] = '\0';
    }
    
    // 调用len函数统计字符串长度
    int length = len(str);
    
    // 输出统计结果
    printf("字符串的长度为：%d\n", length);
    
    return 0;
}