#include <stdio.h>

int main() {
    const int STANDARD_HOURS = 160;  
    const int STANDARD_RATE = 5;     
    const int OVERTIME_RATE = 4;     
    
    int work_hours;                  
    int total_salary;                
    
    
    
    scanf("%d", &work_hours);
    
    
    if (work_hours < 0) {
        printf("工作时间不能为负数！\n");
        return 1;
    }
    
    
    if (work_hours <= STANDARD_HOURS) {
        
        total_salary = work_hours * STANDARD_RATE;
    }  else {
       
        int standard_salary = STANDARD_HOURS * STANDARD_RATE;
        int overtime_hours = work_hours - STANDARD_HOURS;
        int overtime_salary = overtime_hours * OVERTIME_RATE;  
        total_salary = standard_salary + overtime_salary;
    }
    
  
    
    
   
    
    printf(" %d", total_salary);
    
    return 0;
}