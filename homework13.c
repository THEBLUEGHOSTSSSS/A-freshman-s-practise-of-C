#include <stdio.h>

int main() {
    int arr[5];  
    int i, j, min_index, temp;
    
   
    for (i = 0; i < 5; i++) {
        
        scanf("%d", &arr[i]);
    }
    
    
    
    for (i = 0; i < 4; i++) {  
        min_index = i; 
        
       
        for (j = i + 1; j < 5; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        if (min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
        
        
        
   
   
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}