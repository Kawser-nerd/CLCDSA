#include <stdio.h>

int main(){
  int x;
  scanf("%d",&x);
  int primes[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
  int exp[15] = {};
  for (int i=0;i<15;i++){
    int temp = x / primes[i];
    while (temp != 0){
      exp[i] = exp[i] + temp;
      temp = temp / primes[i];
    }
  }
  int b75=0,b25=0,b15=0,b5=0,b3=0;
  for (int i=0;i<15;i++){
    if (exp[i] >= 74)
      b75++;
    if (exp[i] >= 24)
      b25++;
    if (exp[i] >= 14)
      b15++;
    if (exp[i] >= 4)
      b5++;
    if (exp[i] >= 2)
      b3++;
  }
  int ret = b75 + b25*(b3-1) + b15*(b5-1) + (b5*(b5-1)*(b3-2))/2;
  printf("%d\n",ret);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x);
   ^