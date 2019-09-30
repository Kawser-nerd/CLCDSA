#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

const int MAXN = 100;

int n, tot;
int a[MAXN][MAXN];
string s[MAXN];
string ans;
bool chk[MAXN], chk2[MAXN];
int stack[MAXN];
int top;
int list[MAXN];

void dfs(int p)
{
	if (chk[p]) return;
	++tot;
	chk[p] = true;
	for (int i = 1; i <= n; ++i)
		if (a[p][i]) dfs(i);
}

void init()
{
	int m, x, y;
	cin >> n >> m;
	for (int i = 0; i <= n; ++i)
		getline(cin, s[i]);
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= m; ++i)
	{
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
}

void solve()
{
	ans = "";
	memset(chk2, 0, sizeof(chk2));
	int best;
	top = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			for (int j = 1; j <= n; ++j)
				list[j] = 1;
		}
		else
		{
			memset(list, 0, sizeof(list));
			for (int j = 1; j <= top; ++j)
			for (int k = 1; k <= n; ++k)
			if (a[stack[j]][k])
				list[k] = j;
		}
		best = -1;
		for (int j = 1; j <= n; ++j)
		if (!chk2[j] && list[j] > 0)
		{
			memcpy(chk, chk2, sizeof(chk2));
			tot = i;
			dfs(j);
			if (i != 0)
				for (int k = list[j]; k >= 1; --k) {--tot; chk[stack[k]] = false; dfs(stack[k]);}
			if (tot == n)
			{
				if (best == -1 || s[j] < s[best])
				{
					best = j;
				}
			}
		}
		chk2[best] = true;
		cout << s[best];
		if (i != 0)
		{
			top = list[best];
			stack[++top] = best;
		}
		else stack[top = 1] = best;
	}
	cout << endl;
}

int main()
{
	freopen("c.in", "r", stdin);
	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		init();
		printf("Case #%d: ", ii);
		solve();
	}
	return 0;
}










