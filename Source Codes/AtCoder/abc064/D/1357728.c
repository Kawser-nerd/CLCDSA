#include <stdio.h>
int main(void)
{
  int n, i, x=0, y=0;
  char s[102];
  
  scanf("%d", &n);
  scanf("%s", s);
  for(i = 0; i < n; i++){
    if(s[i] == '(') x++;
    else if(x > 0) x--;
    else y++;
  }

  for(i = 0; i < y; i++)
    printf("(");
  printf("%s", s);

  for(i = 0; i < x; i++)
    printf(")");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^