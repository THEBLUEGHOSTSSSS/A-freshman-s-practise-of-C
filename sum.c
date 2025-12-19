#include <stdio.h>


int sum(int n);

int main() {
    int n;
    

    
    scanf("%d", &n);
    

    if (n < 1) {
        printf("输入必须为正整数！\n");
        return 1;
    }
    
    
    int result = sum(n);
    printf(" %d\n",  result);
    
    return 0;
}


int sum(int n) {
    int total = 0;
    int i = 2; 
    
    
    if (i <= n) {
        do {
            total += i; 
            i += 2;     
    }while(i<=n);
    
    return total;
}
}