#include<stdio.h>
#define Min(a,b) a<b?a:b
int main(void){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int train=Min(a,b);
    int bus=Min(c,d);
    printf("%d\n",train+bus);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&a,&b,&c,&d);
     ^