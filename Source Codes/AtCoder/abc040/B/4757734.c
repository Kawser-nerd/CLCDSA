#include <stdio.h>
#include <math.h>
int main(void){
    int n,h,w,min=1000000000,sa;
    scanf("%d",&n);
    for(h=1;h<=n;h++){
        for(w=1;w*h<=n && w<=h;w++){
            sa=n-w*h+h-w;
            if(sa<min) min=sa;
        }
    }
    printf("%d\n",min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^