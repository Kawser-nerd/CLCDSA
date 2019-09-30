#include<stdio.h>
#include<stdlib.h>
int main(){
    int x,a,b;
    scanf("%d%d%d",&x,&a,&b);
    int disa = abs(a-x),disb = abs(b-x);
    if(disa<disb)printf("A\n");
    else printf("B\n");
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&x,&a,&b);
     ^