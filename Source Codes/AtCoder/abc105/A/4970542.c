# include <stdio.h>

int main(){
    int N, K;

    scanf("%d%d", &N, &K);

    int dif = 0;
    if (N % K)
        dif = 1;

    printf("%d", dif);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &N, &K);
     ^