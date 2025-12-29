#include<stdio.h>
int sum(int *ar,int n);
int main() 
{   int n,i;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int ar[n];
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    sum(ar,n);
    printf("Sum of elements is:%d",sum(ar,n));
    return 0;
}
int sum(int *ar,int n)
{
    int i;
    int total=0;
    for(i=0;i<n;i++)
    {
        total+=*(ar+i);
    }
    return total;
        
}