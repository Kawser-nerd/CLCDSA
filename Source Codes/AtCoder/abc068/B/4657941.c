#include <stdio.h>
int main(void){
    int n,i;
    scanf("%d",&n);
    for(i=2;i<=n;i*=2);
    printf("%d\n",i/2);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^