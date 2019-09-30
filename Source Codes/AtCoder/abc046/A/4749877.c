#include <stdio.h>

int main()
{
  int a,b,c, ans;
  scanf("%d %d %d", &a, &b, &c);
  
  if(a == b && b == c)
    ans = 1;
  else if(a == b || a == c || b == c)
    ans = 2;
  else
    ans = 3;
  printf("%d", ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &a, &b, &c);
   ^