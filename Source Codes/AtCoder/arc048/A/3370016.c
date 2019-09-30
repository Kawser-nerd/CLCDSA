#include <stdio.h>
int main(void){
    int a,b;
    scanf("%d%d",&a,&b);
    if (a<0 && b>0){
        b--;
    }
    printf("%d\n",b-a);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^