#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define DEBUG_FLAG 1
#if DEBUG_FLAG
#define dbg(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define cdbg(...) cerr << __VA_ARGS__ << endl
#else
#define debug(r)
#define dbg(...)
#endif

int R, K, N;
int a[1024];
int next[1024];
int cnt[1024];

void compute() {
	for (int i = 0; i < N; ++i) {
		cnt[i] = 0;
		next[i] = i;
		for (int j = i; j != i+N; ++j) {
			int k = j%N;
			if (cnt[i] + a[k] <= K) {
				cnt[i] += a[k];
			} else {
				next[i] = k;
				break;
			}
		}
	}
}

int main() {
	string fname = "C-large";
	freopen((fname+".in").c_str(), "r", stdin);
	freopen((fname+".out").c_str(), "w", stdout);
	int T;
	scanf("%d", &T);
	for (int u = 1; u <= T; ++u) {
		scanf("%d%d%d", &R, &K, &N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &a[i]);
		compute();
		int cur = 0;
		long long r = 0;
		for (int i = 0; i < R; ++i) {
			r += cnt[cur];
			cur = next[cur];
		}
		printf("Case #%d: %lld\n", u, r);
	}

	return 0;
}
