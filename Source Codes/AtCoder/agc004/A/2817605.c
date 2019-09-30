#include <stdio.h>
#include <stdlib.h>

int q(const long *a,const long *b)
{
	return *a-*b;
}

int main(void)
{
	long n[3],i;
	for(i=0;i<3;i++)scanf("%ld",&n[i]);
	qsort(n,3,sizeof(long),q);
	printf("%ld",n[0]*n[1]*((n[2]+1)/2)-n[0]*n[1]*(n[2]/2));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:25: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
  qsort(n,3,sizeof(long),q);
                         ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const long int *, const long int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:12:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<3;i++)scanf("%ld",&n[i]);
                  ^