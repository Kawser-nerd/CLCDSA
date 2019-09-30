#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

vector <pair <int, int> > pos, neg;
const int maxn = 505;

const double inf = 1e30;
double dp[maxn][maxn][2];
int _p[maxn], _s[maxn];

double getPos(int i, double cur)
{
	return pos[i].second + pos[i].first * cur;
}
double getNeg(int j, double cur)
{
	return neg[j].second - neg[j].first * cur; 
}

void solve()
{
	pos.clear();
	neg.clear();

	int v, n;
	scanf("%d%d", &v, &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &_p[i] );
	for (int i = 0; i < n; i++)
		scanf("%d", &_s[i] );
	for (int i = 0; i < n; i++)
	{
		int p = _p[i], s = _s[i];
		if (p > 0)
			pos.push_back(make_pair(s, p) );
		else
			neg.push_back(make_pair(s, p) );
	}
	sort(pos.begin(), pos.end() );
	reverse(pos.begin(), pos.end() );
	sort(neg.begin(), neg.end() );
	reverse(neg.begin(), neg.end() );

	int ni = (int) pos.size();
	int nj = (int) neg.size();
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			for (int h = 0; h < 2; h++)
				dp[i][j][h] = inf;
	dp[0][0][0] = dp[0][0][1] = 0;
	double answer = inf;
	for (int _i = 0; _i <= ni; _i++)
		for (int _j = 0; _j <= nj; _j++)
			for (int t = 0; t < 2; t++)
			{
				int i = _i, j = _j;
				double cur = dp[i][j][t];
//				eprintf("i = %d, j = %d, t = %d, cur = %.10lf\n", i, j, t, cur);
				if (cur == inf)
					continue;
				double cp = 0;
				if (t == 0 && i != 0)
					cp = getPos(i - 1, cur);
				else if (t == 1 && j != 0)
					cp = getNeg(j - 1, cur);
//				eprintf("cp = %.10lf\n", cp);
				if (t == 0)
				{
					while (i < ni && fabs(getPos(i, cur) ) < fabs(cp) )
						i++;
				}
				else
				{
					while (j < nj && fabs(getNeg(j, cur) ) < fabs(cp) )
						j++;
				}
				if (i == ni && j == nj)
				{
					answer = min(answer, cur);
					continue;
				}
				

				if (i != ni)
				{
					double d = fabs(getPos(i, cur) - cp);
					double nxt = cur + d / (double) (v - pos[i].first);
					int nxi = i + 1;
					dp[nxi][j][0] = min(dp[nxi][j][0], nxt);
				}
				if (j != nj)
				{
					double d = fabs(getNeg(j, cur) - cp);
					double nxt = cur + d / (double) (v - neg[j].first);
					int nxj = j + 1;
					dp[i][nxj][1] = min(dp[i][nxj][1], nxt);
				}
			}
//	eprintf("\n\n");
	printf("%.10lf\n", answer);
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Case #%d: ", i);
		eprintf("Case #%d .. %d\n", i, n);
		solve();
	}


}

int main(int argc, char **)
{
	if (argc == 1)
		multitest();
	else
		solve();

	return 0;
}


