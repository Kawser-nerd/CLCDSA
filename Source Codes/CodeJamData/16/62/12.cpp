#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <tuple>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

using namespace std;
typedef long long LL;
typedef function<int(int)> VALF;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define SZ(V) ((int)((V).size()))

#define fr first
#define sd second

//const int MAX_N = 10000000 ;
const LL MOD = 1000000007;//10^9+7

const int MAX_N = 10017;
LL fact[MAX_N + 1];
int N, K;
LL MULT(LL a, LL b) {
	return (a*b) % MOD;
}
LL PLUS(LL a, LL b) {
	return (a + b) % MOD;
}
LL MINUS(LL a, LL b) {
	return (MOD + a - b) % MOD;
}

LL div(LL i) {
	if (i == 1) return 1;
	LL a = MOD / i;
	LL b = MOD % i;
	return (MOD - MULT(a, div(b))) % MOD;
}
LL DIV(LL a, LL b) {
	return MULT(a, div(b));
}
LL getImp(int N, int K) {
	int R = N - 2 * K;
	if (R < 0) return 0;
	if (K + 1 < R) return 0;
	//K+1 C R * K !
	LL res = 1;
	res = MULT(res, fact[K + 1]);
	res = DIV(res, fact[K + 1 - R]);
	res = DIV(res, fact[R]);
	res = MULT(res, fact[K]);
	return res;
}

//const int MAX_N = 10016;
LL *Dyn[MAX_N], *Nu1[MAX_N], *Nu2[MAX_N];
int main() {
	fact[0] = 1;
	for (int i = 1; i <= MAX_N; i++) {
		fact[i] = MULT(fact[i - 1], i);
	}
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 0; i < MAX_N; i++) {
		Dyn[i] = new LL[MAX_N];
		memset(Dyn[i], 0, sizeof(LL) * MAX_N);
		Nu1[i] = new LL[MAX_N];
		memset(Nu1[i], 0, sizeof(LL) * MAX_N);
		Nu2[i] = new LL[MAX_N];
		memset(Nu2[i], 0, sizeof(LL) * MAX_N);
	}
	for (int N = 2; N <MAX_N; N++) {
		for (int K = 1; K <= N; K++) {
			LL d = div((LL)(N - 1));
			if (K - 2 >= 0) {
				Dyn[N][K] = PLUS(Dyn[N][K], MULT(Nu1[N - 2][K - 2], d));
			}
			if (N - 2 >= K) {
				LL nu2 = MINUS(Nu2[N - 2][K], Nu2[K - 1][K]);
				Dyn[N][K] = PLUS(Dyn[N][K], MULT(nu2, d));
			}

			Dyn[N][K] = PLUS(Dyn[N][K], d);
			if (1 < K && K < N) {
				Dyn[N][K] = PLUS(Dyn[N][K], d);
			}
			Nu1[N][K] = PLUS(Dyn[N][K], Nu1[N - 1][K - 1]);
			Nu2[N][K] = PLUS(Dyn[N][K], Nu2[N - 1][K]);
		}
	}
	fprintf(stderr, "Okay");
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &K);
		printf("Case #%d: %lld\n", tc, Dyn[N][K]);
	}
	return 0;
}