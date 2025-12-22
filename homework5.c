#include <stdio.h>
#include <ctype.h>

// 子函数：实现字母大小写转换
char convertCase(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        // 大写字母转小写
        return ch + ('a' - 'A');
    } else if (ch >= 'a' && ch <= 'z') {
        // 小写字母转大写
        return ch - ('a' - 'A');
    } else {
        // 如果不是字母，原样返回
        return ch;
    }
}

int main() {
    char letters[6];
    int isValid = 1; // 假设输入有效
    
    // 输入6个字符
    for (int i = 0; i < 6; i++) {
        scanf("%c", &letters[i]);
    }
    
    // 检查所有字符是否都是字母
    for (int i = 0; i < 6; i++) {
        if (!isalpha(letters[i])) {
            isValid = 0; // 发现非字母字符
            break;
        }
    }
    
    if (isValid) {
        // 转换并输出结果
        for (int i = 0; i < 6; i++) {
            printf("%c", convertCase(letters[i]));
        }
        printf("\n");
    } else {
        // 输出错误信息
        printf("输入的字符不满足要求\n");
    }
    
    return 0;
}