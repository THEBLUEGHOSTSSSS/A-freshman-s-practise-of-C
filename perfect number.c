#include <stdio.h>

#define MAX_FACTORS 100  

int main() {
    int factors[MAX_FACTORS];  
    int factor_count;

   
    
    for (int num = 2; num <= 1000; num++) {
        int sum = 0;
        factor_count = 0;
        
        
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                factors[factor_count++] = i;
                sum += i;
            }
        }
        
        
        if (sum == num) {
            printf("%d=", num);
    
            for (int i = 0; i < factor_count; i++) {
               if (i > 0) printf(" + ");
                printf("%d", factors[i]);
            }
            printf("\n");
            

            
        }
    }
    
    return 0;
}