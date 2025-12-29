#include<stdio.h>
#include<stdlib.h>

int main(){
    void *p;
    int cnt=0;
    while((p=malloc(10*1024*1024))){
        cnt++;
    }
    printf("Allocated %d00 MB\n",cnt);
    return 0;
}