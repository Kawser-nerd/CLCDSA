#include<stdio.h>
int main(){
    long int a,b,x;
    scanf("%ld %ld %ld",&a,&b,&x);
    long int y=b/x-a/x;
    if(a%x==0) y++;
    printf("%ld",y);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld %ld",&a,&b,&x);
     ^