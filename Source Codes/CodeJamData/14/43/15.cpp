#include <cstdio>
#include <algorithm>
using namespace std;

const int max_n = 1024;
const int inf = 1000000000;
int w, h, n;
int lx[max_n], ly[max_n], ux[max_n], uy[max_n];
int dist[max_n][max_n], pot[max_n];
bool vis[max_n];

int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d %d %d", &w, &h, &n);
		lx[0] = -1; ly[0] = 0;
		ux[0] = -1; uy[0] = h - 1;
		for(int i = 1; i <= n; i++)
			scanf("%d %d %d %d", &lx[i], &ly[i], &ux[i], &uy[i]);
		n++;
		lx[n] = w; ly[n] = 0;
		ux[n] = w; uy[n] = h - 1;
		n++;
		for(int i = 0; i < n; i++)
		{
			dist[i][i] = 0;
			for(int j = 0; j < i; j++)
			{
				int xdist, ydist;
				if(ux[i] < lx[j])
					xdist = lx[j] - ux[i] - 1;
				else if(ux[j] < lx[i])
					xdist = lx[i] - ux[j] - 1;
				else
					xdist = 0;
				if(uy[i] < ly[j])
					ydist = ly[j] - uy[i] - 1;
				else if(uy[j] < ly[i])
					ydist = ly[i] - uy[j] - 1;
				else
					ydist = 0;
				dist[i][j] = dist[j][i] = max(xdist, ydist);
			}
		}
		/*
		for(int i = 0; i < n; printf("\n"), i++)
			for(int j = 0; j < n; j++)
				printf("%d ", dist[i][j]);
				*/
		pot[0] = 0, vis[0] = false;
		for(int i = 1; i < n; i++)
			pot[i] = inf, vis[i] = false;
		while(true)
		{
			int mpot = inf, mv = -1;
			for(int i = 0; i < n; i++)
				if(!vis[i] && mpot > pot[i])
					mpot = pot[i], mv = i;
			if(mv == -1)
				break;
			vis[mv] = true;
			for(int i = 0; i < n; i++)
				pot[i] = min(pot[i], pot[mv] + dist[mv][i]);
		}
		printf("Case #%d: %d\n", t, pot[n - 1]);
	}
	return 0;
}
