#include <stdio.h>

#define MAX_N 100  // 假设最大维度不超过 100，可视情况调整

int main() {
    int n;
    int matrix[MAX_N][MAX_N]; 


    scanf("%d", &n);

   
    int top = 0;          
    int bottom = n - 1;   
    int left = 0;         
    int right = n - 1;    

    int num = 1;          
    int target = n * n;   

    while (num <= target) {
        for (int i = left; i <= right && num <= target; i++) {
            matrix[top][i] = num++;
        }
        top++; 

        
        for (int i = top; i <= bottom && num <= target; i++) {
            matrix[i][right] = num++;
        }
        right--; 

       
        for (int i = right; i >= left && num <= target; i--) {
            matrix[bottom][i] = num++;
        }
        bottom--; 

        for (int i = bottom; i >= top && num <= target; i--) {
            matrix[i][left] = num++;
        }
        left++; 
    }

 
    if(n>=1&&n<=10)
    {for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            printf("%d", matrix[i][j]);
            
            if (j < n ) {
                printf("\t"); 
            }
        }
        printf("\n"); 
    }
    }
    if(n<1||n>10) 
    {
        printf("Invalid input! n should be between 1 and 10.");
    }
    return 0;
}