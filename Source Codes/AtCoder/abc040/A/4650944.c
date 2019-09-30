#include <stdio.h>
int main(void){
    int n,x;
    scanf("%d%d",&n,&x);
    printf("%d\n",x-1<n-x?x-1:n-x);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&x);
     ^