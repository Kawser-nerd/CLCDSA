#include <stdio.h>
#include <stdbool.h>

#define N_MAX 8
#define INF 1145141919
#define SMAP(a, b) ((a)!=(b))&&((a)^=((b)^=((a)^= (b))))

#define IMP "Impossible"
#define POS "Possible"

typedef unsigned long long ull;

int i, j;

int n, m;
int k;

int h, w;

ull t[N_MAX];
char d[N_MAX + 1][N_MAX + 2];

void solve(){
	int result = 0;
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (d[i][j] == '#') result++;
		}
	}
	puts((result == h + w - 1) ? POS : IMP);
	return;
}

int main (void) {
	scanf("%d%d", &h, &w);
	for (i = 0; i < h; i++) scanf("%s", d[i]);

	solve();
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &h, &w);
  ^
./Main.c:36:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i = 0; i < h; i++) scanf("%s", d[i]);
                          ^