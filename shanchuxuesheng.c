#include <stdio.h>
#include <string.h>


#define MAX_STUDENTS 50
#define MAX_NAME_LEN 20


struct Student {
    int sno;                      
    char name[MAX_NAME_LEN];     
    int score1;                   
    int score2;                   
    int score3;                   
    int total_score;             
};


void print_all_students(struct Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d %s %d %d %d %d\n", 
               students[i].sno, 
               students[i].name, 
               students[i].score1, 
               students[i].score2, 
               students[i].score3, 
               students[i].total_score);
    }
}


void query_by_name(struct Student students[], int count, const char* target_name) {
    for (int i = 0; i < count; i++) {
       
        if (strcmp(students[i].name, target_name) == 0) {
            printf("%d %s %d %d %d %d\n", 
                   students[i].sno, 
                   students[i].name, 
                   students[i].score1, 
                   students[i].score2, 
                   students[i].score3, 
                   students[i].total_score);
        }
    }
}


void modify_scores(struct Student students[], int count, int target_sno, int s1, int s2, int s3) {
    for (int i = 0; i < count; i++) {
        if (students[i].sno == target_sno) {
            students[i].score1 = s1;
            students[i].score2 = s2;
            students[i].score3 = s3;
            
            students[i].total_score = s1 + s2 + s3; 
            return; 
        }
    }
}


void delete_student(struct Student students[], int *count, int target_sno) {
    int found_index = -1;
    
    
    for (int i = 0; i < *count; i++) {
        if (students[i].sno == target_sno) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
       
        for (int i = found_index; i < *count - 1; i++) {
            students[i] = students[i+1];
        }
       
        (*count)--;
    }
}

int main() {
    
    struct Student students[MAX_STUDENTS];
    int n, q; 
    int current_student_count;

    
    if (scanf("%d %d", &n, &q) != 2) return 0;
    current_student_count = n;

   
    for (int i = 0; i < n; i++) {
        if (scanf("%d %s %d %d %d", 
                  &students[i].sno, 
                  students[i].name, 
                  &students[i].score1, 
                  &students[i].score2, 
                  &students[i].score3) == 5) {
            students[i].total_score = students[i].score1 + students[i].score2 + students[i].score3;
        } else {
           
            break; 
        }
    }

   
    for (int k = 0; k < q; k++) {
        int op_type;
        if (scanf("%d", &op_type) != 1) break;

        if (op_type == 1) { 
           
            char target_name[MAX_NAME_LEN];
            if (scanf("%s", target_name) == 1) {
                query_by_name(students, current_student_count, target_name);
            }
        } else if (op_type == 2) { 
            
            int sno, s1, s2, s3;
            if (scanf("%d %d %d %d", &sno, &s1, &s2, &s3) == 4) {
                modify_scores(students, current_student_count, sno, s1, s2, s3);
                
                print_all_students(students, current_student_count);
            }
        } else if (op_type == 3) { 
           
            int sno;
            if (scanf("%d", &sno) == 1) {
                delete_student(students, &current_student_count, sno);
               
                print_all_students(students, current_student_count);
            }
        }
    }

   
    return 0;
}