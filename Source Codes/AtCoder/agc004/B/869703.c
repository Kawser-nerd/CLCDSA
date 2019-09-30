#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long a[2010], c[2010], min[2010]={0}, P=0, r=0, t[2010][2010]={{0}}, x;

int llintcmp(const void *a, const void *b) {
	long long c = *(long long *)a-*(long long *)b;
	if (c>0) return 1;
	else if (c==0) return 0;
	else return -1;
}

int main() {
	int b, i, j, k, N;
	scanf("%d%lld", &N, &x);
	for (i=0;i<N;i++) scanf("%lld", &a[i]);

	c[0] = 0;
	for (i=0;i<N;i++) min[i] = a[i];
	for (i=0;i<N;i++) c[0] += a[i];
	for (k=1;k<N;k++) {
		c[k] = x*k;
		for (i=0;i<N;i++) {
			if (i>=k) b = i-k; else b = N+i-k;
			if (min[i] > a[b]) min[i] = a[b];
		}
		for (i=0;i<N;i++) c[k] += min[i];
	}
	qsort(c, N, sizeof(long long), llintcmp);

	printf("%lld\n", c[0]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%lld", &N, &x);
  ^
./Main.c:17:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i=0;i<N;i++) scanf("%lld", &a[i]);
                    ^