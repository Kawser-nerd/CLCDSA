#include <cstdio>
#include <algorithm>

using namespace std;

const double pi = 3.141592653589793238463;
const int MAXN = 1001;

struct Pair{
	int r, h;
} a[MAXN];

double x[MAXN];
int n, K;
double ans;

int main()
{
	freopen("a2.in", "r", stdin);
	freopen("a2.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t ++)
	{
		scanf("%d%d", &n, &K);
		for (int i = 0; i < n; i ++)
			scanf("%d%d", &a[i].r, &a[i].h);
		ans = 0;
		for (int i = 0; i < n; i ++){
			int s = 0;
			double cur = pi * a[i].r * a[i].r + 2 * pi * a[i].r * a[i].h;
			for (int j = 0; j < n; j ++)
				if (i != j && a[j].r <= a[i].r){
					x[s ++] = 2 * pi * a[j].r * a[j].h;
				}
			if (s >= K-1){
				sort(x, x + s);
				for (int t = 0; t < K-1; t ++)
					cur += x[s-1-t];
			}
			if (cur > ans) ans = cur;
		}
		printf("Case #%d: %.10lf\n", t, ans);
	}
	return 0;
}
