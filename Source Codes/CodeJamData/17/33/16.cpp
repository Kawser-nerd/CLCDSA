#include <cstdio>

using namespace std;

const int MAXN = 51;

double pr[MAXN], ans;
int n, K;

int main()
{
	freopen("c1.in", "r", stdin);
	freopen("c1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t ++)
	{
		scanf("%d%d", &n, &K);
		double u;
		scanf("%lf", &u);
		for (int i = 0; i < n; i ++)
			scanf("%lf", &pr[i]);
		double l = 0, r = 1.0;
		for (int i = 0; i < 100; i ++){
			double m = (l + r) / 2;
			double s = 0;
			for (int j = 0; j < n; j ++)
				if (pr[j] < m)
					s += m - pr[j];
			if (u >= s) l = m;
				else r = m;
		}
		ans = 1.0;
		for (int i = 0; i < n; i ++)
			if (pr[i] < l)
				ans *= l;
			else
				ans *= pr[i];
		printf("Case #%d: %.10lf\n", t, ans);
	}
	return 0;
}
