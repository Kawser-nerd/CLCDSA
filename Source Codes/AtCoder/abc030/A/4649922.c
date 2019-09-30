#include <stdio.h>
int main(void){
    int a,b,c,d;
    double ta,ao;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    ta=(double)b/a;
    ao=(double)d/c;
    printf("%s\n",ta>ao?"TAKAHASHI":(ta<ao?"AOKI":"DRAW"));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&a,&b,&c,&d);
     ^