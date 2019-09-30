#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long
#define TBMod 1000000007

// qsort(array, size, sizeof(int),comp);
int comp(const int *a,const int *b){
	return (*a - *b);
}

int main(int argc, char const *argv[])
{
	int n,*a;
	scanf("%d",&n);
	a = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)	scanf(" %d",&a[i]);
	qsort(a,n,sizeof(int),comp);
	printf("%d\n", a[n - 1] - a[0]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:24: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
  qsort(a,n,sizeof(int),comp);
                        ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const int *, const int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:21:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (int i = 0; i < n; ++i) scanf(" %d",&a[i]);
                              ^