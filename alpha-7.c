#include<stdio.h>
#include<stdlib.h>
#define NAME "GIGATHINK,INC."
#define ADDRESS "101 Megabuck Plaza"
#define PlACE "Megapolis,CA 94904"
#define WIDTH 40

void starbar();/*声明函数原型*/

int main()
{
    starbar();
    printf("%s\n",NAME);
    printf("%s\n",ADDRESS);
    printf("%s\n",PlACE);
    starbar();
    
   return 0;
}
void starbar()/*定义函数starbar()*/
{
    int count;
    for(count=1;count<=WIDTH;count++)
    putchar('*');
    putchar('\n');
}