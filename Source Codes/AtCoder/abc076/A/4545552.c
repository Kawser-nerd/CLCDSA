#include<stdio.h>
int main(){
    int r,g,a;
    scanf("%d %d",&r,&g);
    a=(2*g)-r;
    printf("%d\n",a);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&r,&g);
     ^