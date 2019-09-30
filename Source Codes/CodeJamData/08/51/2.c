#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <set>
using namespace std;

int offset[4][2] = 
{
	{0,1}, {-1,0}, {0,-1}, {1, 0}
};

set<pair<pair<int,int>, pair<int,int> > > eg;
int x, y, dir;

void doit(string act)
{
	int i,j,k;
	int nx,ny;
	for(i=0; i<act.size(); i++)
	{
		switch(act[i])
		{
		case 'F':
			if (dir == 0)
			{
				eg.insert(make_pair(make_pair(x,y), make_pair(x-1,y)));
				eg.insert(make_pair(make_pair(x-1,y), make_pair(x,y)));
			}
			else if (dir == 1)
			{
				eg.insert(make_pair(make_pair(x-1,y-1), make_pair(x-1,y)));
				eg.insert(make_pair(make_pair(x-1,y), make_pair(x-1, y-1)));
			}
			else if (dir == 2)
			{
				eg.insert(make_pair(make_pair(x,y-1), make_pair(x-1,y-1)));
				eg.insert(make_pair(make_pair(x-1,y-1), make_pair(x, y-1)));
			}
			else
			{
				eg.insert(make_pair(make_pair(x,y), make_pair(x,y-1)));
				eg.insert(make_pair(make_pair(x,y-1), make_pair(x,y)));
			}
			x += offset[dir][0];
			y += offset[dir][1];
			break;
		case 'L':
			dir = (dir + 3)%4;
			break;
		case 'R':
			dir = (dir + 1)%4;
			break;
		}
	}
}

#define MAXN 202
int map[MAXN][MAXN];

int main()
{
	int cc,ca;
	int i,j,k;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		int T;
		eg.clear();
		x = 101; y = 101; dir = 3;
		cin >> T;
		for(i=0; i<T; i++)
		{
			string s; int rep;
			cin >> s >> rep;
			for(j=0; j<rep; j++)
				doit(s);
		}
		memset(map, 0, sizeof(map));
		for(i=0; i<MAXN; i++) for(j=0; j<MAXN; j++)
		{
			int count = 0;
			int cx = i; int cy = j;
			while(1)
			{
				int nx = cx + 1;
				if (nx >= MAXN) break;
				if (eg.find(make_pair(make_pair(cx,cy), make_pair(nx, cy))) != eg.end())
					count++;
				cx++;
			}
			if (count%2 != 0)
				map[i][j] = 1;
		}
/*
		for(i=0; i<50; i++)
		{
			for(j=0; j<50; j++)
				printf("%d", map[i][j]);
			printf("\n");
		}
*/
		int rr = 0;
		for(i=0; i<MAXN; i++) for(j=0; j<MAXN; j++)
		{
			if (map[i][j]) continue;
			int flag = 0;
			int cx = i; int cy = j;
			while(1)
			{
				if (cy == 0) break;
				if (eg.find(make_pair(make_pair(cx, cy), make_pair(cx, cy-1))) != eg.end())
				{
		//			printf("%d %d %d %d\n", cx, cy, cx, cy-1);
					flag = 1;
					break;
				}
				cy--;
			}
			if (flag)
			{
				cy = j;
				while(1)
				{
					if (cy == MAXN-1) break;
					if (eg.find(make_pair(make_pair(cx, cy), make_pair(cx, cy+1))) != eg.end())
					{
				//		printf("%d %d %d %d\n", cx, cy, cx, cy+1);
						flag = 2;
						break;
					}
					cy++;
				}
				if (flag == 2)
				{
					rr++;
			//		printf("%d %d\n", i, j);
					continue;
				}
			}

			cx = i; cy = j;
			flag = 0;
			while(1)
			{
				if (cx == 0) break;
				if (eg.find(make_pair(make_pair(cx, cy), make_pair(cx-1, cy))) != eg.end())
				{
				//	printf("%d %d %d %d\n", cx, cy, cx-1, cy);
					flag = 1;
					break;
				}
				cx--;
			}
			cx = i; cy = j;
			if (flag)
			{
				cx = i; cy = j;
				while(1)
				{
					if (cx == MAXN-1) break;
					if (eg.find(make_pair(make_pair(cx, cy), make_pair(cx+1, cy))) != eg.end())
					{
						//printf("%d %d %d %d\n", cx, cy, cx+1, cy);
						flag = 2;
						break;
					}
					cx++;
				}
				if (flag == 2)
				{
					rr++;
					//printf("%d %d\n", i, j);
					continue;
				}
			}
		}
		fprintf(stderr, "Case %d\n", cc);
		printf("Case #%d: %d\n", cc, rr);
	}
}
