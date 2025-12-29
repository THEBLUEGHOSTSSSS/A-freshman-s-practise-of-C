#include <stdio.h>


struct Student {
    long id;       
    char name[20]; 
    int score;     
};

int main() {
    
    struct Student student1, student2;
    
   

 
    scanf("%ld %s %d", &student1.id, student1.name, &student1.score);
    
    
    scanf("%ld %s %d", &student2.id, student2.name, &student2.score);
    
   
    if (student1.score >= student2.score) {
        
        printf("%ld %s %d\n", student1.id, student1.name, student1.score);
    } else {
        
        printf("%ld %s %d\n", student2.id, student2.name, student2.score);
    }
    

    
    return 0;
}