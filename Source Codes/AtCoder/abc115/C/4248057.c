#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
  return *(int*)a - *(int*)b;
}


int main(void)
{
  int k, n;
  int h[100000];

  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", &h[i]);
  
  qsort(h, n, sizeof(int), compare);

  int min = h[k - 1] - h[0];
  for (int i = 1; i < n - k + 1; i++) {
    if (h[k + i - 1] - h[i] < min)
      min = h[k + i - 1] - h[i];
  }

  printf("%d\n", min);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &k);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &h[i]);
     ^