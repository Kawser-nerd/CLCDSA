#include <stdio.h>
#include <math.h>
int main(void){
    // Your code here!
    int n,x,g = 101;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        g = fmin(x,g);
    }
    printf("%d\n",g);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x);
         ^