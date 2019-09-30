#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

#define N 21000
#define INF 1000000000
int len;
bool cc[N];
int till[N], Next[N], go[N], f[N], n1[N], D[N];
int s, t, t1, t2;
int n, c, m;
int p[N], b[N];
int sum[N];

void add(int x, int y, int z) {
	Next[++len] = till[x];
	till[x] = len;
	go[len] = y;
	f[len] = z;
}

void Ad(int x, int y, int z) {
	add(x, y, z);
	add(y, x, 0);
}
bool bfs() {
  int q, h, i;
  memset(D, 0, sizeof D);
  memset(cc, true, sizeof cc);
  for (D[n1[q = h = 1] = s] = 1; q <= h; q++)
    for (i = till[n1[q]]; i; i = Next[i])
      if (f[i] && !D[go[i]])  D[n1[++h] = go[i]] = D[n1[q]] + 1;
  return D[t];
}
int dfs(int k, int mi) {
  if (k == t) return mi;
  int i, tmp, sum = 0;
  for (i = till[k]; i && mi; i = Next[i])
    if (f[i] && D[go[i]] == D[k] + 1 && cc[go[i]]) {
      tmp = dfs(go[i], min(mi, f[i]));
      sum += tmp;
      mi -= tmp;
      f[i] -= tmp;
      f[i ^ 1] += tmp;
    }
  if (!sum) cc[k] = false;
  return sum;
}
int maxFlow() {
  int sum = 0;
  while (bfs()) sum += dfs(s, INF);
  return sum;
}

void init() {
	memset(till, 0, sizeof till);
	len = 1;
}

bool ok(int x) {
	init();
	s = 0;
	t = n + c + 1;
	for (int i = 1; i <= m; i++) {
		Ad(s, b[i], 1);
		Ad(b[i], c + p[i], 1);
	}
	for (int i = 1; i < n; i++) {
		Ad(c + i + 1, c + i, INF);
		// Ad()
	}
	for (int i = 1; i <= n; i++) {
		Ad(c + i, t, x);
	}
	return maxFlow() == m;
}

bool ok(int y, int x) {
	init();
	s = 0;
	t1 = 2 * n + c + 1;
	t2 = t1 + 1;
	t = t1 + 2;
	for (int i = 1; i <= m; i++) {
		Ad(s, b[i], 1);
		Ad(b[i], c + p[i], 1);
		Ad(b[i], c + n + p[i], 1);
	}
	for (int i = 1; i < n; i++) {
		Ad(c + i + 1, c + i, INF);
	}
	for (int i = 1; i <= n; i++) {
		Ad(c + i, t1, x);
		Ad(c + n + i, t2, x);
	}
	Ad(t1, t, y);
	Ad(t2, t, m - y);
	return maxFlow() == m;
}

void doit() {
	scanf("%d%d%d", &n, &c, &m);
	for (int i = 1; i <= c; i++)
		sum[i] = 0;
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &p[i], &b[i]);
		sum[b[i]] += 1;
		ans = max(ans, sum[b[i]]);
	}
	int q = 0, h = m;
	while (q < h - 1) {
		int mid = (q + h) / 2;
		if (ok(mid))
			h = mid;
		else
			q = mid;
	}
	h = max(h, ans);
	printf("%d ", h);
	int l = -1, r = m;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (ok(mid, h))
			r = mid;
		else
			l = mid;
	}
	printf("%d\n", r);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        doit();
    }
}