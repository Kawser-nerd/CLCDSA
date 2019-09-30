#include <stdio.h>

int main(void){
  int a, b;
  scanf("%d%d", &a, &b);
  int i;
  int count = 0;
  for(i = a; i <= b; i++){
    if(((i / 10000) % 10) == i % 10){
      if((i / 1000) % 10 == (i / 10) % 10){
        count++;
      }
    }
  }
  printf("%d\n", count);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^