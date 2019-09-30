#include<stdio.h>

int main(){
  int n, c;
  scanf("%d", &n);
  if(n%2 == 0){
    c = n - 1;
  } else {
    c = n + 1;
  }
  
  printf("%d\n", c);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^