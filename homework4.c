#include <stdio.h>

// 函数声明
int Fun(const char *ss, char ch);

int main() {
    char str[100];
    char target;
    
    printf("请输入字符串: ");
    fgets(str, sizeof(str), stdin);
    
    printf("请输入要查找的字符: ");
    scanf("%c", &target);
    
    int count = Fun(str, target);
    printf("字符 '%c' 在字符串中出现了 %d 次\n", target, count);
    
    return 0;
}

// 函数定义：统计字符串中指定字符的个数
int Fun(const char *ss, char ch) {
    int count = 0;
    
    // 遍历字符串直到遇到结束符 '\0'
    while (*ss != '\0') {
        if (*ss == ch) {
            count++;
        }
        ss++;  // 移动到下一个字符
    }
    
    return count;
}