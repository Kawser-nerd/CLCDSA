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

int P;
int M[2000];
int C[1000][1000];

int re(int lv, int prefix, int *MM)
{
ull res = 10000000000000ULL;
	int nozero = 0;
	int base = prefix << lv;
if (lv == 0) return 0;
	for (int i = 0; i < POW2(lv); i++)
	{
		if (MM[base+i] == 0)
		{
			nozero = 1;
			break;
		}
	}
	if (!nozero)
	{
		int MM1[2000];
		memcpy(MM1, MM, sizeof(MM1));
		for (int i = 0; i < POW2(lv); i++)
		{
			MM1[base+i]--;
		}
		ull c1 = re(lv-1, prefix<<1, MM1);
		if (c1 >= 0)
		{
			ull c2 = re(lv-1, (prefix<<1)+1, MM1);
			if (c1 >= 0 && c2 >= 0)
			{
				remin(res, c1+c2);
			}
		}
	}
	{
		ull c1 = re(lv-1, prefix<<1, MM);
		if (c1 >= 0)
		{
			ull c2 = re(lv-1, (prefix<<1)+1, MM);
			if (c1 >= 0 && c2 >= 0)
			{
				remin(res, c1+c2+C[lv-1][prefix]);
			}
		}
	}
return (res != 10000000000000ULL? res: -1);

}

// Main Program (Start Here)
int main(int argc, char *argv[])
{
	char buf[4096];
	FILE *in = stdin;
	int N;

	FGETS(buf, 4096, in);
	sscanf(buf, "%d", &N);
	REP(c,N)
	{
//	Data preparaion put here

scanf("%d", &P);
for (int i = 0; i < POW2(P); i++)
{
	scanf("%d", &(M[i]));
}
for (int i = 0; i < P; i++)
{
	for (int j = 0; j < POW2(P-i-1); j++)
	scanf("%d", &(C[i][j]));
}

if (0)
{
//printf("%d\n", P);
for (int i = 0; i < POW2(P); i++)
{
	printf(" %d", M[i]);
}
//printf("\n");
for (int i = 0; i < P; i++)
{
	for (int j = 0; j < POW2(P-i-1); j++)
	printf(" %d", C[i][j]);
printf("\n");
}
}

ull cost = re(P, 0, M);
/*
for (i = 0; i < POW2(P); i++)
for (i = 0; i < POW2(P-1); i++)

for (i = POW2(P-1); i < POW2(P); i++)
*/


		printf("Case #%d: ", c+1);
//	Result Calculation/Display put here
printf("%llu\n", cost);

	}
	return 0;
}
