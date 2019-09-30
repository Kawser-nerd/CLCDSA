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

inline int work0(const int &x, const int &w)
{
	return (x == w ? w : w + 1);
}

inline int work(const int &x, const int &w)
{
	int tmp = x / w;
	return tmp - 1 + work0(x - (tmp - 1) * w, w);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		printf("Case #%d: ", i);
		int r, c, w;
		scanf("%d%d%d", &r, &c, &w);
		printf("%d\n", (r - 1) * (c / w) + work(c, w));
	}
	return 0;
}
