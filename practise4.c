#include <stdio.h>

void exchange(int total) {
    int count = 0;
    
    printf("%d元人民币兑换方案（1元、2元、5元）：\n", total);
    printf("===========================================\n");
    
    // 遍历所有可能的5元数量
    for (int z = 0; z <= total / 5; z++) {
        int after_five = total - 5 * z;
        
        // 遍历所有可能的2元数量
        for (int y = 0; y <= after_five / 2; y++) {
            int x = after_five - 2 * y;  // 1元数量
            
            count++;
            printf("方案%2d: ", count);
            
            // 美化输出，只显示非零面额
            int first = 1;
            if (z > 0) { printf("%d张5元", z); first = 0; }
            if (y > 0) { 
                if (!first) printf(" + ");
                printf("%d张2元", y); 
                first = 0;
            }
            if (x > 0) { 
                if (!first) printf(" + ");
                printf("%d张1元", x); 
            }
            
            printf(" = %d元\n", total);
        }
    }
    
    printf("===========================================\n");
    printf("总共有 %d 种兑换方案\n\n", count);
}

int main() {
    // 兑换10元
    exchange(10);
    
    // 如果需要，也可以兑换其他金额
    // exchange(20);
    
    return 0;
}