#include <stdio.h>
int main()
{
  char op;
  int a, b;
  scanf("%d %c %d", &a, &op, &b);
  if(op == '+')
    printf("%d", a+b);
  else if(op == '-')
    printf("%d", a-b);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %c %d", &a, &op, &b);
   ^