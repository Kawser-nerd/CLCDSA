#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int T;
int N, F[1010];
bool ep[1010];
int dist[1010];
int dmax[1010];

int solve_cycle()
{
	int ret = 0;
	for (int i = 0; i < N; ++i) {
		int p = i;
		for (int j = 1; j <= 2 * N; ++j) {
			p = F[p];
			if (p == i) {
				ret = max(ret, j);
				break;
			}
		}
	}
	return ret;
}

int solve_chain()
{
	int ret = 0;
	for (int i = 0; i < N; ++i) {
		if (F[F[i]] == i) ep[i] = true;
		else ep[i] = false;
		dmax[i] = 0;
	}
	for (int i = 0; i < N; ++i) {
		int p = i;
		dist[i] = -1;
		for (int j = 0; j <= 2 * N; ++j) {
			if (ep[p]) {
				dist[i] = j;
				dmax[p] = max(dmax[p], j);
				break;
			}
			p = F[p];
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (i == F[F[i]]) {
			ans += dmax[i] + 1;
		}
	}
	return ans;
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", F + i);
			--F[i];
		}

		int ret = 0;
		ret = max(ret, solve_cycle());
		ret = max(ret, solve_chain());
		printf("Case #%d: %d\n", t, ret);
	}

	return 0;
}
