#include <stdio.h>
int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    int K;
    int food[30] = {0};
    for(int i = 0; i < N; i++){
        scanf("%d", &K);
        int A;
        for(int j = 0; j < K; j++){
            scanf("%d", &A);
            food[A-1] += 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < M; i++){
        if(food[i] == N){
            ans += 1;
        }
    }
    printf("%d\n", ans);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &M);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &K);
         ^
./Main.c:11:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &A);
             ^