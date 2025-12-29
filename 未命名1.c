#include<stdio.h>
#include<math.h>
int main (){
    double t,w,h;
    printf("Please enter your w and h:");
    scanf("%lf %lf",&w,&h);
    t=w/(h*h);
if(t<18)
    printf("Low t");
    else if(18<=t&&t<=25)
        printf("Normal t");
        else if(25<=t&&t<=27)
            printf("Heavy");
        else
            printf("Fat");
    return 0;

}
