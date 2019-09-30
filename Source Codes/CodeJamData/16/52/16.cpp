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

typedef long double ld;
typedef long long int int64;

const int IT = (int) 2e4;
const int N = 105;
vector <int> ch[N];
int p[N];

ld C[N][N];
ld dp[N];
int sz[N];
char letter[N];
char str[N];

vector <int> order;

void dfs(int v)
{
	order.push_back(v);
	for (int to : ch[v] )
		dfs(to);
}

char s[N];

int n;
void gen()
{
	vector <int> cur = {n};
	for (int i = 0; i <= n; i++)
	{
		vector <double> cntX;
		double sum = 0;
		for (int x : cur)
		{
			double val = C[n - i - 1][sz[x] - 1] / C[n - i][sz[x] ];
			cntX.push_back(val);
			sum += val;
		}
		double rnd = (double) rand() / (double) RAND_MAX;
		for (double &x : cntX)
			x /= sum;
		int takeID = 0;
		for (int it = 0; it < (int) cur.size(); it++)
		{
			if (rnd <= cntX[it] )
			{
				takeID = it;
				break;
			}
			rnd -= cntX[it];
		}
		int take = cur[takeID];
		swap(cur[takeID], cur.back() );
		cur.pop_back();
		
		s[i] = letter[take];
		for (int to : ch[take] )
			cur.push_back(to);
	}
}

void solve()
{
	for (int i = 0; i < N; i++)
		ch[i].clear();

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i] );
		p[i]--;
		if (p[i] == -1)
			p[i] = n;
		ch[p[i] ].push_back(i);
	}
	scanf("%s", letter);
	letter[n] = '.';

	p[n] = n;
	order.clear();
	dfs(n);
	reverse(order.begin(), order.end() );

	for (int x : order)
	{
		dp[x] = 1;
		sz[x] = 0;
		for (int to : ch[x] )
		{
			sz[x] += sz[to];
			dp[x] *= dp[to] * C[sz[x] ][sz[to] ];
		}
		sz[x]++;
	}

//	eprintf("%.10lf\n", (double) dp[n] );
	
	int m;
	scanf("%d", &m);
	for (int it = 0; it < m; it++)
	{
		scanf("%s", str);
		int len = strlen(str);
		int cntEq = 0;
		for (int iter = 0; iter < IT; iter++)
		{
			gen();
//			eprintf("%s %s\n", s, str);
			bool eq = false;
			for (int j = 0; j + len <= n + 1; j++)
			{
				eq = true;
				for (int h = 0; h < len; h++)
					if (str[h] != s[j + h] )
					{
//						eprintf("%d - %d\n", h, j + h);
						eq = false;
						break;
					}
				if (eq)
					break;
			}
			if (eq)
			{
//				eprintf("!\n");
				cntEq++;
			}
		}
		printf("%.5lf ", (double) cntEq / (double) IT);
	}
	printf("\n");
}

void init()
{
	for (int i = 0; i < N; i++)
	{
		C[i][0] = C[i][i] = 1.;
		for (int j = 1; j < i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int nn;
	scanf("%d", &nn);
	for (int i = 1; i <= nn; i++)
	{
		printf("Case #%d: ", i);
		eprintf("Case #%d .. %d\n", i, nn);
		solve();
	}


}

int main(int argc, char **)
{
	init();

	if (argc == 1)
		multitest();
	else
		solve();

	return 0;
}


