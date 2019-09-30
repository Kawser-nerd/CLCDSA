#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN 1E9
#define MAX -10000000
long long int i,j;

int cp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}

int main(void){
    int sx,sy,tx,ty;
    scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
    for(i=sy;i<ty;i++)printf("U");
    for(i=sx;i<tx;i++)printf("R");
    for(i=ty;i>sy;i--)printf("D");
    for(i=tx;i>sx;i--)printf("L");
    printf("L");
    for(i=sy;i<=ty;i++)printf("U");
    for(i=sx;i<=tx;i++)printf("R");
    printf("DR");
    for(i=ty;i>=sy;i--)printf("D");
    for(i=tx;i>=sx;i--)printf("L");
    puts("U");
 // puts("UURDDLLUUURRDRDDDLLU");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
     ^