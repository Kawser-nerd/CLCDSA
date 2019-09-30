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

long long N, cnt[26];
long long ans;
char S[100001];

int main(void) {
	scanf("%lld", &N);
	scanf("%s", S);

	for (int i = 0; i < 26; i++) {
		cnt[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		cnt[S[i] - 'a'] += 1;
	}

	ans = 1;
	for (int i = 0; i < 26; i++) {
		ans = mod_prod(ans, cnt[i] + 1);
	}
	ans = (ans - 1 + 1000000007) % 1000000007;

	printf("%lld\n", ans);
}