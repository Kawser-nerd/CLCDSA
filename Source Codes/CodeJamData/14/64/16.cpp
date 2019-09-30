#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;


int arr[1005];
char buf[105][105];

bool Check(const vector<int> &v, int desired) {
	int cur = v[0];
	for (int i = 1; i < v.size(); ++i) {
		if (buf[cur][v[i]] == 'N') {
			cur = v[i];
		}
	}
	return cur == desired;
}

void Solve() {
	int n, v;
	scanf("%d%d", &n, &v);
	for (int i = 0; i < n; ++i) {
		scanf("%s", buf[i]);
	}
	vector<int> p;
	for (int i = 0; i < n; ++i) {
		p.push_back(i);
	}

	vector<int> order;
	do {
		if (Check(p, v)) {
			order = p;
			break;
		}
	} while (next_permutation(p.begin(), p.end()));
	if (order.empty()) {
		puts("IMPOSSIBLE");
	} else {
		for (int i = 0; i < order.size(); ++i) {
			printf("%d ", order[i]);
		}
		puts("");
	}
}

int main() {
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	int tc = 0;
	int T;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++tc);
		Solve();
	}    
	return 0;
}