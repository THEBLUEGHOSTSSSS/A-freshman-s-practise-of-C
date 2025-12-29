#include<stdio.h>
int sum(int * ar)
{
    int i;
    int total =0;
    for(i =0;i<10;i++)
       total+=ar[i];
    return total;
    
}