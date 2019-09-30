#include <stdio.h>
#include <stdlib.h>
int main(void){
// Your code here!
    double a[6];
    int i;
    float ans;
    for(i=0;i<6;i++) scanf("%lf",&a[i]);
    a[0] -= a[4];
    a[2] -= a[4];
    a[1] -= a[5];
    a[3] -= a[5];

    ans = fabs((a[0]*a[3]-a[1]*a[2])/2);
    printf("%f",ans);
} ./Main.c: In function ‘main’:
./Main.c:14:11: warning: implicit declaration of function ‘fabs’ [-Wimplicit-function-declaration]
     ans = fabs((a[0]*a[3]-a[1]*a[2])/2);
           ^
./Main.c:14:11: warning: incompatible implicit declaration of built-in function ‘fabs’
./Main.c:14:11: note: include ‘<math.h>’ or provide a declaration of ‘fabs’
./Main.c:8:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<6;i++) scanf("%lf",&a[i]);
                      ^