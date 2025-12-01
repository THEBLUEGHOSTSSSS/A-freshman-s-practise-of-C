#include<stdio.h>
#include<string.h>
#define RPWS 3
#define ROWS 4
#define COLS 4
int sum2d(int rows, int cols, int ar[rows][cols]){
    int r,c;
    int tot = 0;
    for(r = 0; r < rows; r++){
        for(c = 0; c < cols; c++){
            tot += ar[r][c];
        }
    }
    return tot;
}

int main(){
    int i,j;
    int rs=3;
    int cs=10;
    int junk[RPWS][COLS]={
        {2,4,6,8},
        {3,5,7,9},
        {12,10,8,6}
    };
    int morejunk[ROWS][COLS+2]={
        {20,30,40,50,60,70},
        {5,6,7,8,9,10},
        {1,2,3,4,5,6},
        {11,22,33,44,55,66}
    };
    int varr[rs][cs];
    for(i=0;i<rs;i++){
        for(j=0;j<cs;j++){
            varr[i][j]=(i+1)*(j+1);
        }
    }
    printf("3x4 array total: %d\n",sum2d(RPWS,COLS,junk));
    printf("4x6 array total: %d\n",sum2d(ROWS,COLS+2,morejunk));
    printf("3x10 array total: %d\n",sum2d(rs,cs,varr));
    return 0;



}