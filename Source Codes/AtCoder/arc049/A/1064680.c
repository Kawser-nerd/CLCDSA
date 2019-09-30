#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N_MAX 100000
#define M_MAX 100000
#define INF 10000000
#define SMAP(a, b) ((a)!=(b))&&((a)^=((b)^=((a)^= (b))))

typedef unsigned long long ull;
typedef   signed long long dll;

int n, m;

int i, j, k;

typedef struct {
	int in;
	int out;
} twoway;

char s[N_MAX + 1];
bool b[N_MAX];
int a[M_MAX];

void deb(){
	return;
}

// void dfill(int edge, char ch){
// 	int i, j;
// 	if (edge == 0) {
// 		for (i = edge; i < n - edge; i++) {
// 			t[i][edge] = t[i][m - edge - 1] = 0;
// 		}
// 		for (j = edge; j < m - edge; j++) {
// 			t[edge][j] = t[n - edge - 1][j] = 0;
// 		}
// 	} else {
// 		for (i = edge; i < n - edge; i++) {
// 			t[i][edge] = t[i][edge - 1];
// 			t[i][m - edge - 1] = t[i][m - edge - 2];
// 		}
// 		for (j = edge; j < m - edge; j++) {
// 			t[edge][j] = t[edge - 1][j];
// 			t[n - edge - 1][j] = t[n - edge - 2][j];
// 		}
// 	}
// }

void solve(){
	if (a[0]) {
		k = 0;
	} else {
		k = 1;
		putchar('\"');
	}

	for (i = 0; s[i]; i++) {
		putchar(s[i]);
		if (a[k] - 1 == i) {
			putchar('\"');
			k++;
		}
	}

	putchar('\n');

	return;
}

int main (void) {
	scanf("%s", s);
	scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);

	solve();
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:73:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^
./Main.c:74:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
  ^