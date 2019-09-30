#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const int MAXN = 1123;

int e[MAXN][MAXN];
int d[MAXN];
bool vis[MAXN];

struct S{//seg
	int l, r;
};

S x[MAXN], y[MAXN];

int dis(S a, S b){
	if(a.l > b.r)
		return a.l-b.r;
	if(b.l > a.r)
		return b.l - a.r;
	return 0;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int i0 = 1;
	int T;
	scanf("%d", &T);
	for (i0 = 1; i0 <= T; i0++) {
		int H, W, n;
		int i, j, k;

		scanf("%d%d%d", &W, &H, &n);

		for(i = 0; i < n; i++){
			int x0, x1, y0, y1;

			scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
			x1++;
			y1++;

			x[i].l = x0;
			x[i].r = x1;
			y[i].l = y0;
			y[i].r = y1;
		}

		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++){
				if(i == j)
					e[i][j] = 1<<20;
				else
					e[i][j] = max(dis(x[i], x[j]), dis(y[i], y[j]));
			}

		for(i = 0; i < n; i++)
			d[i] = x[i].l;

		int ans = W;
		memset(vis, false, sizeof vis);
		while(true){
			int j = -1;
			for(i = 0; i < n; i++)
				if(!vis[i] && (j == -1 || d[i] < d[j]))
					j = i;
			if(j == -1)
				break;

			i = j;
			vis[i] = true;
			ans = min(ans, d[i] + (W-x[i].r));
			for(j = 0; j < n; j++){
				d[j] = min(d[j], d[i] + e[i][j]);
			}
		}

		printf("Case #%d: %d\n", i0, ans);
	}
	return 0;
}
