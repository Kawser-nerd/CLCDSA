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

//#define TEST
#ifdef TEST
#define debug printf
#else
#define debug(...)
#endif

typedef struct {
	int st;	// Shared Time
	int et;	// Exclusive Time
} qType;

int dmap[1001][101];	// Disc x Privileges

int qrank(qType v)
{
	return v.st + v.et;
}

#define DIV_CEIL(a,b)	(a)/(b) + ((a)%(b)?1:0)
void prep(void) {
	int M = 1000;
	dmap[1][0] = 1;	// One basic second
	FOR(i,2,M) {
		dmap[i][0] = i;
	}
	FOR(i,2,M) {
		int N = sqrt(i);
		FOR(j,1,N-1) {
			dmap[i][j] = DIV_CEIL(i,j+1);
//debug("D-%d Pt-%d = %d\n", i, j, dmap[i][j]);
		}
	}
}

//	sp	shared time
qType cal(int sp, int *freq, int maxP) {
	qType res = { 0, 0 };
	FOR(i,1,maxP) {
		if (!freq[i]) continue;
		int N = sqrt(i);
		qType qmin = { i, 0 };
		FOR(j,0,N-1) {
			qType q = { max(sp, dmap[i][j]), freq[i]*j };
			if (qrank(q) < qrank(qmin)) {
				qmin = q;
			}
		}
debug("maz-%d-%d = (%d %d)\n", sp, i, qmin.st, qmin.et);
		REMAX(res.st, qmin.st);
		res.et += qmin.et;
	}
debug("max-%d = (%d %d)\n", sp, res.st, res.et);
	return res;
}

// Main Program (Start Here)
int main(int argc, char *argv[])
{
	char buf[4096];
	FILE *in = stdin;
	int T;

	prep();

	FGETS(buf, 4096, in);
	sscanf(buf, "%d", &T);
	REP(c,T)
	{
//	Data preparaion put here
		int D, P[1001], freq[1001], maxP = 0;
		FILL(freq, 0);
		fscanf(in, "%d", &D);
debug("D=%d\n", D);
		REP(i,D) {
			fscanf(in, "%d", &(P[i]));
			freq[P[i]]++;
			REMAX(maxP, P[i]);
debug(" %d", P[i]);
		}
debug("\n");
debug("MaxP = %d\n", maxP);

/*
		qType res = { 0, 0 };
		FOR(i,1,1000) {
			if (!freq[i]) continue;
			qType min_v = { i, res.et };	// Worse case, probably
			int N = sqrt(i);
			FOR(j,1,N-1) {
				// Optimization options
				qType v = { MAX(res.st, dmap[i][j]), res.et + freq[i]*j };
				if (qrank(v) < qrank(min_v)) {
					min_v = v;
				}
			}
			res = min_v;
debug("P-%d freq-%d Result: %d %d\n", i, freq[i], res.st, res.et);
		}
*/
		qType min_v = {maxP, 0};	// Default Result
debug("Test %d-%d st0=%d v=(%d %d)\n", maxP, 0, dmap[maxP][0], min_v.st, min_v.et);
		// Other possibilities
		{
			int N = sqrt(maxP);
			FOR(j,1,N-1) {
				int sp = dmap[maxP][j];	// Reference shared time
				qType v = cal(sp, freq, maxP);
debug("Test %d-%d st0=%d v=(%d %d)\n", maxP, j, sp, v.st, v.et);
				if (qrank(v) < qrank(min_v)) {
					min_v = v;
				}
			}
		}

debug("Try - %d\n",
		qrank(min_v)
);



		printf("Case #%d: ", c+1);
//	Result Calculation/Display put here
		printf("%d\n", qrank(min_v));
	}
	return 0;
}
