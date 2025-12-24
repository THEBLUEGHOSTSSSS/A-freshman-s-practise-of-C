#include <stdio.h>

int main() {
    int arr[5];  
    
    
    for (int i = 0; i < 5; i++) {
       
        scanf("%d", &arr[i]);
    }
    
    
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    
    for (int i = 0; i < 4; i++) {  
        
        
        for (int j = 0; j < 4 - i; j++) {  
            
           
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
            } 
        }
        
        
        
    }
    
    
    printf("\n排序后的数组(降序):");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}