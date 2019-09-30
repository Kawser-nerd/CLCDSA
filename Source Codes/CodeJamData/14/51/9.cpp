#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef long long int64;

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		printf("Case #%d: ", nc);
		int N, p, q, r, s;
		cin >> N >> p >> q >> r >> s;
		vector<int> a(N);
		vector<int64> S(N + 1);
		for (int i = 0; i < N; ++i) {
			a[i] = (1LL * i * p + q) % r + s;
		}
		S[0] = 0;
		for (int i = 1; i <= N; ++i) {
			S[i] = S[i - 1] + a[i - 1];
		}
		//fix [a,b) S[a],S[b]-S[a],S[N]-S[b]
		//minimize the max of it
		int64 ans = 1LL << 60;
		int b = 0;
		for (int a = 0; a < N; ++a) {
			b = max(b, a + 1);
			while (b < N && S[b] - S[a] < S[N] - S[b])
				++b;
			int64 t = max(S[b] - S[a], S[N] - S[b]);
			if (b - 1 > a)
				t = min(t, max(S[b - 1] - S[a], S[N] - S[b - 1]));
			ans = min(ans, max(S[a], t));
		}
		printf("%0.15lf\n", 1.0 * (S[N] - ans) / S[N]);
	}
}
