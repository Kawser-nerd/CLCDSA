#include <stdio.h>
static double n, k, p;
int main(void) {
    scanf("%lf%lf", &n, &k);
    
    // three Ks.
    p += (1 / n) * (1 / n) * (1 / n);
    
    // two Ks.
    p += (1 / n) * (1 / n) * (1 - 1 / n);
    p += (1 / n) * (1 - 1 / n) * (1 / n);
    p += (1 - 1 / n) * (1 / n) * (1 / n);
    
    // first is K.
    p += (1 / n) * ((k - 1) / n) * (1 - k / n);
    p += (1 / n) * (1 - k / n) * ((k - 1) / n);
    
    // second is K.
    p += ((k - 1) / n) * (1 / n) * (1 - k / n);
    p += (1 - k / n) * (1 / n) * ((k - 1) / n);
    
    // third is K.
    p += ((k - 1) / n) * (1 - k / n) * (1 / n);
    p += (1 - k / n) * ((k - 1) / n) * (1 / n);
    
    printf("%.17f\n", p);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf%lf", &n, &k);
     ^