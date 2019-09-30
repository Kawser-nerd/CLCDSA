#include <stdio.h>

int main() {
  char s[4];
  scanf("%s", s);
  int n,i;
  
  while(i < 3) {
    if(s[i] == '1')
      n++;
    i++;
  }
  printf("%d\n", n);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^