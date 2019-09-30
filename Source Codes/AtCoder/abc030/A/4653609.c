#include<stdio.h>
#include<string.h>
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if((double)b/a > (double)d/c)printf("TAKAHASHI\n");
    else if((double)b/a < (double)d/c)printf("AOKI\n");
    else printf("DRAW\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&a,&b,&c,&d);
     ^