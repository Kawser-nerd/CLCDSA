#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MX = 100005;

typedef long long LL;

const LL INF = 1000000000000000001LL;

bool v[MX];
LL d[MX];

int n;

int t[105];

int mx;

void bfs() {
	memset(v, 0, sizeof(v));
	deque<int> q;
	for (int i = 1; i < mx; ++i)
		d[i] = INF;
	d[0] = 0;
	q.push_back(0);
	while (!q.empty()) {
		int c = q.front();
		q.pop_front();
		if (v[c]) continue;
		v[c] = 1;
		for (int i = 1; i < n; ++i) {
			int a = c + t[i];
			int cost = 1;
			if (a >= mx) {
				a -= mx;
				--cost;
			}
			if (d[a] > d[c] + cost) {
				d[a] = d[c] + cost;
				if (cost == 0)
					q.push_front(a);
				else
					q.push_back(a);
			}
		}
	}
}

LL l;

void alg() {
	scanf("%lld %d", &l, &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &t[i]);
	sort(t + 1, t + n + 1);
	mx = t[n];
	bfs();
	if (d[l % mx] == INF) {
		printf("IMPOSSIBLE\n");
		return;
	}
	printf("%lld\n", d[l % mx] + l / mx);
}

int main() {
	int d;
	scanf("%d", &d);
	for (int caseNo = 1; caseNo <= d; ++caseNo) {
		printf("Case #%d: ", caseNo);
		alg();
	}
}
