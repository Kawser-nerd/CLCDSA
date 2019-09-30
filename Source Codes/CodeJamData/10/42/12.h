#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

#define rep(i, a, b) for(i = (a); i < (b); ++i)
#define repb(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define repd(i, a, b, d) for(i = (a); i < (b); i += (d))
#define repbd(i, a, b, d) for(i = (a) - 1; i >= (b); i -= (d))
#define reps(i, s) for(i = 0; (s)[i]; ++i)
#define repl(i, l) for(i = l.begin(); i != l.end(); ++i)

#define in(f, a) scanf("%"#f, &(a))

bool firstout = 1;

#define out(f, a) printf("%"#f, (a))
#define outf(f, a) printf((firstout) ? "%"#f : " %"#f, (a)), firstout = 0
#define nl printf("\n"), firstout = 1

#define all(x) (x).begin(),(x).end()
#define sqr(x) ((x) * (x))

#define inf 1000000000
#define eps 1e-9

#define N 4000
#define M 12

int n, m;
int A[N], C[N], D[N][M];

int fnd(int i, int j)
{
	int &res = D[i][j];
	if(res >= 0) return res;
	res = C[i] + fnd(2 * i, j) + fnd(2 * i + 1, j);
	if(A[i] > j) res = min(res, fnd(2 * i, j + 1) + fnd(2 * i + 1, j + 1));
	return res;
}

int main()
{
	//freopen("in.txt", "rt", stdin);
	freopen("b.in", "rt", stdin);
	freopen("b.out", "wt", stdout);

	int i, j, k, d;
	char c;
	int a;
	
#if 1
	int T, iT;
	in(d, T);
	rep(iT, 1, T + 1)
#else
	for(; in(d, n) > 0;)
#endif
	{
		in(d, n);
		m = n;
		n = (1 << n);
		rep(i, n, 2 * n) in(d, A[i]);
		for(i = n; i > 1; i >>= 1)
		{
			j = (i >> 1);
			rep(j, j, i) in(d, C[j]), A[j] = min(A[2 * j], A[2 * j + 1]);
		}
		rep(i, 1, n) rep(j, 0, m + 1) D[i][j] = -1;
		rep(i, n, 2 * n) rep(j, 0, n + 1) D[i][j] = 0;
		int res = fnd(1, 0);
		printf("Case #%d: %d\n", iT, res);
	}

	return 0;
}
