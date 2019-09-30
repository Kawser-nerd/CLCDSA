#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cassert>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = 100;

typedef long long LL;

int ans = 0;

int num, n, V;

int a[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case)
	{
		scanf("%d%d%d", &num, &n, &V);
		REP(i, 0, n) scanf("%d", a + i);
		a[n++] = V + 1;
		sort(a, a + n);
		LL sum = 0;
		int ans = 0;
		REP(i, 0, n)
		{
			if (sum >= V) break;
			while (a[i] > sum + 1)
			{
				++ans;
				sum += LL(sum + 1) * num;
				if (sum >= V) break;
			}
			sum += LL(a[i]) * num;
		}
		printf("Case #%d: %d\n", Case, ans);
	}
	return 0;
}
