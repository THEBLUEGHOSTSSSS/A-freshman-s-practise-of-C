#include <stdio.h>
#include <ctype.h>  // 包含字符分类函数
#include <string.h>

int main() {
    char str[1000];
    int letters = 0, spaces = 0, digits = 0, others = 0;
    
    printf("请输入一个字符串:\n");
    fgets(str, sizeof(str), stdin);
    
    // 移除末尾的换行符
    str[strcspn(str, "\n")] = '\0';
    
    // 使用ctype.h中的函数进行判断
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        
        if (isalpha(ch)) {      // 判断是否为字母
            letters++;
        }
        else if (isdigit(ch)) { // 判断是否为数字
            digits++;
        }
        else if (isspace(ch)) { // 判断是否为空白字符（包括空格、制表符等）
            // 如果是空格字符，但只统计空格
            if (ch == ' ') {
                spaces++;
            } else {
                others++;  // 其他空白字符（制表符、换行符等）
            }
        }
        else {
            others++;
        }
    }
    
    // 输出结果
    printf("\n统计结果:\n");
    printf("英文字母: %d\n", letters);
    printf("数字: %d\n", digits);
    printf("空格: %d\n", spaces);
    printf("其他字符: %d\n", others);
    
    return 0;
}