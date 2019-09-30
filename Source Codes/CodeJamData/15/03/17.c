#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define FGETS(s,n,p)		{ s[0] = 0; fgets(s,n,p); }
#define FOR(i,a,b)		for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i,a,b)		for (int i(a), _b(b); i >= _b; --i)
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

int sign[5][5] = {
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 1 },
	{ 0, 1, -1, 1, -1 },
	{ 0, 1, -1, -1, 1 },
	{ 0, 1, 1, -1, -1 }
};

#define I	2
#define	J	3
#define K	4

//	1:1	2:i	3:j	4:k
int mul[5][5] = {
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, I, J, K },
	{ 0, I, 1, K, J },
	{ 0, J, K, 1, I },
	{ 0, K, J, I, 1 }
};

int ijk2v(char c)
{
	return c == 'i' ? I : (c == 'j' ? J : K);
}

typedef struct {
	int s;
	int v;
} qType;

//#define TEST
#ifdef TEST
#define debug printf
#else
#define debug(...)
#endif

qType cal(qType a, qType b)
{
	qType c;
	c.s = a.s * b.s * sign[a.v][b.v];
	c.v = mul[a.v][b.v];
	return c;
}

ull get_pos(ull L, ull X, qType *Lv, qType target, int is_reverse)
{
	int MX = MIN(X, 4);
	qType v = {1, 1};
	REP(j, MX) {
		REP(i, L) {
			v = is_reverse ? cal(Lv[i], v) : cal(v, Lv[i]);
debug("LM%d-%d %d %d\n", j, i, v.s, v.v);
			if (v.s == target.s && v.v == target.v) {
				return L*j + (i + 1);
			}
		}
	}
	return 0;
}

qType get_mul(ull L, ull X, qType *Lv) {
	qType v = { 1, 1 }, pt = { 1, 1 };
	REP(i, L) {
		v = cal(v, Lv[i]);
	}
	REP(i, X % 4) {
		pt = cal(pt, v);
	}
	return pt;
}

// Main Program (Start Here)
int main(int argc, char *argv[])
{
	char buf[4096];
	FILE *in = stdin;
	int T;

	FGETS(buf, 4096, in);
	sscanf(buf, "%d", &T);
	REP(c,T)
	{
//	Data preparaion put here
		ull L, X;
		qType Lv[10000], Rv[10000];
		ull len_i = 0, len_k = 0;
		int is_okay = 0, res = 0;

		FGETS(buf, 4096, in);
		sscanf(buf, "%llu %llu", &L, &X);
		{
			char s[10010];
			FGETS(s, 10010, in);
			REP(i, L) {
				qType v = { 1, ijk2v(s[i]) };
				Lv[i] = v;
				Rv[L - 1 - i] = v;
			}
		}
debug("L=%llu X=%llu\n L*X=%llu\n", L, X, L*X);

		// Whole chain test...
		{
			qType target = { -1, 1 };	// ijk = -1
			qType z = get_mul(L, X, Lv);
			is_okay = (z.s == target.s && z.v == target.v ? 1 : 0);
debug("SUM=(%d %d) %s\n", z.s, z.v, is_okay ? "OKAY" : "");
		}

		// Prefix i test...
		if (is_okay) {
			qType target = { 1, I };
			len_i = get_pos(L, X, Lv, target, 0);
debug("I = %llu\n", len_i);
		}

		// Postfix k test...
		if (len_i) {
			qType target = { 1, K };
			len_k = get_pos(L, X, Rv, target, 1);
debug("K = %llu\n", len_k);
		}

		res = (len_k && (len_i + len_k < L * X)) ? 1 : 0;

		printf("Case #%d: ", c+1);
//	Result Calculation/Display put here

		printf("%s\n", res ? "YES" : "NO");
	}
	return 0;
}
