#include <stdio.h>
#include <stdlib.h>

int diff(int a, int b)
{
  return (a > b) ? a - b : b - a;
}

int str_length(const char s[])
{
  int len = 0;

  while (s[len])
    len++;
  return len;
}

int main(void)
{
  char s[11];
  int a[10];
  scanf("%s", s);

  int len = str_length(s);
  for (int i = 0; i < len; i++) {
    a[i] = s[i] - '0';
  }
  int min = diff(753, a[0] * 100 + a[1] * 10 + a[2]);
  for (int i = 1; i < len - 2; i++)
    if (diff(753, a[i] * 100 + a[i + 1] * 10 + a[i + 2]) < min)
      min = diff(753, a[i] * 100 + a[i + 1] * 10 + a[i + 2]);
  printf("%d\n", min);	

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^