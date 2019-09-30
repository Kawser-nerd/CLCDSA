#include <stdio.h>

int main(){
    int N, A, B, sum, cnt = 0, sumAll = 0;
    scanf("%d%d%d", &N, &A, &B);
    for(int n = 1; n <= N; n++){
        sum = 0;
        int n_now = n;
        for(int i = 0; i < 5; i++){
            sum += n_now%10;
            n_now /= 10;
        }
        if(sum >= A && sum <= B) sumAll += n;
    }
    printf("%d", sumAll);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &N, &A, &B);
     ^