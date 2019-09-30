#include<stdio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int start = a+b;
    if(start>=24)start -= 24;
    printf("%d\n",start);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^