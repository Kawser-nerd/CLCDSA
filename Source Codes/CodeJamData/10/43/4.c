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


int m[102][102];
int maxx, maxy;
void fill(int x1, int y1, int x2, int y2)
{
	for (int i = x1; i <= x2; i++)
	{
		for (int j = y1; j <= y2; j++)
		{
			m[i][j] = 1;
		}
	}
}
void printmap(void)
{
	for (int j = 1; j <= maxy; j++)
	{
		for (int i = 1; i <= maxx; i++)
		{
			printf(" %d", m[i][j]);
		}
		printf("\n");
	}
}

int gen(void)
{
int yes = 0;
	int nnew[102][102];
	memset(nnew, 0, sizeof(nnew));
	for (int j = 1; j <= maxy; j++)
	{
		for (int i = 1; i <= maxx; i++)
		{
			if (!m[i-1][j] && !m[i][j-1])
			{
				nnew[i][j] = 0;
			}
			else if (m[i-1][j] && m[i][j-1])
			{
				nnew[i][j] = 1;
			}
			else
			{
				nnew[i][j] = m[i][j];
			}
			if (nnew[i][j]) yes = 1;
//			printf(" %d", m[i][j]);
		}
//		printf("\n");
	}
	memcpy(m, nnew, sizeof(nnew));
//printmap();
//printf("\n");
	return yes;
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
	memset(m, 0, sizeof(m));
maxx = maxy = 0;
int r, x1, x2, y1, y2;

	scanf("%d", &r);
	REP(i,r)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
fill(x1, y1, x2, y2);
remax(maxx, x2);
remax(maxy, y2);
//printmap();
//printf("\n");
	}
int count = 1;
	while (gen()) count++;



		printf("Case #%d: ", c+1);
//	Result Calculation/Display put here
printf("%d\n", count);

	}
	return 0;
}
