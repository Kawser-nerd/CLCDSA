#include <stdio.h>

int main(void)
{
    long int N, x = 1;
    int deapth = 0, turn = 0, i;

    scanf("%ld", &N);

    for(long int tmp = N; tmp > 0; tmp /= 2)
        deapth++;
    if(deapth%2) {
        while(x<=N) {
            if(turn%2) {
                x *= 2;
           }else {
                x = x*2+1;
           }
           turn++;
        }
    }else {
        while(x<=N) {
            if(turn%2) {
                x = x*2+1;
           }else {
                x *= 2;
           }
           turn++;
        }
    }

    if(turn%2) 
        printf("Aoki\n");
    else
        printf("Takahashi\n");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &N);
     ^