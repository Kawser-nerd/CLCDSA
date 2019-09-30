#include <stdio.h>

int sum(int n){
    return n * (n + 1) / 2;
}
int main(void){
    int a, b;
    scanf("%d%d", &a, &b);
    int ans =  sum(b - a - 1) - a;
    printf("%d\n", ans);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a, &b);
     ^