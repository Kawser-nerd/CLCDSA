#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1010;

struct node
{
	int x,y,r;
} a[N];

struct edge
{
	int v;
	double cost;
	edge(int x,double b):v(x),cost(b){};
};
int n;
double d[N];
bool vis[N];

vector<edge> G[N];

double cal(int i,int j)
{
	double sum = a[i].r + a[j].r;
	double xx = 1.0 * (a[i].x - a[j].x) * (a[i].x - a[j].x);
	double yy = 1.0 * (a[i].y - a[j].y) * (a[i].y - a[j].y);
	double ans = sqrt(xx+yy);
	if (sum >= ans) return 0;
	else return ans - sum;
}

void dij(void)
{
	for (int i = 0;i <= n + 1;i++) d[i] = 1e30;
	d[0] = 0;
	for (int i = 0;i <= n;i++)
	{
		double mi = 1e30;
		int x;
		for (int j = 0;j <= n + 1;j++)
		{
			if (!vis[j] && d[j] < mi)
			{
				mi = d[j];
				x = j;
			}
		}
		if (mi == 1e30) break;
		vis[x] = 1;
		for (auto e : G[x])
		{
			double cost = e.cost;
			int v = e.v;
			if (d[v] > cost + d[x])
			{
				d[v] = cost + d[x];
			}
		}
	}
}

int main()
{
	scanf("%d%d",&a[0].x,&a[0].y);
	a[0].r = 0;
	int x,y;
	scanf("%d%d",&x,&y);
	scanf("%d",&n);
	a[n+1].x = x,a[n+1].y = y,a[n+1].r = 0;
	for (int i = 1;i <= n;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].r);
	for (int i = 0;i <= n + 1;i++)
	{
		for (int j = i + 1;j <= n + 1;j++)
		{
			double len = cal(i,j);
			G[i].push_back(edge(j,len));
			G[j].push_back(edge(i,len));
		}
	}
	dij();
	printf("%.15f\n",d[n+1]);
	return 0;
}