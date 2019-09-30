#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  int sum = 0;
  int tmp = n;
  while(tmp > 0){
    sum += tmp % 10;
    tmp = tmp / 10;
  }
  if(n % sum == 0){
    puts("Yes");
  }else{
    puts("No");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^