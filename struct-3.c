#include <stdio.h>
#include <string.h>


struct Student {
    char name[21]; 
    int lang_score; 
    int data_score; 
    int algo_score; 
};

int main() {
    
    struct Student current_student;
    
    
    int max_score = -1; 
  
    char winner_name[21] = ""; 

    
    while (scanf("%s %d %d %d", 
                  current_student.name, 
                  &current_student.lang_score, 
                  &current_student.data_score, 
                  &current_student.algo_score) == 4) 
    {
       
        int current_total_score = current_student.lang_score + 
                                  current_student.data_score + 
                                  current_student.algo_score;

        
        if (current_total_score > max_score) {
            max_score = current_total_score;
           strcpy(winner_name, current_student.name);
        }
    }

  
    if (winner_name[0] != '\0') {
        printf("%s\n", winner_name);
    }

    return 0;
}