#include <stdio.h>
int main(void){
    int n,k,x,y;
    scanf("%d%d%d%d",&n,&k,&x,&y);
    if(n>k) printf("%d\n",x*k+y*(n-k));
    else printf("%d\n",x*n);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&n,&k,&x,&y);
     ^