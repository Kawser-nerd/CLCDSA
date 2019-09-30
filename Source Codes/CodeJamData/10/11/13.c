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

int test(int mz, int m[60][60], int K)
{
// 01 R
// 10 B
int res = 0;
	REP(i, mz)
	{
	REP(j, mz)
	{
if (!(m[i][j] == 'B' || m[i][j] == 'R')) continue;
if (m[i][j] == 'B' && (res & 0x10)) continue;
if (m[i][j] == 'R' && (res & 0x01)) continue;
//printf("K:%d\n", K);
int match = 0;
if (i+K < mz)	// ---
{
	int x = 1;
	for (int k = i; k <= i+K; k++)
	{
		if (m[k][j] != m[i][j]) { x = 0; break; }
	}
	if (x) match = 1;
//printf("Match |? %d\n", x);
}
if (j+K < mz)   // ||
{
	int x = 1;
	for (int k = j; k <= j+K; k++)
	{
		if (m[i][k] != m[i][j]) { x = 0; 
//printf("i j k %d %d %d Failed\n", i, j, k);
break; }
	}
//printf("x = %d\n", x);
	if (x) match = 1;
//printf("Match -? %d\n", x);
}
if (i+K < mz && j+K < mz)   //
{
	int x = 1;
	for (int k = 0; k <= K; k++)
	{
		if (m[i][j] != m[i+k][j+k]) { x = 0; break; }
	}
	if (x) match = 1;
//printf("Match \? %d\n", x);
}
if (i-K >= 0 && j+K < mz)
{
	int x = 1;
	for (int k = 0; k <= K; k++)
	{
		if (m[i][j] != m[i-k][j+k]) { x = 0; break; }
	}
	if (x) match = 1;
//printf("Match /? %d\n", x);
}
//		printf("%c", (m[i][j] == 0? '.': m[i][j]));
if (match)
{
	res |= (m[i][j] == 'B'? 0x10: 0x01);
}
//printf("res(%d,%d): %d\n", i, j, res);
if (res == 0x11) break;
	}
//	printf("\n");
	}
//printf("res: %d\n", res);
return res;
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
	char buf[255];
int K, mz;
int m[60][60];
memset(m, 0, sizeof(m));
fgets(buf, 255, stdin);
sscanf(buf, "%d %d", &mz, &K);
//printf("%d", mz);
for (int i = 0; i < mz; i++)
{
	fgets(buf, 255, stdin);
	int bufz = strlen(buf);
	int pos = mz - 1;
//printf("%d: %s", i, buf);
	for (int j = bufz - 1; j >= 0; j--)
	{
		if (buf[j] == 'R' || buf[j] == 'B')
		{
			m[i][pos--] = buf[j];
		}
	}
}
int r = test(mz, m, K-1);

		printf("Case #%d: ", c+1);
//	Result Calculation/Display put here
printf("%s\n", r == 0x11? "Both": (r == 0x10? "Blue": (r == 0x01? "Red": "Neither")));
	}
	return 0;
}
