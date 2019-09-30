#include <stdio.h>
#include <string.h>

int main(void)
{

  char s[100], t[100];
  int i, k = 0;

    scanf("%s", s);

    for (i = 0; i < 10; i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        strcpy(&t[k], &s[i]); k++;
      }
    }

    for (i = 0; i < k; i++)
    printf("%c", t[i]);
    printf("\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^