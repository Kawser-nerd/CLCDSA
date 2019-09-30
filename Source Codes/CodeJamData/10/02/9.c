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


#define BIGINT_MAXSIZE 60
typedef struct {
	int size;
	char value[BIGINT_MAXSIZE+1];
} bigint;

int bigint_compare(bigint *a, bigint *b)
{
	if (a->size != b->size)
	{
		return (a->size > b->size? 1: -1);
	}
	else
	{
		int i;
		for (i = 0; i < a->size; i++)
		{
			if (a->value[i] != b->value[i])
			{
				return (a->value[i] > b->value[i]? 1: -1);
			}
		}
	}
	return 0;
}

int bigint_absdiff(bigint *a, bigint *b, bigint *c)
{
	bigint tmp;
if (0)
{
	long long va, vb, vc;
	sscanf(a->value, "%lld", &va);
	sscanf(b->value, "%lld", &vb);
	vc = va - vb;
	if (vc < 0) vc = -vc;
	sprintf(c->value, "%lld", vc);
//printf("vavb: %llu %llu\n", va, vb);
	c->size = strlen(c->value);
}

	bigint *big;
	bigint *small;
	if (bigint_compare(a, b) > 0)
	{
		big = a;
		small = b;
	}
	else
	{
		big = b;
		small = a;
	}

	int minus_start = (big->size - small->size);
	memset(&tmp, 0, sizeof(bigint));
	tmp.value[big->size] = 0;
	for (int i = big->size - 1; i >= 0; i--)
	{
		if (i < minus_start)
		{
			tmp.value[i] += (big->value[i] - '0');
		}
		else
		{
			tmp.value[i] += (big->value[i] - small->value[i-minus_start]);
		}
		if (tmp.value[i] < 0)
		{
			tmp.value[i] += 10;
			tmp.value[i-1]--;
		}
		tmp.value[i] += '0';
	}
	while (tmp.value[0] == '0' && strlen(tmp.value) > 1)
	{
		memmove(tmp.value, tmp.value+1, (strlen(tmp.value))*sizeof(char));
	}
	tmp.size = strlen(tmp.value);
//printf("|(%s) - (%s)| = (%s)\n", a->value, b->value, tmp.value);
//printf("|(%s) - (%s)| = (%s)\n", big->value, small->value, tmp.value);
	memcpy(c, &tmp, sizeof(bigint));
	return 1;
}

int bigint_mod(bigint *a, bigint *b, bigint *c)
{
	bigint tmp;
	memcpy(&tmp, a, sizeof(bigint));
	while (bigint_compare(&tmp, b) >= 0)
	{
		bigint t2;
		memcpy(&t2, b, sizeof(bigint));
		while (t2.size < tmp.size - 1)
		{
			t2.value[t2.size++] = '0';
			t2.value[t2.size] = 0;
		}
		while (bigint_compare(&tmp, &t2) >= 0)
		{
			bigint_absdiff(&tmp, &t2, &tmp);
		}
	}
	memcpy(c, &tmp, sizeof(bigint));
if (0)
{
	long long va, vb, vc;
	sscanf(a->value, "%lld", &va);
	sscanf(b->value, "%lld", &vb);
	vc = va % vb;
	sprintf(c->value, "%lld", vc);
	c->size = strlen(c->value);
}
	return 1;
}

int bigint_gcd(bigint *a, bigint *b, bigint *result)
{
	bigint big, small;
	if (bigint_compare(a, b) > 0)
	{
		memcpy(&big, a, sizeof(bigint));
		memcpy(&small, b, sizeof(bigint));
	}
	else
	{
		memcpy(&big, b, sizeof(bigint));
		memcpy(&small, a, sizeof(bigint));
	}
	while (small.value[0] != '0')
	{
		bigint tmp;
		bigint_mod(&big, &small, &tmp);
		memcpy(&big, &small, sizeof(bigint));
		memcpy(&small, &tmp, sizeof(bigint));
	}
	memcpy(result, &big, sizeof(bigint));
	return 1;
}

bool sort_bigint(bigint a, bigint b)
{
	return (bigint_compare(&a, &b) == -1);
}

int DEBUG = 0;//1;

// Main Program (Start Here)
int main(int argc, char *argv[])
{
	char buf[409600];
	FILE *in = stdin;
	int N;

	FGETS(buf, 4096, in);
	sscanf(buf, "%d", &N);
	REP(c,N)
	{
//	Data preparaion put here
int tz;
bigint t[1010];
bigint dt[1010];	// dt[i] = t[i+1] - t[i]
{
	int i, len, n;
	buf[0] = 0;
	fgets(buf, 409600, stdin);
	sscanf(buf, "%d%n", &tz, &n);
	for (i = 0, len = n; i < tz; i++, len += n)
	{
		sscanf(buf+len, "%s%n", t[i].value, &n);
		t[i].size = strlen(t[i].value);
	}
}

sort(t, t+tz, sort_bigint);

// Debug
if (DEBUG)
{
	printf("[%d]",tz);
	REP(i,tz)
	{
		printf(" (%s)", t[i].value);
	}
	printf("\n");
}


	REP(i,tz-1)
	{
		bigint_absdiff(&(t[i+1]), &(t[i]), &(dt[i]));
	}
if (DEBUG)
{
	printf("DT:");
	REP(i,tz-1)
	{
		printf(" (%s)", dt[i].value);
	}
	printf("\n");
}

bigint gcd;
	{
		int i;
		memcpy(&gcd, &(dt[0]), sizeof(bigint));
		for (i = 1; i < tz-1; i++)
		{
if (DEBUG)
{
printf("GCD[%d] of [%s] [%s] ", i, gcd.value, dt[i].value);
}
			bigint_gcd(&dt[i], &gcd, &gcd);
if (DEBUG)
{
printf("= (%s)\n", gcd.value);
}
		}
	}


bigint tmp;
{
	bigint_mod(&t[0], &gcd, &tmp);
	if (tmp.value[0] != '0')
	{
		bigint_absdiff(&gcd, &tmp, &tmp);
	}
}

		printf("Case #%d: ", c+1);
//	Result Calculation/Display put here
REP(i,tmp.size)
{
	printf("%c", tmp.value[i]);
}
printf("\n");

	}
	return 0;
}
