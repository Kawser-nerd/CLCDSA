#include <stdio.h>

int divisor(int num){
  int count = 0;
  for(int i=1;i<=num;i++){
    if(num%i==0)
      count++;
  }
  return count;
}

int counter(int num){
  int x = 0;
  for(int i=1;i<=num;i++){
    if(i%2==1 && divisor(i)==8){
      x++;
    }
  }
  return x;
}

int main(void){
  int n = 0;
  scanf("%d", &n);
  printf("%d", counter(n));
} ./Main.c: In function ‘main’:
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^