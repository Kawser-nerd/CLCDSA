#include <stdio.h>

int main(void)
{
  int len, q;
  scanf("%d%d", &len, &q);

  char str[len + 1];
  scanf("%s", str);

  int i, j, k;
  int table[len];

  table[0] = 0;
  for(i = 1; i < len; i++)
    {
      if(str[i - 1] == 'A' && str[i] == 'C') {
        table[i] = table[i - 1] + 1;
      }
      else {
        table[i] = table[i - 1];
      }
    }

  int answers[len];
  for(i = 0; i < q; i++) {
    scanf("%d%d", &j, &k);
    answers[i] = table[k - 1] - table[j - 1];
  }
  for(i = 0; i < q; i++) {
    printf("%d\n", answers[i]);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &len, &q);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", str);
   ^
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &j, &k);
     ^