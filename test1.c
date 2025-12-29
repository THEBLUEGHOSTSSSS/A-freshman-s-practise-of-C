#include<stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    
    int mask=1;
    while(x>9)
    {
        x=x/10;
        mask=mask*10;

    }
    printf("mask=%d\n", mask);
    do
    {
        int d = x/mask;
        printf("%d\n", d);
        if(mask>9)
        {
            printf("  ");

        }
        x=x%mask;
        mask=mask/10;
    }while(mask>0);
    printf("\n");
    return 0;

}