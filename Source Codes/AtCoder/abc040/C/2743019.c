#include <stdio.h>


int min(int a, int b){
    if(a >= b){
        return b;
    }
    else{
        return a;
    }
}

int main(void){
    int n,i;
    scanf("%d", &n);
    int bar[100005];
    for(i=0; i<n; i++){
        scanf("%d", &bar[i]);
    }
    int dp[100005];
    dp[0] = 0;
    dp[1] = abs(bar[0]-bar[1]);
    for(i=2; i<=n; i++){
        dp[i] = min(dp[i-2] + abs(bar[i]-bar[i-2]), dp[i-1] + abs(bar[i] - bar[i-1]));
    }
    printf("%d\n", dp[n-1]);
} ./Main.c: In function ‘main’:
./Main.c:22:13: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     dp[1] = abs(bar[0]-bar[1]);
             ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &bar[i]);
         ^