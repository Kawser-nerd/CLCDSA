#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 2005

struct node
{
	int s, v;
	double t, t2;
};

struct datanode
{
	int l, r, v;
};

void sort1 (struct datanode a[MAXN], int l, int r)
{
	int i, j, x;
	struct datanode y;
	i = l; j = r; x = a[(l+r)/2].l;
	while (i <= j)
	{
		while (a[i].l < x) i++;
		while (a[j].l > x) j--;
		if (i <= j)
		{
			y = a[i]; a[i] = a[j]; a[j] = y;
			i++; j--;
		}
	}
	if (l < j) sort1(a,l,j);
	if (i < r) sort1(a,i,r);
}

double Module (double a)
{
	if (a < 0.0) return -1.0 * a;
	else return a;
}

void sort2 (struct node a[MAXN], int l, int r)
{
	int i, j;
	struct node x, y;
	i = l; j = r; x = a[(l+r)/2];
	while (i <= j)
	{
		while (a[i].v < x.v) i++;
		while (a[j].v > x.v) j--;
		//while (((a[i].t2 - 1E-9) > x.t2) || ((Module(a[i].t2 - x.t2) < 1E-9) && (a[i].s < x.s))) i++;
		//while (((a[j].t2 + 1E-9) < x.t2) || ((Module(a[i].t2 - x.t2) < 1E-9) && (a[j].s > x.s))) j--;
		if (i <= j)
		{
			y = a[i]; a[i] = a[j]; a[j] = y;
			i++; j--;
		}
	}
	if (l < j) sort2(a,l,j);
	if (i < r) sort2(a,i,r);
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static struct node a[MAXN];
	int ac;
	static struct datanode data[MAXN];
	for (iT = 0; iT < T; iT++)
	{
		int M, S, R, t, N;
		scanf("%d %d %d %d %d",&M,&S,&R,&t,&N);
		int i;
		for (i = 0; i < N; i++)
		{
			scanf("%d %d %d",&(data[i].l),&(data[i].r),&(data[i].v));
		}
		sort1(data,0,N-1);
		int pos = 0;
		ac = 0;
		for (i = 0; i < N; i++)
		{
			if (data[i].l > pos)
			{
				a[ac].s = data[i].l - pos;
				a[ac].v = S;
				a[ac].t = (double)(a[ac].s) / (double)(a[ac].v);
				a[ac].t2 = (double)(a[ac].s) / (double)(a[ac].v + (R-S));
				pos = data[i].l;
				ac++;
			}
			a[ac].s = data[i].r - data[i].l;
			a[ac].v = data[i].v + S;
			a[ac].t = (double)(a[ac].s) / (double)(a[ac].v);
			a[ac].t2 = (double)(a[ac].s) / (double)(a[ac].v + (R-S));
			pos = data[i].r;
			ac++;
		}
		if (pos != M)
		{
			a[ac].s = M - pos;
			a[ac].v = S;
			a[ac].t = (double)(a[ac].s) / (double)(a[ac].v);
			a[ac].t2 = (double)(a[ac].s) / (double)(a[ac].v + (R-S));
			ac++;
		}
		sort2(a,0,ac-1);
		double res = 0.0;
		double rem = (double)(t);
		for (i = 0; i < ac; i++)
		{
			if (rem < 1E-9) res += a[i].t;
			else if ((a[i].t2 + 1E-9) <= rem)
			{
				res += a[i].t2;
				rem -= a[i].t2;
			}
			else
			{
				double s2 = rem * (double)(a[i].v + (R-S));
				double s3 = (double)(a[i].s) - s2;
				res += (rem + s3 / (double)(a[i].v));
				rem = 0.0;
			}
		}
		printf("Case #%d: %.10lf\n",iT+1,res);
	}
	return 0;
}
