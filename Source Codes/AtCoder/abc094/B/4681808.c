#include <stdio.h>
int main(void){
    int n,m,x,a,i,c0=0,cn=0;
    scanf("%d%d%d",&n,&m,&x);
    for(i=0;i<m;i++){
        scanf("%d",&a);
        if(a<x) c0++;
        else cn++;
    }
    printf("%d\n",c0<cn?c0:cn);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&m,&x);
     ^
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a);
         ^