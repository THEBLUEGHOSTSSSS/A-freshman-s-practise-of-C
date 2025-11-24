#include<stdio.h>
int main()
{
    int i,j,a=0;
    for(i=0;i<2;i++)
    {   printf("%d\n",i);
        for(j=0;j<=4;j++) 
        {   printf("we%d\n",a);
            a++; 
            printf("%d\n",a);}
    }
        printf("%d",a);
    return 0;
}