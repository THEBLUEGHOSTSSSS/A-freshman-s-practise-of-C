#include <stdio.h>

int main() {
    int digits[] = {2, 5, 7, 9};
    int count = 0;
    
    printf("由数字2、5、7、9组成的三位数有：\n");
    printf("--------------------------------\n");
    
    // 三层循环分别表示百位、十位、个位
    for (int i = 0; i < 4; i++) {           // 百位
        for (int j = 0; j < 4; j++) {       // 十位
            if (j == i) continue;          // 十位不能与百位相同
            for (int k = 0; k < 4; k++) {   // 个位
                if (k == i || k == j) continue; // 个位不能与百位或十位相同
                
                // 组成三位数
                int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                count++;
                
                // 输出，每行显示6个数字
                printf("%4d", num);
                if (count % 6 == 0) {
                    printf("\n");
                }
            }
        }
    }
    
    printf("\n--------------------------------\n");
    printf("总共有 %d 个互不相同且无重复的三位数\n", count);
    
    return 0;
}