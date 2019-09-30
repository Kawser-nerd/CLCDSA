#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 105

struct coord
{
	int x, y;
};

struct coordd
{
	double x, y;
};

static struct coordd c[2*MAXN+5];
int cc;
static struct coordd d[2*MAXN+5];
int dc;

double FindS (struct coord a[MAXN], int ac, struct coord b[MAXN], int bc, double L)
{
	cc = 0;
	dc = 0;
	int i = 0;
	while (i < ac)
	{
		if (((double)(a[i].x) - 1E-9) > L) break;
		c[cc].x = (double)(a[i].x);
		c[cc].y = (double)(a[i].y);
		cc++;
		i++;
	}
	i--;
	if (fabs((double)(a[i].x) - L) >= 1E-9)
	{
		//Add new point
		double L2 = (double)(a[i].y) + ((L - (double)(a[i].x)) / (double)(a[i+1].x - a[i].x)) * (double)(a[i+1].y - a[i].y);
		c[cc].x = L;
		c[cc].y = L2;
		cc++;
	}
	i = 0;
	while (i < bc)
	{
		if (((double)(b[i].x) - 1E-9) > L) break;
		d[dc].x = (double)(b[i].x);
		d[dc].y = (double)(b[i].y);
		dc++;
		i++;
	}
	i--;
	if (fabs((double)(b[i].x) - L) >= 1E-9)
	{
		//Add new point
		double L2 = (double)(b[i].y) + ((L - (double)(b[i].x)) / (double)(b[i+1].x - b[i].x)) * (double)(b[i+1].y - b[i].y);
		d[dc].x = L;
		d[dc].y = L2;
		dc++;
	}
	for (i = dc-1; i >= 0; i--)
	{
		c[cc] = d[i];
		cc++;
	}
	double res = 0.0;
	struct coordd A, B;
	for (i = 1; (i+1) < cc; i++)
	{
		A.x = c[i].x - c[0].x;
		A.y = c[i].y - c[0].y;
		B.x = c[i+1].x - c[0].x;
		B.y = c[i+1].y - c[0].y;
		res += (A.x * B.y - A.y * B.x);
	}
	res = fabs(res);
	return res;
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static struct coord a[MAXN];
	static struct coord b[MAXN];
	for (iT = 0; iT < T; iT++)
	{
		int W, ac, bc, K;
		scanf("%d %d %d %d",&W,&ac,&bc,&K);
		int i;
		for (i = 0; i < ac; i++)
		{
			scanf("%d %d",&(a[i].x),&(a[i].y));
		}
		for (i = 0; i < bc; i++)
		{
			scanf("%d %d",&(b[i].x),&(b[i].y));
		}
		double S = FindS(a,ac,b,bc,(double)(W));
		double SP = S / (double)(K);
		printf("Case #%d:\n",iT+1);
		double l, r, c, S2;
		for (i = 1; i < K; i++)
		{
			l = 0.0; r = (double)(W);
			while ((r-l) > 1E-8)
			{
				c = (l+r)/2;
				S2 = FindS(a,ac,b,bc,c);
				if ((S2 + 1E-9) >= (SP * (double)(i))) r = c;
				else l = c;
			}
			printf("%.8lf\n",l);
		}
	}
	return 0;
}
