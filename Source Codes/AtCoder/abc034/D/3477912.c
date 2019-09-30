#include<stdio.h>
#include<stdlib.h>
#define NMAX 1000

int n, k;
double w[NMAX], p[NMAX], c[NMAX];
int compare(const void *a, const void *b);
int concentrate(double x);
int main(void)
{
  int i;
  double lb = 0, ub = 1000000000;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) scanf("%lf%lf", &w[i], &p[i]);
  for (i = 0; i < 100; i++) {
    double mid = (lb + ub) / 2;
    if (concentrate(mid)) lb = mid;
    else ub = mid;
  }
  printf("%.10f\n", lb);
}
int compare(const void *a, const void *b)
{
  double ta = *(double*)a, tb = *(double*)b;
  if (ta > tb) return 1;
  else if (ta < tb) return -1;
  return 0;
}
int concentrate(double x)
{
  int i;
  double sum = 0.0;
  for (i = 0; i < n; i++) c[i] = w[i] * (p[i] - x);
  qsort(c, n, sizeof(double), compare);
  for (i = 0; i < k; i++) sum += c[n-1-i];
  return sum >= 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &n, &k);
   ^
./Main.c:14:27: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for (i = 0; i < n; i++) scanf("%lf%lf", &w[i], &p[i]);
                           ^