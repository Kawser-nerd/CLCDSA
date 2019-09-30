#include <stdio.h>

int main(void){
    int N;
    int ans[101] = {0};
    scanf("%d", &N);
    for(int i = 0; i <= 25; i++){
        for(int j = 0; j <= 12; j++){
            if(4 * i + 7 * j > 100) continue;
            ans[4 * i + 7 * j] += 1;
        }
    }
    printf("%s\n", (ans[N] > 0) ? "Yes" : "No");
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^