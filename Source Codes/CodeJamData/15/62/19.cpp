#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <map>
#include <string>
#include <set>

typedef long long LL;
using namespace std;

const int MAX_N = 1000024;
LL MOD = 1000000007;
LL denum[MAX_N], fac[MAX_N];



struct Solution { LL gcd, x, y; };
Solution extendedEuclid(LL a, LL b) {
	LL q = a / b, r = a % b;
	if (r == 0) return Solution{ b, 0, 1 };
	Solution s = extendedEuclid(b, r);
	// now, we have
	// s.gcd = s.x * b + s.y * r
	//       = s.x * b + s.y * (a - q * b)
	//       = s.y * a + (s.x - q * s.y) * b
	return Solution{ s.gcd, s.y, s.x - q * s.y };
}

LL mult(LL a, LL b) {
	return (a*b + MOD) % MOD;
}

LL na(LL a, LL b) {
	Solution s = extendedEuclid(b, MOD);
	return mult(a, s.x);
}

LL sum(LL a, LL b) {
	return (a + b + MOD) % MOD;
}

LL sub(LL M) {
	return mult(fac[M], denum[M]);
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	fac[0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		fac[i] = mult(fac[i - 1], i);
	}
	denum[0] = 1;
	denum[2] = 1;
	for (int i = 3; i < MAX_N; i++) {
		denum[i] = sum(mult(denum[i - 1], i), ((i % 2) == 0) ? 1 : -1);
	}

	LL N, X;
	for (int cs = 1; cs <= T; cs++) {
		fprintf(stderr, "Case %d\n", cs);
		scanf("%lld %lld", &N, &X);
		LL sol = 0;
		LL nCk = 1;
		LL nPk = 1;
		for (LL K = 1; K < X; K++) {
			nCk = mult(nCk, (N - K + 1));
			nCk = na(nCk, K);

			nPk = mult(nPk, (N - K + 1));
		}
		for (LL K = X; K <= N; K++) {
			if (K != 0) {
				nCk = mult(nCk, (N - K + 1));
				nCk = na(nCk, K);

				nPk = mult(nPk, (N - K + 1));
			}

			sol = sum(sol, mult(mult(nCk, nPk), sub(N - K)));
		}
		printf("Case #%d: %lld\n", cs, sol);
	}
	return 0;
}