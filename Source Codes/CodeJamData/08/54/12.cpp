#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int mod = 10007;
int inv[10007];
short mult[100000000], rem[100000000];

void init() {
	int i, j;
	mult[0] = 0;
	rem[0] = 1;
	mult[1] = 0;
	rem[1] = 1;
	for (i = 2; i < 100000000; i++) {
		j = i;
		mult[i] = mult[i - 1];
		if (j % mod == 0) {
			j /= mod;
			mult[i]++;
		}
		rem[i] = (__int64)rem[i-1] * j % mod;
		if (rem[i] == 0) {
			printf("%d %d %d\n",i,j,rem[i-1]);
			exit(0);
		}
	}
	for (i = 1; i < 10007; i++) {
		for (j = 1; j < 10007; j++) {
			if (i * j % 10007 == 1) {
				inv[i] = j;
			}
		}
	}
}

int ways(int x,int y) {
	int t;
	if ((x + y)%3 != 0) return 0;
	t = (x + y) / 3;
	x -= t;
	y -= t;
	if (x < 0 || y < 0) return 0;
	if (mult[x+y] > mult[x] + mult[y]) return 0;
	return (int)rem[x+y] * inv[rem[x]] % mod * inv[rem[y]] % mod;
}

int n, m, k, x[20], y[20], tot;

void solve(int mask) {
	int i, j, ret, tx[12], ty[12];
	tx[0] = 0;
	ty[0] = 0;
	j = 1;
	for (i = 0; i < k; i++) if (mask & (1 << i)) {
		tx[j] = x[i];
		ty[j++] = y[i];
	}
	tx[j] = n - 1;
	ty[j++] = m - 1;
	for (i = 0; i < j - 1; i++) if (ty[i+1] < ty[i]) return;
	ret = 1;
	for (i = 0; i < j - 1; i++) {
		ret = (ret * ways(tx[i+1] - tx[i], ty[i+1]-ty[i])) % mod;
	}
	if (j % 2 == 0) tot += ret;
	else tot -= ret;
}

int main() {
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	int testcases;
	scanf("%d", &testcases);
	int z, i, j;
	init();
	for (z = 0; z < testcases; z++) {
		printf("Case #%d: ", z+1);
		scanf("%d%d%d",&n,&m,&k);
		for (i = 0; i < k; i++) {
			scanf("%d%d",&x[i],&y[i]);
			x[i]--;
			y[i]--;
		}
		for (i = 0; i < k; i++) {
			for (j = 0; j < i; j++) {
				if (x[i] < x[j]) {
					swap(x[i],x[j]);
					swap(y[i],y[j]);
				}
			}
		}
		tot = 0;
		for (i = 0; i < (1 << k); i++) {
			solve(i);
		}
		tot = (tot % mod + mod) % mod;
		printf("%d\n",tot);
	}
	return 0;
}
