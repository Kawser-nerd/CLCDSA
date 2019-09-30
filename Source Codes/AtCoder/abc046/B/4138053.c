#include <stdio.h>
int main(void){
    int n, k, num = 1;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n-1; i ++){
        num *= (k-1);
    }
    num *= k;
    printf("%d\n", num);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &k);
     ^