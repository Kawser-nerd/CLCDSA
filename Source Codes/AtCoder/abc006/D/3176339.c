#include <stdio.h>

int main(int argc, const char * argv[]) {
    int N = 0;
    
    scanf("%d", &N);
    
    int num[40000];
    
    for(int i = 0; i < N; i++){
        scanf("%d", &num[i]);
    }
    
    int dp[40000];
    for(int i = 0; i < 40000; i++){
        dp[i] = 0;
    }
    int max_up = 0;
    for(int i = 0; i < N; i++){
        int max = 0;
        for(int j = 0; j < num[i]; j++){
            if(max < dp[j]){
                max = dp[j];
            }
        }
        if(dp[num[i]] < max + 1){
            dp[num[i]] = max + 1;
            if(max_up < dp[num[i]]){
                max_up = dp[num[i]];
            }
        }
    }
    
    
    printf("%d\n", N - max_up);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &num[i]);
         ^