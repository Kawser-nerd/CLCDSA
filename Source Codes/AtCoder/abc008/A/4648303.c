#include <stdio.h>
int main(void){
    int s,t;
    scanf("%d%d",&s,&t);
    printf("%d\n",t-s+1);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&s,&t);
     ^