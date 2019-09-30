#include <stdio.h>
int main(void){
    int q;
    scanf("%d",&q);
    if(q==1) printf("ABC\n");
    else printf("chokudai\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&q);
     ^