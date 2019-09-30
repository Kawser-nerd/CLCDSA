#include <stdio.h>
int main(void){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if (n<5){
        printf("%d\n",b*n);
    } else {
        printf("%d\n",a*n-(a-b)*5);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&a,&b);
     ^