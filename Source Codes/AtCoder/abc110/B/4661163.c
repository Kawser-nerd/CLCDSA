#include <stdio.h>
int max(int x[], int num){
    int m = -100;
    for(int i = 0; i < num; i++){
        if(m < x[i]){m = x[i];}
    }
    return m;
}

int min(int x[], int num){
    int m = 100;
    for(int i = 0; i < num; i++){
        if(m > x[i]){m = x[i];}
    }
    return m;
}

int main(void){
    int N, M, X, Y;
    scanf("%d %d %d %d", &N, &M, &X, &Y);
    int x[N+1];
    for(int i = 0; i < N; i++){
        scanf("%d", &x[i]);
    }
    x[N] = X;
    X = max(x, N+1);

    int y[M+1];
    for(int i = 0; i < M; i++){
        scanf("%d", &y[i]);
    }
    y[M] = Y;
    Y = min(y, M+1);
    if(X < Y){
        printf("%s ", "No");
    }
    printf("%s\n", "War");
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d", &N, &M, &X, &Y);
     ^
./Main.c:23:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &x[i]);
         ^
./Main.c:30:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &y[i]);
         ^