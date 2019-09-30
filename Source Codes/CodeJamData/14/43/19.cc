//By Lin
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 1010

int n, W, H;
struct Rect {
	int x1, y1, x2, y2;
	void read() {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x2 ++, y2 ++;
	}
}data[N];
int cal(int l1, int r1, int l2, int r2) {
	int l = max(l1, l2),
		r = min(r1, r2);
	return max(0, l - r);
}
int cal(const Rect &a, const Rect &b) {
	return max(cal(a.x1, a.x2, b.x1, b.x2), 
			   cal(a.y1, a.y2, b.y1, b.y2));
}

int dis[N];
bool mark[N];

int main() {
	int cas = 0, tt = 0;
	scanf("%d", &cas);
	while (cas --) {
		scanf("%d%d%d", &W, &H, &n);
		Rep(i, n) data[i].read();
		Rep(i, n) dis[i] = data[i].x1;
		memset(mark, 0, sizeof mark);
		while (true) {
			int i = -1;
			Rep(k, n) if (!mark[k]) 
				if (i == -1 || dis[i] > dis[k]) i = k;
			if (i == -1) break;
			mark[i] = true;
			Rep(j, n) 
				dis[j] = min(dis[j], dis[i] + cal(data[i], data[j]));
		}
		int ans = W;
		Rep(i, n) ans = min(ans, dis[i] + W - data[i].x2);
		printf("Case #%d: %d\n", ++tt, ans);
	}
	return 0;
}
