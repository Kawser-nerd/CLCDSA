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

int main() {
	string fname = "A-large";
	freopen((fname+".in").c_str(), "r", stdin);
	freopen((fname+".out").c_str(), "w", stdout);
	int T;
	scanf("%d", &T);
	for (int u = 1; u <= T; ++u) {
		int N, K;
		scanf("%d%d", &N, &K);
		bool r = true;
		for (int i = 0; i < N; ++i)
			r = r && (K & (1 << i));
		if (r) printf("Case #%d: ON\n", u);
		else printf("Case #%d: OFF\n", u);
	}

	return 0;
}
