#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[200000];

  scanf("%s", s);

  long ans = 0;
  long count = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == 'B')
      count++;
    else if (s[i] == 'W')
      ans += count;
  }

  printf("%ld\n", ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^