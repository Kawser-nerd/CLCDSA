#include <stdio.h>
#define N_MAX 100000
#define a_MAX 10000

int my_abs(int a, int b){
    if(a-b>=0)
        return a-b;
    else
        return b-a;
}

int main (void){
    int dp[N_MAX]={};
    int N;
    scanf("%d",&N);
    int a[N];
    for(int i=0; i<N; i++){
        scanf("%d",&a[i]);
    }
    dp[0] = 0;
    dp[1] = my_abs(a[0], a[1]);
    for(int i=2; i<N; i++){
        if( dp[i-2]+my_abs(a[i],a[i-2]) <= dp[i-1]+my_abs(a[i],a[i-1]) )
            dp[i] = dp[i-2]+my_abs(a[i],a[i-2]);
        else
            dp[i] = dp[i-1]+my_abs(a[i],a[i-1]);
    }
    printf("%d\n",dp[N-1]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^