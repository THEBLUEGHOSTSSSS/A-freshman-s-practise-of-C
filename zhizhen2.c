#include<stdio.h>
#define SIZE 10
int sump(int *start, int *end);
int main(){
    int marbles[SIZE]={20,30,25,15,10,5,40,50,60,70};
    long answer;

    answer=sump(marbles,marbles+SIZE);
    printf("The total number of marbles is %ld\n",answer);
    return 0;

}
int sump(int *start, int *end){
    int total=0;
    while(start<end){
        total+=*start;
        start++;
    }
    return total;
}