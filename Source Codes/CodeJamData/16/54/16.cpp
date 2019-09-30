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


const int N = 205;
const int LEN = 205;
char s[N][LEN];
char a[LEN], b[LEN];
string d[N];

int dp[LEN][LEN][2];
bool test(char str[] )
{
	memset(dp, -1, sizeof dp);
	dp[0][0][0] = 0;
	int alen = strlen(a);
	int blen = strlen(b);
	for (int pa = 0; pa <= alen; pa++)
		for (int pb = 0; pb <= blen; pb++)
			for (int val = 0; val <= 1; val++)
			{
				int cur = dp[pa][pb][val];
				if (cur == -1) continue;
				if (pa != alen)
				{
					if (a[pa] == '0')
						dp[pa + 1][pb][0] = cur;
					else if (a[pa] == '1')
						dp[pa + 1][pb][1] = cur;
					else if (val + '0' == str[cur] )
						dp[pa + 1][pb][val] = cur + 1;
				}
				if (pb != blen)
				{
					if (b[pb] == '0')
						dp[pa][pb + 1][0] = cur;
					else if (b[pb] == '1')
						dp[pa][pb + 1][1] = cur;
					else if (val + '0' == str[cur] )
						dp[pa][pb + 1][val] = cur + 1;
				}
			}
	return dp[alen][blen][0] != -1 || dp[alen][blen][1] != -1;
}

bool test(int n)
{
	for (int i = 0; i < n; i++)
		if (!test(s[i] ) )
		{
			eprintf("i = %d\n", i);
			return false;
		}
	if (test(s[n] ) ) 
	{
		eprintf("!!\n");
		return false;
	}
	return true;
}
int ptr[N];

void solve(int n, int l)
{
	memset(ptr, 0, sizeof ptr);
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	int pa = 0, pb = 0;
	for (int i = 0; i < l; i++)
	{
		b[pb++] = '0' + '1' - s[n][i];
		b[pb++] = '?';
	}
	int pos = 0;
	int t = 1;
	while (true)
	{
		t ^= 1;
		bool fnd = false;
		int has0 = 0, has1 = 0;
		for (int i = 0; i < n; i++)
		{
			if (ptr[i] == (int) d[i].size() ) continue;
			fnd = true;
			if (d[i][ptr[i] ] == '0')
				has0++;
			else
				has1++;
		}
		if (!fnd) break;
		char x = '0';
		if (t == 1)
		{
			if (s[n][pos] == '0')
			{
				if (has1 > has0) x = '1';
			}
			else
			{
				if (has0 < has1) x = '1';
			}
		}
		else
		{
			if (s[n][pos] == '0')
			{
				if (has1) x = '1';
			}
			else
			{
				if (has0 == 0) x = '1';
			}
		}
		if (x == s[n][pos] )
		{
			t = 1;
			pos++;
		}
		if (pos == l) 
		{
			eprintf("WTF??\n");
			throw;
		}
		a[pa++] = x;
		for (int i = 0; i < n; i++)
			if (ptr[i] != (int) d[i].size() && d[i][ptr[i] ] == x)
				ptr[i]++;
	}
}

void solve()
{
	int n, l;
	scanf("%d%d", &n, &l);
	for (int i = 0; i <= n; i++)
		scanf("%s", s[i] );
	for (int i = 0; i < n; i++)
	{
		d[i].clear();
		bool good = false;
		for (int j = 0; j < l; j++)
			if (s[i][j] != s[n][j] )
				good = true;
			else
				d[i].push_back(s[i][j] );
		if (!good)
		{
			printf("IMPOSSIBLE\n");
			return;
		}
	}
	solve(n, l);
	eprintf("%s %s\n", a, b);
	if (strlen(a) == 0)
	{
		a[0] = b[0];
	}
	
	if (!test(n) ) throw;
	if (strlen(a) + strlen(b) > 200) throw;
	printf("%s %s\n", a, b);
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


