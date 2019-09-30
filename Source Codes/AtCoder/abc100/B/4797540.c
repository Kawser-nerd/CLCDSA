#include <stdio.h>
#include <math.h>

int main(void){
    int d, n;
    scanf("%d%d", &d, &n);
    n += n/100;
    int ans = pow(100, d) * n;    
    printf("%d\n", ans);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &d, &n);
     ^