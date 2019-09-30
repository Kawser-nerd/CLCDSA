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

#define N 1000
#define M 1000

int n;
int X[N], Y[N], XX[N], YY[N];
bool A[N][N];
int C[N];
int R[N], RX[N], RY[N];

bool coin(int i, int j)
{
	bool r, rr;
	r = rr = 0;
	r |= (X[i] <= X[j] && X[j] <= XX[i]) || (X[i] <= XX[j] && XX[j] <= XX[i]);
	swap(i, j);
	r |= (X[i] <= X[j] && X[j] <= XX[i]) || (X[i] <= XX[j] && XX[j] <= XX[i]);
	rr |= (Y[i] <= Y[j] && Y[j] <= YY[i]) || (Y[i] <= YY[j] && YY[j] <= YY[i]);
	swap(i, j);
	rr |= (Y[i] <= Y[j] && Y[j] <= YY[i]) || (Y[i] <= YY[j] && YY[j] <= YY[i]);
	bool res = r && rr;
	if(XX[i] == X[j] && YY[i] == Y[j]) res = 0;
	swap(i, j);
	if(XX[i] == X[j] && YY[i] == Y[j]) res = 0;
	return res;
}

void dfs(int i, int c)
{
	C[i] = c;
	int j;
	for(j = 0; j < n; ++j) if(A[i][j] && C[j] == -1) dfs(j, c);
}

int main()
{
	//freopen("in.txt", "rt", stdin);
	freopen("c.in", "rt", stdin);
	freopen("c.out", "wt", stdout);

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
		rep(i, 0, n) in(d, X[i]), in(d, Y[i]), in(d, XX[i]), in(d, YY[i]), ++XX[i], ++YY[i];
		rep(i, 0, n) rep(j, 0, n) A[i][j] = coin(i, j);
		rep(i, 0, n) C[i] = -1;
		d = 0;
		rep(i, 0, n) if(C[i] == -1) dfs(i, d++);
		rep(i, 0, n) R[i] = inf, RX[i] = RY[i] = 0;
		rep(i, 0, n) R[C[i]] = min(R[C[i]], X[i] + Y[i]), RX[C[i]] = max(RX[C[i]], XX[i]), RY[C[i]] = max(RY[C[i]], YY[i]);
		int res = 0;
		rep(i, 0, d) res = max(res, RX[i] + RY[i] - R[i] - 1);
		printf("Case #%d: %d\n", iT, res);
	}

	return 0;
}
