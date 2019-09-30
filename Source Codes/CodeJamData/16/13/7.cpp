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


const int N = 1005;
int f[N];
bool used[N];
int ans[N][N];

void solveCycle(int v, int &mx)
{
	memset(used, false, sizeof used);
	int cur = v;
	int len = 0;
	while (!used[cur] )
	{
		used[cur] = true;
		cur = f[cur];
		len++;
	}
	if (v != cur) return;
	mx = max(mx, len);
}

void updPair(int v)
{
	memset(used, false, sizeof used);
	int cur = v;
	int len = 0;
	while (!used[cur] )
	{
		used[cur] = true;
		cur = f[cur];
		len++;
	}
	if (f[f[cur] ] != cur) return;
	int a = cur;
	int b = f[cur];
	len--;
	ans[a][b] = max(ans[a][b], len);
}

void solve()
{
	int n;
	scanf("%d", &n);
	memset(ans, 0, sizeof ans);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &f[i] );
		f[i]--;
	}
	int ans2 = 0, mx = 0;

	for (int i = 0; i < n; i++)
		solveCycle(i, mx);

	for (int i = 0; i < n; i++)
		updPair(i);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans2 += ans[i][j];

	int answer = max(ans2, mx);
	printf("%d\n", answer);
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


