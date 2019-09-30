#include<stdio.h>

int main(void)
{
  int n, i, x=0, y=0;
  char s[101];

  scanf("%d", &n);

  for(i=0;i<n;i++)
  {
    scanf("%s", &s[i]);
    if(s[i] == 'I')
      x++;
    else if(s[i] == 'D')
      x--;

    if(y < x)
      y = x;
  }
  printf("%d\n", y);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", &s[i]);
     ^