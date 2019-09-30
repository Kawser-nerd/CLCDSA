#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    printf("%d\n",800*n-200*(n/15));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^