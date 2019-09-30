#include <stdio.h>
#include <string.h>

int main()
{
  char a[200001];
  int B = 0;
  long int count = 0;
  scanf("%s", a);

  for (int i = 0; i < strlen(a); i++)
  {
    if (a[i] == 'B')
      B += 1;
    else
    {
      count += B;
    }
  }
  printf("%ld\n", count);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", a);
   ^