#include <stdio.h>

typedef long long ll;

int x[200], y[200];

int N, M;

bool valid[(1 << 16)];
bool contain(int mask,int pos);

ll dp[(1 << 16)];

int main() {

	scanf("%d %d",&N,&M);

	int i;

	for (i = 0; i < M; i++) {
		scanf("%d %d",&x[i],&y[i]);
		x[i]--;
		y[i]--;
	}

	int mask;

	for (mask = 0; mask < (1 << N); mask++) {
		valid[mask] = true;
		for (i = 0; i < M; i++) {
			if (contain(mask, y[i]) && !contain(mask, x[i])) {
				valid[mask] = false;
			}
		}
	}

	dp[0] = 1;

	for (mask = 1; mask < (1 << N); mask++) {
		if (valid[mask]) {
			for (i = 0; i < N; i++) {
				if (contain(mask, i) && valid[mask ^ (1 << i)]){
						dp[mask] += dp[mask ^ (1 << i)];
				}
			}
		}

	}
	printf("%lld\n",dp[(1<<N)-1]);

	return 0;
}
bool contain(int mask, int pos) {
	return ((mask&(1 << pos)) != 0);
}