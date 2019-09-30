#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define FGETS(s,n,p)		{ s[0] = 0; fgets(s,n,p); }
#define LINE(s)			{ s[0] = 0; fgets(s,sizeof(s),in); }
#define FOR(i,a,b)		for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i,a,b)		for (int i(a), _b(b); i >= _b; --i)
#define FORSQ(i,a,b)		for (int i(a), _ii(i*i), _b(b); _ii <= _b; ++i, _ii = i*i)
#define FORLSQ(i,a,b)		for (ll i(a), _ii(i*i), _b(b); _ii <= _b; ++i, _ii = i*i)
#define REP(i,n)		for (int i(0), _n(n); i < _n; ++i)
#define REPD(i,n)		for (int i((n)-1); i >= 0; --i)
#define FILL(a,c)		memset(a,c,sizeof(a))

#define SQPOS(n,i,j)		POS((n),(n),(i),(j))
#define POS(mx,my,x,y)		((x)*(my)+(y))
#define POS3D(mx,my,mz,x,y,z)	((x)*(my)*(mz)+POS((my),(mz),(y),(z)))
#define INSIDE(i,min,max)	((min)<=(i)&&(i)<(max))
#define REMIN(v,n)		{ if ((n)<(v)) { (v)=(n); } }
#define REMAX(v,n)		{ if ((n)>(v)) { (v)=(n); } }
#define SWAP(a,b)		((a)^=((b)^=((a)^=(b))))

#define MIN(a,b)		((a)<(b)?(a):(b))
#define MAX(a,b)		((a)>(b)?(a):(b))
#define	EPS			1e-11	// 1e-6

#define POW2(n)			(1<<(n))
#define HASBIT(v,bit)		(((v)&POW2(bit))!=0)

typedef unsigned long long	ull;
typedef long long		ll;

typedef pair<int, int>		pii;
typedef pair<pii, pii>		ppi;
typedef pair<ll, ll>		pll;
typedef pair<string, string>	pss;

typedef vector<int>		vi;
typedef vector<vi>		vvi;
typedef vector<pii>		vpi;
typedef vector<ll>		vl;
typedef vector<vl>		vvl;
typedef vector<char>		vc;
typedef vector<string>		vstr;

template<typename T> void remin(T& a, const T& b) { if (b < a) a = b; }
template<typename T> void remax(T& a, const T& b) { if (b > a) a = b; }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }
template<class T> T cross(T x0, T y0, T x1, T y1, T x2, T y2)
{ return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0); }

int ccw(double x0, double y0, double x1, double y1, double x2, double y2)
{ double t = cross(x0, y0, x1, y1, x2, y2); return (fabs(t) <= EPS? 0: (t < 0? -1: 1)); }
bool line_intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{ return (	ccw(x1, y1, x2, y2, x3, y3)*ccw(x1, y1, x2, y2, x4, y4) < 0 &&
		ccw(x3, y3, x4, y4, x1, y1)*ccw(x3, y3, x4, y4, x2, y2) < 0); }
int sscanf_ilist(char *s, int n_size, int *n)
{
	int nz = 0, pos = 0, len = 0;
	for (nz = 0; nz < n_size; nz++, pos += len)
	{
		n[nz] = -1; sscanf(s+pos, "%d%n", n+nz, &len);
		if (n[nz] == -1) break;
	}
	return nz;
}

//#define TEST
#ifdef TEST
//#define test(v)	cerr << #x << " = " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
//#define test(v)
#define debug(...)
#endif

int x = 0;
int test(int S, char *slot, int L, char *line)
{
	int count = 0;
	REP(i,S-L+1) {
		if (strncmp(slot+i, line, L) == 0) {
			count++;
		}
	}
//debug("%06d: S = [%s], C = [%d]\n", x++, slot, count);
	return count;
}
int re(int K, char *key, int L, char *line, int S, char *slot, int p, int *best)
{
	int count = 0;
	if (S == p) {
		slot[p] = 0;
		int c = test(S, slot, L, line);
		REMAX(*best, c);
		count += c;
	} else {
		REP(i,K) {
			slot[p] = key[i];
			count += re(K, key, L, line, S, slot, p+1, best);
		}
	}
	return count;
}

// Main Program (Start Here)
int main(int argc, char *argv[])
{
	char buf[10240];
	FILE *in = stdin;
	int T;

	LINE(buf);
	sscanf(buf, "%d", &T);
	REP(c,T)
	{
//	Data preparaion put here
		LINE(buf);
x = 0;
char slot[110], key[110], line[110];
int K, L, S, count, best = 0;
		sscanf(buf, "%d %d %d", &K, &L, &S);
		LINE(key);
		LINE(line);

		count = re(K, key, L, line, S, slot, 0, &best);

long pow = 1;
REP(i,S) {
	pow *= K;
}

		printf("Case #%d: ", c+1);
//	Result Calculation/Display put here
		debug("P = %ld C = %d, B = %d\n", pow, count, best);
		printf("%lf\n", (double)best - (double)count/pow);

	}
	return 0;
}
