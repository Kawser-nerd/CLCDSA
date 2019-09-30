#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N_MAX 100000
#define M_MAX 1000
#define INF 10000000
#define SMAP(a, b) ((a)!=(b))&&((a)^=((b)^=((a)^= (b))))

typedef unsigned long long ull;
typedef   signed long long dll;

dll a[N_MAX];
int n, m;

int i, j, k;

void deb(){
	return;
}

ull abs(dll n){
	return (ull)((n > 0) ? n : -n);
}

void solve(){
	dll result = 0;
	dll total = 0;
	dll rangetot = 0;
	for (i = 0; i < n; i++) {
		if (a[i] >= 0) total += a[i];
	}
	for (i = 0; i < k; i++) {
		if (a[i] >= 0) total -= a[i];
		rangetot += a[i];
	}

	// puts("deb line B");

	while (i <= n) {
		ull candid;
		candid = total;
		if (rangetot > 0) candid += rangetot;
		if (result < candid) result = candid;

		if (a[i-k] >= 0) total += a[i-k];
		rangetot -= a[i-k];
		if (a[i] >= 0) total -= a[i];
		rangetot += a[i];
		i++;
	}

	printf("%lld\n", result);
	return;
}

int main (void) {
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++) scanf("%lld", &a[i]);

		// puts("deb line A");

	solve();
	return 0;
} ./Main.c:22:5: warning: conflicting types for built-in function ‘abs’
 ull abs(dll n){
     ^
./Main.c: In function ‘main’:
./Main.c:58:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &n, &k);
  ^
./Main.c:59:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i = 0; i < n; i++) scanf("%lld", &a[i]);
                          ^