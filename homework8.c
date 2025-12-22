#include <stdio.h>
#include <string.h>
// 使用指针的字符串连接函数
void strcat_pointer(char *dest, char *src) {
    // 移动dest指针到字符串末尾
    while (*dest != '\0') {
        dest++;
    }
    
    // 复制src到dest末尾
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    
    // 添加结束符
    *dest = '\0';
}

int main() {
    char str1[100], str2[100];
    
    printf("请输入第一个字符串：");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    
    printf("请输入第二个字符串：");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';
    
    // 调用指针版本的连接函数
    strcat_pointer(str1, str2);
    
    printf("连接后的字符串：%s\n", str1);
    
    return 0;
}