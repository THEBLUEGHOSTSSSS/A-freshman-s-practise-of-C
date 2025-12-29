#include <stdio.h>
#include <string.h>

int main() {
    char strings[3][100];
    char max_str[100];
    
    // 输入三个字符串
    for (int i = 0; i < 3; i++) {
        printf("请输入第%d个字符串：", i + 1);
        fgets(strings[i], sizeof(strings[i]), stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0'; // 去除换行符
    }
    
    // 初始化最大字符串为第一个字符串
    strcpy(max_str, strings[0]);
    
    // 比较找出最大字符串
    for (int i = 1; i < 3; i++) {
        if (strcmp(strings[i], max_str) > 0) {
            strcpy(max_str, strings[i]);
        }
    }
    
    printf("最大的字符串是：%s\n", max_str);
    
    return 0;
}