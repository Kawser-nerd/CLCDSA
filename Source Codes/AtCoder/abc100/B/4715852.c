#include <stdio.h>
int main(void){
    int d,n;
    scanf("%d%d",&d,&n);
    if(n==100) printf("%d\n",d==0?101:(d==1?10100:1010000));
    else printf("%d\n",d==0?n:(d==1?100*n:10000*n));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&d,&n);
     ^