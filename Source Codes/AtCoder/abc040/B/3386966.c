#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int n;
    scanf("%d",&n);
    int sqr = (int)sqrt((double)n);
    int sqr2 = sqr*2;
    int sub,amari,tmp,i,j;
    int min = INT_MAX;
    for(int i = 1;i<=sqr;i++){
        for(int j = sqr;j<=sqr2;j++){
            if(i * j <= n){
                // printf("n %d,i %d,j %d min sqr %d %d\n",n,i,j,sqr,min);
                tmp = n - i * j + abs(i - j);
                if(min > tmp){
                    min = tmp;
                }
            }
        }
    }
    printf("%d\n",min);
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^