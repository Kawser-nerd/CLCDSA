#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;
int H,N,M;
int C[101][101];
int F[101][101];
int v[101][101];

struct node{
	int x,y;
};

int off[4][2] = {
{0,-1}, {0,1}, {-1, 0}, {1,0}
};

void solve()
{
	int i,j,k;
	for(i=0; i<N; i++) for(j=0; j<M; j++) v[i][j] = 1000000000;
	node c,t;
	c.x = 0; c.y = 0;
	v[c.x][c.y] = -1;
	deque<node> qu;
	qu.push_back(c);
	while(!qu.empty())
	{
		c = qu.front(); qu.pop_front();
		int curt = v[c.x][c.y];

//		printf("%d %d %d\n", c.x, c.y, curt);

		int curw;
		if (curt < 0) curw = H;
		else curw = H-curt;
		if (curw < F[c.x][c.y]) curw = F[c.x][c.y];

		for(i=0; i<4; i++)
		{
			t = c;
			t.x += off[i][0]; t.y += off[i][1];
			if (!(t.x >= 0 && t.x < N && t.y >= 0 && t.y < M)) continue;
			if (C[t.x][t.y] - F[c.x][c.y] < 50) continue;
			if (C[t.x][t.y] - F[t.x][t.y] < 50) continue;
			if (C[c.x][c.y] - F[t.x][t.y] < 50) continue;
			
			int wait = 0; int nextt = curt;

			if (C[t.x][t.y] - curw < 50)
				wait = 50-C[t.x][t.y]+curw;
			if (wait < 0) wait = 0;
			//printf("%d %d %d\n", C[t.x][t.y], curw, wait);

			int neww = curw - wait;

			if (wait == 0)
			{
				if (nextt > 0)
				{
					if (neww-F[c.x][c.y] >= 20) nextt+=10;
					else nextt+=100;
				}
				else
					nextt = -1;
			}
			else
			{
				if (nextt < 0) nextt = 0;
				nextt += wait;
				if (neww-F[c.x][c.y] >= 20) nextt+=10;
				else nextt += 100;
			}

			//printf("[%d,%d] to [%d,%d] wait=%d\n", c.x, c.y, t.x, t.y, wait);
			if (nextt < v[t.x][t.y])
			{
				v[t.x][t.y] = nextt;
				qu.push_back(t);
			}
		}
	}
	int r = v[N-1][M-1];
	if (v[N-1][M-1] < 0) printf(" 0.0\n");
	else printf(" %d.%d\n", r/10, r%10);
}

int main()
{
	int cc,ca;
	int i,j,k;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> H >> N >> M;
		for(i=0; i<N; i++)
			for(j=0; j<M; j++)
				cin >> C[i][j];
		for(i=0; i<N; i++)
			for(j=0; j<M; j++)
				cin >> F[i][j];
		printf("Case #%d:", cc);
		solve();
	}
}
