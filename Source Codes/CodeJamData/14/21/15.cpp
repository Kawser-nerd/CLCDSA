#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 120;

int n;
string a[MAXN];
string ss;
int b[MAXN], c[MAXN];

void init()
{
	cin >> n;
	getline(cin, ss);
	for (int i = 1; i <= n; ++i)
		getline(cin, a[i]);
}

string simple(string s)
{
	string ss = "";
	for (int i = 0; i < s.size(); ++i)
	if (ss == "" || ss[ss.size() - 1] != s[i])
		ss += s[i];
	return ss;
}

int abs(int x) { return x < 0 ? -x : x;}

void solve()
{
	ss = simple(a[1]);
	for (int i = 2; i <= n; ++i)
	{
		if (simple(a[i]) != ss)
		{
			printf("Fegla Won\n");
			return;
		}
	}
	int ans = 0;
	int t;
	memset(c, 0, sizeof(c));
	for (int i = 0; i < ss.size(); ++i)
	{
		memset(b, 0, sizeof(b));
		for (int j = 1; j <= n; ++j)
		{
			while (c[j] < a[j].size() && a[j][c[j]] == ss[i]) ++b[j], ++c[j];
		}
		sort(b + 1, b + n + 1);
		t = b[(n + 1) / 2];
		for (int j = 1; j <= n; ++j)
			ans += abs(b[j] - t);
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("a.in", "r", stdin);
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






