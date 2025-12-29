/*2025.10.27
向函数传递一维数组
输入n个学生的成绩，输出n个学生的成绩，求解其最高分
*/
#include<stdio.h>
#define N 20

int ReadScore(int score[]);//函数原型的声明
int FindMax(int score[], int n);
void PrintScore(int score[], int n);
void DataSort(int score[], int n);

int main(void)
{  
    int score[N], max, n;	
    n = ReadScore(score);
    printf("Total students are %d\n", n);
    PrintScore(score,n);
    max = FindMax(score, n);
    printf("The highest score is %d\n", max);
    
    // 可选：排序并输出排序后的成绩
    DataSort(score, n);
    printf("Sorted scores: ");
    PrintScore(score, n);
    
    return 0;
}

//函数功能：输入学生的成绩，当输入负值时，结束输入，返回学生人数
int ReadScore(int score[]) //函数定义
{
    int i = -1;
    do{
        i++;
        printf("Input score:");
        scanf("%d", &score[i]); // 输入成绩
    } while(score[i] >= 0 && i < N-1);  // 当输入负值时，循环结束，同时防止数组越界
    
    // 如果最后一个输入是负数，需要调整计数
    if(score[i] < 0) {
        return i;
    }
    return i+1; // 函数返回值，返回学生人数
}

//函数功能：输出学生成绩
void PrintScore(int score[], int n)
{
    int i;
    for(i = 0; i < n; i++){
        printf("%4d", score[i]);
    }
    printf("\n");
}

//函数功能：计算最高分
int FindMax(int score[], int n)
{
    int i, max = score[0];
    for (i = 1; i < n; i++){
        if(score[i] > max)
            max = score[i];
    }
    return max;
}

//函数功能：将学生成绩按照从高到低排序（冒泡排序）
void DataSort(int score[], int n)
{
    int i, j, temp;
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-1-i; j++)  // 修正了循环条件
        {
            if(score[j] < score[j+1]){  // 从高到低排序
                temp = score[j];
                score[j] = score[j+1];
                score[j+1] = temp;
            }
        }
    }
}