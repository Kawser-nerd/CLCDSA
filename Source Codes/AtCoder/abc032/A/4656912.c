#include <stdio.h>
int main(void){
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    while(n%a+n%b>0)
        n+=1;
    printf("%d\n",n);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&n);
     ^