#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const long long MOD = 1000000007;

int n;
char s[110][110];
string st[110];
bool ok = true;
bool hash[200];
int a[30][30], b[30];
int d1[30], d2[30];

void init()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i]);
	for (int i = 1; i <= n; ++i)
	{
		st[i] = "";
		for (int j = 0; s[i][j] != '\0'; ++j)
		if (st[i] == "" || st[i][st[i].size() - 1] != s[i][j])
			st[i] += s[i][j];
	}
	ok = true;
	for (int i = 1; i <= n; ++i)
	if (st[i].size() > 2)
	{
		for (int j = 1; j < st[i].size() - 1; ++j)
		{
			for (int ii = 1; ii <= n; ++ii)
			for (int jj = 0; jj < st[ii].size(); ++jj)
			if (st[i][j] == st[ii][jj] && (i != ii || j != jj))
			{
				ok = false;
				return;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	if (st[i].size() > 2)
	{
		string tmp = "";
		tmp += st[i][0];
		tmp += st[i][st[i].size() - 1];
		st[i] = tmp;
	}
}

long long solve()
{
	if (!ok) return 0;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= n; ++i)
	if (st[i].size() == 1) ++b[st[i][0] - 'a'];
	else ++a[st[i][0] - 'a'][st[i][1] - 'a'];
	long long ans = 1;
	for (int i = 0; i < 26; ++i)
	for (int j = 1; j <= b[i]; ++j)
		ans = (ans * j) % MOD;
	for (int i = 0; i < 26; ++i)
	for (int j = 0; j < 26; ++j)
	if (a[i][j] > 1) return 0;
	else if (a[i][j] > 0)
	{
		b[i] = 0;
		b[j] = 0;
	}
	memset(d1, 0, sizeof(d1));
	memset(d2, 0, sizeof(d2));
	for (int i = 0; i < 26; ++i)
	for (int j = 0; j < 26; ++j)
	if (a[i][j] > 0)
	{
		++d1[i];
		++d2[j];
	}
	for (int i = 0; i < 26; ++i)
	if (d1[i] > 1 || d2[i] > 1) return 0;
	ok = true;
	while (ok)
	{
		ok = false;
		for (int k = 0; k < 26; ++k)
		for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
		if (a[i][j] > 0 && a[j][k] > 0)
		{
			if (i == k) return false;
			if (a[i][k] > 0 || a[k][i] > 0) return 0;
			a[i][j] = a[j][k] = 0;
			a[i][k] = 1;
			ok = true;
		}
	}
	int t = 0;
	for (int i = 0; i < 26; ++i)
	for (int j = 0; j < 26; ++j)
	if (a[i][j] > 0) ++t;
	for (int i = 0; i < 26; ++i)
	if (b[i] > 0) ++t;
	for (int i = 1; i <= t; ++i)
		ans = (ans * i) % MOD;
	return ans;
}

int main()
{
	freopen("b.in", "r", stdin);
	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		init();
		printf("Case #%d: %I64d\n", ii, solve());
		solve();
	}
	return 0;
}