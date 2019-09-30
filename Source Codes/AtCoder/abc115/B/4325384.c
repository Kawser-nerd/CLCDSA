#include <stdio.h>

int max_n (int a[], int n)
{
  int max = a[0];
  int p;
  for (int i = 1; i < n; i++)
    if (a[i] > max) {
      max = a[i];
      p = i;
    }
  return p;
}

int main(void)
{
  int n;
  int p[10];
  int sum = 0;
  int a;

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &p[i]);

  a = max_n(p, n);

  for (int i = 0; i < n; i++) {
    if (i == a)
      sum += p[i] / 2;
    else
      sum += p[i];
  }

  printf("%d\n", sum);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &p[i]);
     ^