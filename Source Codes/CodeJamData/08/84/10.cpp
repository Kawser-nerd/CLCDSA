#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

typedef pair <int, int> PII;
typedef long long llong;
typedef vector <int> VI;
typedef vector <string> VS;

#define MP make_pair
#define PB push_back
#define x first
#define y second
#define FORI(p, X) for(__typeof((X).begin()) p = (X).begin(); p != (X).end(); ++p)
#define ALL(X) (X).begin(), (X).end()

const int MOD = 30031;
const int NMAX = 1024;

int N, K, P, NC;
VI T;

int D[NMAX][NMAX], R[NMAX][NMAX];

int get(int x) {
	assert(binary_search(ALL(T), x));
	return lower_bound(ALL(T), x) - T.begin();
}

void out(int D[NMAX][NMAX]) {
	int i, j;

	for (i = 0; i < NC; ++i) {
		for (j = 0; j < NC; ++j) {
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}

}

void prep(void) {
	int i, stop, j, c, u, v;

	stop = 1 << P;

	T.clear();
	for (i = 0; i < stop; ++i) {
		c = 0;

		for (j = 0; j < P; ++j)
			if ((i & (1 << j))) ++c;

		if ((i & 1) && (c == K)) T.PB(i);
	}

	NC = T.size();

	memset(D, 0x00, sizeof(D));

	for (i = 0; i < NC; ++i) {
		u = T[i];

		for (j = 1; j < P; ++j) 
			if (!(u & (1 << j))) {
				v = (u | (1 << j)) >> 1;
				if (v & 1) ++D[get(u)][get(v)];
			}
		v = (u | (1 << P)) >> 1;
		if (v & 1) ++D[get(u)][get(v)];
	}

//	FORI(p, T) printf("%d ", *p);
//	printf("\n");

//	out(D);
}

void mult(int A[NMAX][NMAX], int B[NMAX][NMAX], int C[NMAX][NMAX]) {
	int D[NMAX][NMAX];
	int i, j, k;

	memset(D, 0x00, sizeof(D));

	for (i = 0; i < NC; ++i)
		for (j = 0; j < NC; ++j)
			for (k = 0; k < NC; ++k)
				D[i][j] = (D[i][j] + A[i][k] * B[k][j]) % MOD;
	
	memcpy(C, D, sizeof(D));
}

void solve(void) {
	int i;

	N = N - K;

//	printf("N = %d\n", N);

	memset(R, 0x00, sizeof(R));
	for (i = 0; i < NC; ++i)
		R[i][i] = 1;

//	out(D);
	for (; N; N >>= 1, mult(D, D, D))
		if (N & 1)
			mult(D, R, R);
	
//	out(R);
}

int main(void) {
	freopen("large.in", "rt", stdin);
	freopen("test.out", "wt", stdout);

	int cn, CN;
//	int i, o;

	scanf(" %d", &CN);

	for (cn = 1; cn <= CN; ++cn) {

		scanf(" %d %d %d", &N, &K, &P);

		prep();

		solve();
/*
		for (i = 0, o = 0; i < NC; ++i)
			o = (o + R[i][0]) % MOD;
*/		
		printf("Case #%d: %d\n", cn, R[0][0]);
	}

	return 0;
}
