#include <stdio.h>
int main(void)
{
    int  N, C, s, t, c;
    int  i, j, sum, max, v[30][100000]={{0}}, sm=100000, tm=0;
    
    scanf("%d %d", &N, &C);
    for(i = 0; i < N; i++){
        scanf("%d %d %d", &s, &t, &c);
        for(j = s-1; j < t; j++){
            v[c-1][j] = 1;
        }
        if(s<sm)sm=s; if(t>tm)tm=t;
    }
    max = 0;
    for(j = sm; j < tm; j++){
        sum = 0;
        for(i = 0; i < C; i++){
            if(v[i][j] > 0){
                sum++;
            }
        }
        if(sum > max){
            max = sum;
        }
    }
    printf("%d\n", max);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &C);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &s, &t, &c);
         ^