#include<stdio.h>

int main(){
int N,K;
scanf("%d %d",&N,&K);
int i;
int num = K;
for(i=1;i<=N-1;i++)
  num = num *(K-1);
printf("%d",num);
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d %d",&N,&K);
 ^