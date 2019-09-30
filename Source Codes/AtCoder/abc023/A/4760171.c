#include<stdio.h>
int main(){
int num,sum=0;
  scanf("%d",&num);
  while(1){
    if(num==0) break;
  sum+=num%10;
    num/=10;
  }
  printf("%d\n",sum);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&num);
   ^