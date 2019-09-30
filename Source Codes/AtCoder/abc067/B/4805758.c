#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long

// qsort(array, size, sizeof(int),comp);
int comp(const int *a,const int *b){
	return (*b - *a);
}

int main(int argc, char const *argv[]){
	int n,k,*l;
	int ans = 0;
	scanf("%d%d",&n,&k);
	l = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)	scanf(" %d",&l[i]);
	qsort(l,n,sizeof(int),comp);
	for (int i = 0; i < k; ++i)	ans += l[i];
	printf("%d\n",ans);	
} ./Main.c: In function ‘main’:
./Main.c:21:24: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
  qsort(l,n,sizeof(int),comp);
                        ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const int *, const int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:20:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (int i = 0; i < n; ++i) scanf(" %d",&l[i]);
                              ^