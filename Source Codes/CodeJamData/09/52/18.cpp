//	GCJ 2009 Round 3 (B)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
int in_c() { int c; while ((c = getchar()) <= ' ') { if (!~c) throw ~0; } return c; }
int in() {
	int x = 0, c;
	while ((uint)((c = getchar()) - '0') >= 10) { if (c == '-') return -in(); if (!~c) throw ~0; }
	do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
	return x;
}

const int MO = 10009;

char buf[10010];
int M, T[10], S[10][10];

int N, K;
int A[110][30];

int nk[110];

int calc(int a = 26, int b = 26, int c = 26, int d = 26) {
	int ret = 0, i;
	for (i = 0; i < N; ++i) {
		ret += A[i][a] * A[i][b] * A[i][c] * A[i][d];
	}
	return ret % MO;
}

int main() {
	int k;
	int i;
	int x, y;
	
	for (int TC = in(), tc = 0; TC--; ) {
		printf("Case #%d:", ++tc);
		scanf("%s%d%d", buf, &K, &N);
		for (char *p = buf; *p; ++p) {
			if (*p == '+') *p = ' ';
		}
		istringstream ss(buf);
		string str;
		for (M = 0; ss >> str; ++M) {
			T[M] = str.length();
			for (y = 0; y < T[M]; ++y) {
				S[M][y] = str[y] - 'a';
			}
		}
		
		memset(A, 0, sizeof(A));
		for (i = 0; i < N; ++i) {
			scanf("%s", buf);
			for (char *p = buf; *p; ++p) {
				++A[i][*p - 'a'];
			}
			A[i][26] = 1;
		}
		
		nk[0] = 1;
		for (k = 1; k <= K; ++k) {
			nk[k] = nk[k - 1] * N % MO;
		}
		
		for (k = 1; k <= K; ++k) {
			int ans = 0, tmp;
			for (x = 0; x < M; ++x) {
				switch (T[x]) {
					case 1: {
						tmp = calc(S[x][0]) % MO;
						tmp = tmp * nk[k - 1] % MO;
						tmp = tmp * k % MO;
						ans += tmp;
						ans %= MO;
					} break; case 2: {
						tmp = calc(S[x][0], S[x][1]) % MO;
						tmp = tmp * nk[k - 1] % MO;
						tmp = tmp * k % MO;
						ans += tmp;
						ans %= MO;
						
						if (k < 2) continue;
						tmp = calc(S[x][0]) * calc(S[x][1]) % MO;
						tmp = tmp * nk[k - 2] % MO;
						tmp = tmp * (k * (k - 1)) % MO;
						ans += tmp;
						ans %= MO;
					} break; case 3: {
						tmp = calc(S[x][0], S[x][1], S[x][2]) % MO;
						tmp = tmp * nk[k - 1] % MO;
						tmp = tmp * k % MO;
						ans += tmp;
						ans %= MO;
						
						if (k < 2) continue;
						tmp = 0;
						tmp += calc(S[x][0], S[x][1]) * calc(S[x][2]) % MO;
						tmp += calc(S[x][0], S[x][2]) * calc(S[x][1]) % MO;
						tmp += calc(S[x][1], S[x][2]) * calc(S[x][0]) % MO;
						tmp = tmp * nk[k - 2] % MO;
						tmp = tmp * (k * (k - 1)) % MO;
						ans += tmp;
						ans %= MO;
						
						if (k < 3) continue;
						tmp = calc(S[x][0]) * calc(S[x][1]) % MO * calc(S[x][2]) % MO;
						tmp = tmp * nk[k - 3] % MO;
						tmp = tmp * (k * (k - 1) * (k - 2)) % MO;
						ans += tmp;
						ans %= MO;
						
					} break; case 4: {
						tmp = calc(S[x][0], S[x][1], S[x][2], S[x][3]) % MO;
						tmp = tmp * nk[k - 1] % MO;
						tmp = tmp * k % MO;
						ans += tmp;
						ans %= MO;
						
						if (k < 2) continue;
						tmp = 0;
						tmp += calc(S[x][0], S[x][1], S[x][2]) * calc(S[x][3]) % MO;
						tmp += calc(S[x][0], S[x][1], S[x][3]) * calc(S[x][2]) % MO;
						tmp += calc(S[x][0], S[x][2], S[x][3]) * calc(S[x][1]) % MO;
						tmp += calc(S[x][1], S[x][2], S[x][3]) * calc(S[x][0]) % MO;
						tmp += calc(S[x][0], S[x][1]) * calc(S[x][2], S[x][3]) % MO;
						tmp += calc(S[x][0], S[x][2]) * calc(S[x][1], S[x][3]) % MO;
						tmp += calc(S[x][0], S[x][3]) * calc(S[x][1], S[x][2]) % MO;
						tmp = tmp * nk[k - 2] % MO;
						tmp = tmp * (k * (k - 1)) % MO;
						ans += tmp;
						ans %= MO;
						
						if (k < 3) continue;
						tmp = 0;
						tmp += calc(S[x][0], S[x][1]) * calc(S[x][2]) % MO * calc(S[x][3]) % MO;
						tmp += calc(S[x][0], S[x][2]) * calc(S[x][1]) % MO * calc(S[x][3]) % MO;
						tmp += calc(S[x][0], S[x][3]) * calc(S[x][1]) % MO * calc(S[x][2]) % MO;
						tmp += calc(S[x][1], S[x][2]) * calc(S[x][0]) % MO * calc(S[x][3]) % MO;
						tmp += calc(S[x][1], S[x][3]) * calc(S[x][0]) % MO * calc(S[x][2]) % MO;
						tmp += calc(S[x][2], S[x][3]) * calc(S[x][0]) % MO * calc(S[x][1]) % MO;
						tmp = tmp * nk[k - 3] % MO;
						tmp = tmp * (k * (k - 1) * (k - 2)) % MO;
						ans += tmp;
						ans %= MO;
						
						if (k < 4) continue;
						tmp = calc(S[x][0]) * calc(S[x][1]) % MO * calc(S[x][2]) % MO * calc(S[x][3]) % MO;
						tmp = tmp * nk[k - 4] % MO;
						tmp = tmp * (k * (k - 1) * (k - 2) * (k - 3)) % MO;
						ans += tmp;
						ans %= MO;
						
					}
				}
			}
			printf(" %d", ans);
		}
		puts("");
		
	}
	
	
	return 0;
}

