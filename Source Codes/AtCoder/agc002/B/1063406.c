#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N_MAX 100000
#define M_MAX 100000
#define INF 10000000
#define SMAP(a, b) ((a)!=(b))&&((a)^=((b)^=((a)^= (b))))

typedef unsigned long long ull;
typedef   signed long long dll;

int balls[N_MAX];
bool b[N_MAX];
int n, m;

int i, j, k;

typedef struct {
	int in;
	int out;
} twoway;

twoway x[M_MAX];

void deb(){
	return;
}

void solve(){
	int result = 0;

	for (i = 0; i < n; i++) {
		balls[i] = 1;
		b[i] = !i;
	}

	for (i = 0; i < m; i++) {
		balls[x[i].in]--;
		balls[x[i].out]++;

		if (b[x[i].in]) b[x[i].out] = 1;
		if (!balls[x[i].in]) b[x[i].in] = 0;
	}

	for (i = 0; i < n; i++) {
		if (b[i]) result++;
	}
	printf("%d\n", result);
	return;
}

int main (void) {
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &x[i].in, &x[i].out);
		x[i].in--;
		x[i].out--;
	}

		// puts("deb line A");

	solve();
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:54:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &n, &m);
  ^
./Main.c:56:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &x[i].in, &x[i].out);
   ^