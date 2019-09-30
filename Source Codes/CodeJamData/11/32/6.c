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

ull L, t, N, C;
ull a[1001];
fscanf(in, "%llu %llu %llu %llu", &L, &t, &N, &C);
REP(i,C)
{
fscanf(in, "%llu", &(a[i]));
a[i]*=2;
}

ull count[20002];
memset(count, 0, sizeof(count));

// Before boost
ull acc[1001];
REP(i,C)
{
	if (i==0) acc[i] = a[i];
	else acc[i] = acc[i-1] + a[i]; 
}

/*
REP(i,C)
{
	printf("%d:%llu\n", i, acc[i]);
}
*/

ull sum = N/C*acc[C-1] + acc[(N%C) - 1];

ull safe = 0;
if (sum > t)
{	// Boost

//printf("sum = %llu, acc = %llu\n", sum, acc[C-1]);

	ull totcyc = sum/acc[C-1];
	ull lastacc = sum%acc[C-1];
//printf("totcyc = %llu\n", totcyc);
	REP(i,C)
	{
		count[a[i]] += totcyc;
		if (acc[i] <= lastacc) count[a[i]]++;
	}

/*
REP(i,20000)
{
	if (count[i] > 0)
	{
		printf("B %d %llu\n", i, count[i]);
	}
}
*/
	ull cycle = (t/acc[C-1]);
	ull tacc = t%acc[C-1];
	REP(i,C)
	{
		count[a[i]] -= cycle;
		if (acc[i] <= tacc) count[a[i]]--;
		if (acc[i] > tacc && a[i] > acc[i] - tacc)
		{
			count[a[i]]--;
			count[acc[i] - tacc]++;
		}
	}
/*
REP(i,20000)
{
	if (count[i] > 0)
	{
		printf("C %d %llu\n", i, count[i]);
	}
}
*/
	int s;
ull boost = L;
	for (s = 20000; s >= 0 && boost > 0; s--)
	{
		if (count[s] > 0)
		{
			ull min = MIN(boost,count[s]);
//printf("S,count,B,M = %ld, %ld, %llu, %llu\n", s, count[s], boost, min);
			boost -= min;
			safe += s*min;
		}
	}
//printf("SAFE=%llu\n", safe);
}


/*
ull trip = acc[C-1];

ull cycle = t / trip;
ull sum = cycle * trip;

ull t % trip
*/



		printf("Case #%d: ", c+1);
//	Result Calculation/Display put here
if (safe%2 == 0)
{
printf("%llu\n", sum-(safe/2));
}
else
{
printf("%lf\n", (double)sum-(0.5*safe));
}
	}
	return 0;
}
