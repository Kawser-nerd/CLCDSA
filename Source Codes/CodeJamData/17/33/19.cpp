#include <cstdio>
#include <algorithm>

using namespace std;

const double eps = 1e-9;

double p[55];

int main()
{
	double U;
	int T, N, K;
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d", &T);
	for (int _T = 1; _T <= T; _T++)
	{
		scanf("%d%d%lf", &N, &K, &U);
		for (int i = 0; i < N; i++) scanf("%lf", &p[i]);
		sort(p, p + N);
		p[N] = 1;
		if (K == N)
		{
			for (int i = 0; i < N; i++)
			{
				if (U < eps) break;
				double V = min(U / (i + 1), p[i + 1] - p[i]);
				U -= V * (i + 1);
				for (int j = 0; j <= i; j++) p[j] += V;
			}
			double ans = 1.0;
			for (int i = 0; i < N; i++) ans = ans * p[i];
			printf("Case #%d: %.10lf\n", _T, ans);
		}
	}
	return 0;
}
