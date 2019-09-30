#include<stdio.h>
int main (){
  long int A,B,K,L;
  scanf("%ld %ld %ld %ld",&A,&B,&K,&L);
  long int setnum = K/L;
  long int sum = B * setnum + A *(K - (setnum * L));
  if((setnum + 1) * B < sum){
    sum = (setnum +1) * B;
  }
  printf("%ld",sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld %ld %ld",&A,&B,&K,&L);
   ^