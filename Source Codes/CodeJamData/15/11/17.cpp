#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 1010;
int n;
int a[N];

bool check(int x, int &y)
{
	int bal = a[0];
	y = 0;
	for (int i = 1; i < n; i++)
	{
		y += min(bal, x);
		bal = max(0, bal - x);
		if (bal > a[i]) return false;
		bal = a[i];
	}
	return true;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int ans = 0;
	for (int i = 1; i < n; i++)
		ans += max(0, a[i - 1] - a[i]);
	printf("%d ", ans);
	int l = -1, r = 10 * N;
	while(r > l + 1)
	{
		int x = (l + r) / 2;
		int y;
		if (check(x, y))
			r = x;
		else
			l = x;
	}
	if (!check(r, ans)) throw;
	printf("%d\n", ans);
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		solve();
	}

	return 0;
}
