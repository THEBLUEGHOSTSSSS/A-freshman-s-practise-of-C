#include <stdio.h>

// 定义学生结构体
struct Student {
    int id;          // 学号
    char name[20];   // 姓名
    float english;   // 英语成绩
    float math;      // 数学成绩
    float average;   // 平均分
};

int main() {
    struct Student students[5];
    int i, max_index = 0;
    
    // 输入5个学生的信息
    for (i = 0; i < 5; i++) {
        printf("请输入第%d个学生的信息:\n", i + 1);
        printf("学号: ");
        scanf("%d", &students[i].id);
        printf("姓名: ");
        scanf("%s", students[i].name);
        printf("英语成绩 数学成绩: ");
        scanf("%f %f", &students[i].english, &students[i].math);
        
        // 计算平均分
        students[i].average = (students[i].english + students[i].math) / 2.0;
        printf("\n");
    }
    
    // 找出平均分最高的学生
    for (i = 1; i < 5; i++) {
        if (students[i].average > students[max_index].average) {
            max_index = i;
        }
    }
    
    // 输出结果
    printf("\n平均分最高的学生信息:\n");
    printf("%d %s %.2f %.2f %.2f\n", 
           students[max_index].id,
           students[max_index].name,
           students[max_index].english,
           students[max_index].math,
           students[max_index].average);
    
    return 0;
}