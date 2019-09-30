#include <stdio.h>

int main(void) {

  int n, m, a, b, c[100], i, ju, meisi, count;


  scanf("%d%d%d%d", &n, &m , &a, &b);

  for (i = 0; i < m; i++)
    scanf("%d", &c[i]);

  meisi = n;
  for (i = 0; i < m; i++) {
    if (meisi <= a)
      meisi += b;
    meisi -= c[i];

    if (meisi < 0) {
      ju = 0;
      count = i + 1;
      break;
    }
    else
      ju = 1;


  }

  if (ju == 1)
    printf("complete\n");
  else
    printf("%d\n", count);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d", &n, &m , &a, &b);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &c[i]);
     ^