#include<stdio.h>
int main(){
    int x,t;
    scanf("%d%d",&x,&t);
    int result = x-t;
    if(result<0)result=0;
    printf("%d\n",result);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&t);
     ^