#include<stdio.h>
#include"hotel.h"
int main()
{
    int nights;
    double hotle_rate;
    
    while ((code=meau())!=QUIT)
    {
        switch (code)
        {
        case 1:hotle_rate=HOTEL1;
            break;
        case 2:hotle_rate=HOTEL2;
            break;
        case 3:hotle_rate=HOTEL3;
            break;
        case 4:hotle_rate=HOTEL4;
            break;
        
        default:hotle_rate=0.0;
            printf("Oops!\n");
            break;
        }
        nights=getnights();
        showprice(hotle_rate,nights);
    }
    printf("Thank you and goodbye.\n");
    return 0;
}