#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <assert.h>
#include <math.h>
#include <string.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)
#define MOD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,n) for (int i = 0; i < (n); i++)

int T, N, X, Y, s, r;

long double binom[9000][9000];

long double p(int k) {
	if (k+(s+1) > r)
		return binom[r][k];
	else if (k+(s+1) < r)
		return 0;
	long double w = 1;
	for (int ks = k+1; ks <= r; ks++)
		w -= p(ks);
	return w;
}

int main() {
	for (int n = 0; n < 9000; n++) {
		binom[n][0] = binom[n][n] = pow(2, -n);
		for (int k = 1; k < n; k++)
			binom[n][k] = (binom[n-1][k-1]+binom[n-1][k])/2;
	}
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d%d%d", &N, &X, &Y);
		if (X < 0)
			X = -X;
		s = 1;
		while((s+2)*(s+3)/2 <= N)
			s += 2;
		r = N-s*(s+1)/2;
		long double erg = 0;
		if (X+Y <= s-1)
			erg = 1;
		else if (X+Y >= s+3)
			erg = 0;
		else if (X == 0)
			erg = 0;
		else {
// 			printf("daz(r=%d,s=%d) ", r, s);
			for (int k = Y+1; k <= r; k++)
				erg += p(k);
		}
		printf("%.9Lf\n", erg);
	}
	return 0;
}
