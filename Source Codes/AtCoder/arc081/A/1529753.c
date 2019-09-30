#include <stdio.h>
#include <stdlib.h>
#define MAXN 100100
int cmp(const int* a, const int* b) {
	return *a - *b;
}
int main(void) {
	static int a[MAXN];
	static int cnt[MAXN];
	static long long map[MAXN];
	int i, n, pos = 0;
	int x = -1, y = -1;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), cmp);
	for(map[pos] = a[pos], cnt[pos] = i = 1; i < n; i++) {
		if(a[i] == a[i - 1]) cnt[pos]++;
		else {
			pos++;
			map[pos] = a[i];
			cnt[pos] = 1;
		}
	}
	for(int i = n - 1; i >= 0; i--) {
		if(cnt[i] >= 4 && x == -1 && y == -1) {
			x = y = i;
			break;
		}
		if(cnt[i] >= 2 && x != -1) {
			y = i;
			break;
		}
		if(cnt[i] >= 2 && x == -1) {
			x = i;
		}
	}
	if(x == -1 && y == -1) puts("0");
	else printf("%lld\n", map[x] * map[y]);
	return 0;	
} ./Main.c: In function ‘main’:
./Main.c:15:27: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
  qsort(a, n, sizeof(int), cmp);
                           ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const int *, const int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:14:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i = 0; i < n; i++) scanf("%d", &a[i]);
                         ^