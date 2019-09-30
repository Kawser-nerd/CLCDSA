#include <stdio.h>

int main(){
  int a,b,c;
  scanf("%d %d %d", &a, &b, &c);
  int answer;
  if(a == b && b == c) answer = 1;
  else if(a == b || b == c || c == a) answer = 2;
  else answer = 3;
  printf("%d\n", answer);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &a, &b, &c);
   ^