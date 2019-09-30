#include<stdio.h>

int main(void){
    int k;
    scanf("%d", &k);
    int ans;
    if(k % 2 == 0){
        ans = k * k / 4; 
    }
    else{
        ans = k / 2 * (k / 2 + 1);
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &k);
     ^