#include<stdio.h> 
int max(int a[],int n);


int main()

{   const int SIZE=5;
    int a[SIZE];
    for(int i=0;i<=SIZE;i++)
    {
        scanf("%d",&a[i]);
    }
    int maxs=max(a,SIZE);
    printf("%d",maxs);
    return 0;

  

}
int max(int a[],int n){
    int max=a[0];
    for(int i=1;i<=n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}