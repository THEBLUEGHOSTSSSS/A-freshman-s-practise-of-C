#include <stdio.h>
#include <string.h>

#define MAX_LINE 100  
#define MAX_NAME 50   

typedef struct {
    char id[20];      
    char name[MAX_NAME];  
    double height;    
    double weight;   
} Student;


void findStudent(const char *filename, const char *studentId) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("%s : File not found.\n", studentId);
        return;
    }
    
    Student stu;
    int found = 0;
    
    
    while (!found && fscanf(fp, "%s %s %lf %lf", 
                           stu.id, stu.name, &stu.height, &stu.weight) == 4) {
        if (strcmp(stu.id, studentId) == 0) {
            printf("%s : %s %.2lf %.2lf\n", stu.id, stu.name, stu.height, stu.weight);
            found = 1;
        }
    }
    
    fclose(fp);
    
   
    if (!found) {
        printf("%s : Not found.\n", studentId);
    }
}

int main() {
  
    char studentId[20];
    
  
    while (scanf("%s", studentId) == 1) {
        findStudent("STU.TXT", studentId);
    }
    
    return 0;
}