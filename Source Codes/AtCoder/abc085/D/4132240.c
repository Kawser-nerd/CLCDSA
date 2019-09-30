#include <stdio.h>
#include <stdlib.h>

const int comp_double(const void* p, const void* q)
{
  if( *(double*)p > *(double*)q ) return -1;
  if( *(double*)p < *(double*)q ) return 1;
  return 0;
}

int main()
{

  size_t N;
  double H = 0.0, damage = 0.0;
  int count = 0;
  scanf("%zi %lf%*[^\n]%*c", &N, &H);

  double* a = malloc(N * sizeof(double));
  double* b = malloc(N * sizeof(double));
  for (size_t i = 0; i < N; i++)
  {
    scanf("%lf %lf%*[^\n]", &a[i], &b[i]);
    getchar();
  }
  qsort(a, N, sizeof(double), comp_double), qsort(b, N, sizeof(double), comp_double);
  for (size_t i = 0; i < N; i++)
  {
    if (b[i] <= a[0]) break;
    damage += b[i];
    count++;
    if (damage >= H) break;
  }
  while (damage < H) 
  {
    damage += a[0];
    count++;
  }
  printf("%i\n", count);
  free(a);
  free(b);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:31: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
   qsort(a, N, sizeof(double), comp_double), qsort(b, N, sizeof(double), comp_double);
                               ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘const int (*)(const void *, const void *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:26:73: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
   qsort(a, N, sizeof(double), comp_double), qsort(b, N, sizeof(double), comp_double);
                                                                         ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘const int (*)(const void ...