#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll M = 1e9+7, LIM = 1e4 + 10;
const ll mod = M;
ll inv[LIM] = {(ll)1e5, 1};

ll mem[10001][10001];
ll f(int N, int K) {
	ll p = 0;
	rep(i,1,N) {
		if (i == K || i == K-1) {
			p += 1;
		}
		else if (i > K) {
			p += mem[i-1][K];
		}
		else {
			p += mem[N-i-1][K-i-1];
		}
	}
	p %= mod;
	p *= inv[N-1];
	p %= mod;
	return p;
}

int main() {
	memset(mem, -2, sizeof mem);
	rep(i,2,LIM) inv[i] = M - (M / i) * inv[M % i] % M;

	cin.sync_with_stdio(false);
	cin.tie(0);

	for (int N = 0; N <= 10000; N++) {
#pragma omp parallel for
		for (int K = 1; K <= (N+2) / 2; K++) {
			mem[N][K] = f(N, K);
		}

		for (int K = (N+2) / 2 + 1; K <= N; K++) {
			int K2 = N+1 - K;
			if (K2 < K) {
				mem[N][K] = mem[N][K2];
			}
		}
	}
	cout << "DONE" << endl << endl;

	int T;
	cin >> T;
	vi ns(T), ks(T);
	rep(i,0,T) cin >> ns[i] >> ks[i];

	rep(i,0,T) {
		cout << "Case #" << i+1 << ": " << mem[ns[i]][ks[i]] << endl;
	}
}
