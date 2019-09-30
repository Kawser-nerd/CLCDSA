#include <stdio.h>
int main(void){
    int n,k,x,d=0,i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        d+=2*(x<k-x?x:k-x);
    }
    printf("%d\n",d);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x);
         ^