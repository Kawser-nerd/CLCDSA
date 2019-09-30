#include <stdio.h>
int main(void){
    int a,b,c,color=3;
    scanf("%d%d%d",&a,&b,&c);
    if(a==b) color--;
    if(b==c) color--;
    else if(a==c) color--;
    printf("%d\n",color);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^