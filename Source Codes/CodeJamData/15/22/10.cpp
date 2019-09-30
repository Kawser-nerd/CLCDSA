#include<bits/stdc++.h>
using namespace std;

const int MAXR = 20000;
const int MAXC = 20000;
const int MAXN = 20000;

int go(int R, int C, int N) {
	if(N <= (R * C + 1) / 2) {
		return 0;
	}
	if(C < R) swap(R, C);
	assert(R <= C);
	if(R == 1) {
		return C - 1 - (C - N) * 2;
	} else if(R == 2) {
		assert(N > C);
		return (N - C) * 3 - min(N - C, 2);
	} else {
		assert(R >= 3);
		assert(C >= 3);

		int res = R * (C - 1) + C * (R - 1);
		int M = R * C - N;
		int v = min(M, ((R - 2) * (C - 2) + 1) / 2);
		M -= v;
		//cerr << v << '\n';
		res -= 4 * v;

		v = min(M, R + C - (R * C) % 2 * 2 - 4);
		M -= v;
		//cerr << v << '\n';
		res -= 3 * v;

		v = min(M, ((R * C) % 2 + 1) * 2);
		M -= v;
		//cerr << v << '\n';
		res -= 2 * v;

		assert(M == 0);

		if(N - (R * C + 1) / 2 <= R + C - 2) {
			// can get by just filling in corners/edges
			int c = N - (R * C + 1) / 2;
			res = min(res, c * 3 - min(c, (1 - (R * C) % 2) * 2));
		}

		return res;
	}
}

int dsum(int a) { return a ? dsum(a & (a - 1)) + 1 : 0; }

int slow(int R, int C, int N) {
	int res = R * C * 2 - R - C;
	for(int m = 0; m < (1 << (R * C)); m++) {
		if(dsum(m) != N) continue;
		int cnt = 0;
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				if(i + 1 < R) {
					if((m & (1 << (i * C + j))) && (m & (1 << ((i + 1) * C + j)))) cnt++;
				}
				if(j + 1 < C) {
					if((m & (1 << (i * C + j))) && (m & (1 << (i * C + (j + 1))))) cnt++;
				}
			}
		}
		res = min(res, cnt);
	}
	return res;
}

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		int R, C, N; cin >> R >> C >> N;
		int res = go(R, C, N);
		//int tmp = slow(R, C, N); assert(res == tmp);
		cout << "Case #" << t << ": " << res << '\n';
	}
	return 0;
}
