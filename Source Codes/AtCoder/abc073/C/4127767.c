#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const int *a,const int *b){
	return *a - *b;
}

int main(int argc, char const *argv[]){
	int N,*A,ans = 0;
	scanf("%d",&N);
	A = (int *)malloc(sizeof(int) * N);


	for(int i = 0;i < N; ++i)  scanf("%d",&A[i]);
	qsort(A, N, sizeof(int), comp);

	for(int i = 0;i < N; ++i){
		if(A[i] == A[i + 1])  ++i;
		else  ++ans;
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:27: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
  qsort(A, N, sizeof(int), comp);
                           ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const int *, const int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:15:29: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(int i = 0;i < N; ++i)  scanf("%d",&A[i]);
                             ^