#include<stdio.h>
int main(void){
    int N, M, X, Y;
    scanf("%d %d %d %d", &N, &M, &X, &Y);
    int x[N],y[M];
    for(int i = 0; i < N; i++){
        scanf("%d", &x[i]);
    }
    for(int i = 0; i < M; i++){
        scanf("%d",&y[i]);
    }

    int maxx = x[0];
    for(int i = 1; i < N; i++){
        if(maxx < x[i]) maxx = x[i];
    }
    int miny = y[0];
    for(int i = 1; i < M; i++){
        if(miny > y[i]) miny = y[i];
    }

    if(maxx < miny && X < miny && Y > maxx){
        printf("No War\n");
    }else{
        printf("War\n");
    }

    // if(maxx < miny){
    //     if(X < miny && Y > maxx) 
    // }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d", &N, &M, &X, &Y);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &x[i]);
         ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&y[i]);
         ^