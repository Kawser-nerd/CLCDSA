#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    for (int i=0; i<(n+8)/9; i++){
        printf("%d",(n-1)%9+1);
    }
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^