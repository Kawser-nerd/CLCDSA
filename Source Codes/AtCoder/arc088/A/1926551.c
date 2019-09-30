#include<stdio.h>
#include<stdlib.h>

int main(){
   long long i,j;
   int c=0;
   scanf("%lld%lld",&i,&j);
   while (i<=j) {
    c++;
    i*=2;
   }
   printf("%d\n",c);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%lld%lld",&i,&j);
    ^