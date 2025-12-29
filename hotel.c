#include<stdio.h>
#include"hotel.h"
int meau();
int getnights();
void showprice(double rate,int nights);
int meau()
{
    int code,status;

    printf("\n%s%s\n",STARS,STARS);
    printf("ENTER THE NUMBER OF THE DESIRED HOTLE:\n");
    printf("l) Fairfield Arms    2)Hotel 0lympic\n");
    printf("3) Chertworthy Plaza    4)The  Stockton\n");
    printf("5) quit \n");
    printf("\n%s%s\n",STARS,STARS);
    while((status = scanf("%d",&code))!=1 ||(code<1 ||code>5))
    {
        if(status!=1)
            scanf("%*s");
        printf("ENTER AN INTERGER FROM 1 TO 5 PLZ.\n");
    }
    return code;
}
int getnights()
{
    int nights;

    printf("HOW MANY NIGHTS ARE NEEDED?");
    while(scanf("%d",&nights)!=1)
    {
        scanf("%*s");
        printf("ENTER AN INTERGER,SUCH AS 2.\n");
    }
    return nights;
}
void showprice(double rate,int nights)
{
    int n;
    double total=0.0;
    double factor=1.0;
    for (n=1;n<=nights;n++,factor*=DISCOUNT)
        total+=rate*factor;
    printf("THE TOTAL COST WILL BE $0.2f.\n");
}


    
