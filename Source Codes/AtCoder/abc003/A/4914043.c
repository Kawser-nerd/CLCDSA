#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int N, i;
    int a = 10000;
    int money = 0;

    scanf("%d", &N);
    for(i = 0; i < N; i++){
        money += a;
        a += 10000;
    }

    printf("%d\n", money/N);


} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^