#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N_MAX 500
#define M_MAX 500
#define INF 10000000
#define SMAP(a, b) ((a)!=(b))&&((a)^=((b)^=((a)^= (b))))

typedef unsigned long long ull;
typedef   signed long long dll;

int n, m;

int i, j, k;
int a, b, c, d, e;

typedef struct {
	int in;
	int out;
} twoway;

char s[N_MAX][N_MAX + 1];
char t[N_MAX][N_MAX + 1];

void deb(){
	return;
}

void dfill(int edge, char ch){
	int i, j;
	if (edge == 0) {
		for (i = edge; i < n - edge; i++) {
			t[i][edge] = t[i][m - edge - 1] = 0;
		}
		for (j = edge; j < m - edge; j++) {
			t[edge][j] = t[n - edge - 1][j] = 0;
		}
	} else {
		for (i = edge; i < n - edge; i++) {
			t[i][edge] = t[i][edge - 1];
			t[i][m - edge - 1] = t[i][m - edge - 2];
		}
		for (j = edge; j < m - edge; j++) {
			t[edge][j] = t[edge - 1][j];
			t[n - edge - 1][j] = t[n - edge - 2][j];
		}
	}
}

void solve(){
	int result = 0;
	int prev = k;

	putchar('1');
	for (i = 1; i < n; i++) putchar('0');
	puts("7");

	return;
}

int main (void) {
	scanf("%d", &n);

	solve();
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:63:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^