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

#define N 200
#define M 1000

int n;
int A[N][N];
char S[N];

bool can(int oi, int oj)
{
	int i, j, ii, jj;
	rep(i, 1, 2 * n) rep(j, 1, 2 * n) if(A[i][j] >= 0)
	{
		ii = 2 * oi - i;
		jj = 2 * oj - j;
		if(0 <= ii && ii <= 2 * n) if(A[ii][j] >= 0 && A[ii][j] != A[i][j]) return 0;
		if(0 <= jj && jj <= 2 * n) if(A[i][jj] >= 0 && A[i][jj] != A[i][j]) return 0;
		if(0 <= ii && ii <= 2 * n && 0 <= jj && jj <= 2 * n) if(A[ii][jj] >= 0 && A[i][j] != A[ii][jj]) return 0;
	}
	return 1;
}

int cnt(int oi, int oj)
{
	return sqr(n + abs(oi - n) + abs(oj - n)) - sqr(n);
}

int main()
{
	//freopen("in.txt", "rt", stdin);
	freopen("a.in", "rt", stdin);
	freopen("a.out", "wt", stdout);

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
		in(d, n); gets(S);
		rep(i, 0, 2 * n + 1) rep(j, 0, 2 * n + 1) A[i][j] = -1;
		rep(i, 1, 2 * n)
		{
			gets(S);
			reps(j, S) if(S[j] != ' ') A[i][j + 1] = S[j] - '0';
		}
		int res = inf;
		rep(i, 0, 2 * n + 1) rep(j, 0, 2 * n + 1) if(can(i, j)) res = min(res, cnt(i, j));
		printf("Case #%d: %d\n", iT, res);
	}

	return 0;
}
