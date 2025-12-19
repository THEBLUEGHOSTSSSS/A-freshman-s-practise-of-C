#include <stdio.h>

int main() {
    float scores[5];
    float sum = 0, max, min, average;
    int i;
    
   
    scanf("%f", &scores[0]);
    
    max = min = scores[0];
    sum = scores[0];
    

    for (i = 1; i < 5; i++) {
      
        scanf("%f", &scores[i]);
        
        sum += scores[i];  
        
     
        if (scores[i] > max) {
            max = scores[i];
        }
        
        
        if (scores[i] < min) {
            min = scores[i];
        }
    }
    
   
    sum = sum - max - min;
    average = sum / 3;  
    

    
    
    
    printf("%.0f\n", average);
    
    return 0;
}