#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include <random>
using namespace std;

long long mod_prod(long long a, long long b) {
	long long ret;
	ret = (a * b) % 1000000007;
	return ret;
}

long long N, C[200000], D[200000];
long long pos;
long long ans_1[200000], ans_2[200000], sum[200000];
int main(void) {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &C[i]);
	}
	pos = 1;
	D[0] = C[0];
	for (int i = 1; i < N; i++) {
		if (C[i] != C[i - 1]) {
			D[pos] = C[i];
			pos++;
		}
	}
	for (int i = 0; i < 200000; i++) {
		sum[i] = 0;
	}
	ans_1[0] = 1;
	ans_2[0] = 0;
	sum[D[0]] = 1;
	for (int i = 1; i < pos; i++) {
		ans_1[i] = (ans_1[i - 1] + ans_2[i - 1]) % 1000000007;
		ans_2[i] = sum[D[i]];
		sum[D[i]] = (sum[D[i]] + ans_1[i]) % 1000000007;
		//printf("%lld %lld %lld\n", ans_1[i], ans_2[i], sum[D[i]]);
	}
	printf("%lld\n", (ans_1[pos - 1] + ans_2[pos - 1]) % 1000000007);
}