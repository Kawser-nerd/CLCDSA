#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n,m,A;

int a[10000];

void init() {
	int i, j;
	memset(a, 0xff, sizeof(a));
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			a[i * j] = i;
		}
	}
}

int func(int k, int t) {
	if (t == 0) return a[k];
	if (k == 0) return 0;
	return k / a[k];
}

int main() {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int testcases;
	scanf("%d", &testcases);
	int i, j, k, z;
	init();
	for (z = 0; z < testcases; z++) {
		printf("Case #%d: ", z + 1);
		scanf("%d%d%d",&n,&m,&A);
		if (A > n * m) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		init();
		k = n * m;
		for (i = 0; i <= k - A; i++) {
			if (a[i] >= 0 && a[i + A] >= 0) {
				printf("0 0 %d %d %d %d\n", func(i, 0), func(i + A, 1), func(i + A, 0), func(i, 1));
				break;
			}
		}
	}
	return 0;
}
