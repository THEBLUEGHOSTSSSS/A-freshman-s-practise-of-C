#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main(){
/*unsigned int seed;*/
int magic,guess;
int ret;
char reply;
/*printf("Please enter ur seed:");
canf("%u",&seed);
srand(time(NULL));
magic=rand()%100+1;*/
do{ int counter=0;
    /*srand(time(NULL));*/ 
     unsigned int seed;
    FILE *urandom = fopen("/dev/urandom", "r");
    if (urandom) {
        fread(&seed, sizeof(seed), 1, urandom);
        fclose(urandom);
    } else {
        seed = time(NULL);
    }
    srand(seed);
    magic=rand()%100+1;                                                                                
do{ printf("Please enter ur numeber:");
    ret=scanf("%d",&guess);
    while(ret!=1)
    {
        while(getchar()!='\n');
        printf("ENTER A NUMBER PLESAE !");
        ret=scanf("%d",&guess);
       }           
    counter++;
    if(guess>magic)
        printf("WRONG! TOO BIG\n");
    else if(guess<magic)
        printf("WRONG! TOO SMALL\n");
    else 
        printf("RIGHT\n");
}while(guess!=magic&&counter<=10);
    printf("DO U WANT TO CONTINUE");
    scanf(" %c",&reply);

}while(reply=='y'||reply=='Y');
    return 0;
}