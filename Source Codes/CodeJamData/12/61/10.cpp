#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int Z = 101;

int n;
int x[Z], y[Z], m[Z];
struct event_t
{
	int who, offset;
} times[Z * 1001];

bool operator < (const event_t& a, const event_t& b)
{
	return m[a.who] + a.offset < m[b.who] + b.offset;
}

int tp;

int dp[1001][Z];
vector<int> klist[50];

int distance (int a, int b)
{
	int x1, y1, x2, y2;
	x1 = x[a] + y[a];
	y1 = x[a] - y[a];
	x2 = x[b] + y[b];
	y2 = x[b] - y[b];

	return (std::abs(x1 - x2) + std::abs(y1 - y2)) / 2;
}

int main ()
{
	int t, ct = 0;

	for (scanf ("%d", &t); t > 0; t --)
	{
		scanf ("%d", &n);

		for (int i = 0; i < 50; i ++)
			klist[i].clear();

		for (int i = 0; i < n; i ++)
		{
			scanf ("%d%d%d", x + i, y + i, m + i);
			klist[m[i] % 50].push_back(i);
		}

		x[n] = 0;
		y[n] = 0;
		m[n] = -1000;
		n ++;

		tp = 0;
		for (int i = 0; i < n; i ++)
			for (int j = 0; j <= 1000; j ++)
			{
				times[tp].who = i;
				times[tp].offset = j;
				tp ++;
			}

		sort(times, times + tp);

		memset(dp, -1, sizeof(dp));
		dp[0][n - 1] = 0;

		int ans = 0;
		for (int i = 0; i < tp; i ++)
		{
			int j = times[i].who;
			int o = times[i].offset;

//			printf ("i = %d, who = %d, offset = %d, ans = %d\n", i, j, o, dp[o][j]);

			if (dp[o][j] >= 0)
			{
				if (dp[o][j] > ans)
					ans = dp[o][j];

				if (!(o > 0 && dp[o][j] == dp[o - 1][j]))
				{
					for (int k = 0; k < n; k ++)
						if (k != j)
						{
							// earliest time i can reach k
							int et = max(m[j] + o + 750, max(m[j] + o, 0) + distance(j, k) * 100);
							if (et < m[k])
								et = m[k];
							if (et <= m[k] + 1000)
							{
								int eo = et - m[k];
								if (dp[o][j] + 1 > dp[eo][k])
									dp[eo][k] = dp[o][j] + 1;
							}
						}
				}
				else
				{
					int md = (o + m[j] + 1000) % 50;
					for (int ak = 0; ak < klist[md].size(); ak ++)
					{
						int k = klist[md][ak];
						if (k != j)
						{
							// earliest time i can reach k
							int et = max(m[j] + o + 750, max(m[j] + o, 0) + distance(j, k) * 100);
							if (et < m[k])
								et = m[k];
							if (et <= m[k] + 1000)
							{
								int eo = et - m[k];
								if (dp[o][j] + 1 > dp[eo][k])
									dp[eo][k] = dp[o][j] + 1;
							}
						}
					}
				}

				if (o + 1 <= 1000 && dp[o][j] > dp[o + 1][j])
					dp[o + 1][j] = dp[o][j];
			}
		}

		printf ("Case #%d: %d\n", ++ ct, ans);
		fprintf (stderr, "Finished case %d\n", ct);
	}

	return 0;
}