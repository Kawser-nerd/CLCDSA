#include <stdio.h>
#define N_ELEMENT 1000000
int main() {
  int s;
  scanf("%d", &s);
  int a[N_ELEMENT];
  a[0] = s;
  int i,j; /* index */

  for (i = 1;i < N_ELEMENT;++i) {
    if (a[i-1] % 2 == 1) {
      a[i] = 3*a[i-1] + 1;
    } else if (a[i-1] % 2 == 0) {
      a[i] = a[i-1] / 2;
    } else {
      printf("Error\n");
    }
  }

  int count[N_ELEMENT] = {0};
  for (i = 0;i < N_ELEMENT;++i) {
    int	temp = a[i] - 1;
    ++count[temp];
    for (j = 0;j < 100;++j) {
      if (count[j] == 2) {
        goto end;
      }
    }
  }
 end:
  printf("%d\n",i + 1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &s);
   ^