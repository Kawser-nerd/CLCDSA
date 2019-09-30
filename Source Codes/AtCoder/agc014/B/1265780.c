#include <stdio.h>

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    int a[M], b[M];
    for(int i=0; i<M; i++){
        scanf("%d %d", &a[i], &b[i]);
    }
    //FR
    int C[N+1];
    for(int i=1; i<=N; i++){
        C[i] = 0;
    }
    for(int i=0; i<M; i++){
        C[a[i]]++;
        C[b[i]]++;
    }
    for(int i=1; i<=N; i++){
        if(C[i]%2 == 1){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &M);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &a[i], &b[i]);
         ^