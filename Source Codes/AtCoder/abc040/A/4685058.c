#include <stdio.h>
int main(){
    int a,x;
    scanf("%d%d",&a,&x);
    if(a/2 < x)printf("%d\n",a-x);
    else printf("%d\n",x-1);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&x);
     ^