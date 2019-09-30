#include <stdio.h>
#include <string.h>

int main(void)
{

  char str[200001];
  long long int Bcount = 0;
  long long int ans = 0;

  scanf("%s", str);

  for (long long int i = 0; i < strlen(str); i++)
  {
    if (str[i] == 'B')
    {
      Bcount++;
    }
    else
    {
      ans += Bcount;
    }
  }
  printf("%lld", ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", str);
   ^