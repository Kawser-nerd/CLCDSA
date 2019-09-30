#include <stdio.h>

int main(void){
  int n;
  scanf("%d", &n);
  char c[n];
  scanf("%s", c);
  int x = 0;
  int max = 0;
  for(int i = 0; i < n; i++){
    if(c[i] == 'I'){
      x++;
      if(x > max) max = x;
    }else{
      x--;
    }
  }
  printf("%d\n", max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", c);
   ^