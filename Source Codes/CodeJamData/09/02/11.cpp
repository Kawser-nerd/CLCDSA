#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <queue>
#include <bitset>
#include <sstream>
#include <vector>
using namespace std;

#define	sz(v)	(int)v.size()
#define	rep(i,n)	for((i)=0;(i) < (n); (i)++)
#define	rab(i,a,b)	for((i)=(a);(i) <= (b); (i)++)
#define	Fi(N)		rep(i,N)
#define	Fj(N)		rep(j,N)
#define	Fk(N)		rep(k,N)

typedef pair<int,int>	PII;
typedef pair<int,PII>	PIPII;

int	dr[] = {-1,0,0,1};
int	dc[] = {0,-1,1,0};

int	alt[200][200];
int	basin[200][200];
int	H,W;

PII getNext(int r, int c)
{
	int	i,nr,nc;
	PII	next;
	int	a = alt[r][c];

	next = PII(-1,-1);

	Fi(4)
	{
		nr = r + dr[i];
		nc = c + dc[i];

		if(nr <  0 || nr >= H || nc < 0 || nc >= W) continue;

		if(alt[nr][nc] < a)
		{
			next = PII(nr,nc);
			a = alt[nr][nc];
		}
	}

	return next;
}

void dfs(int r, int c,int label)
{
	int	i;
	int	nr,nc;
	PII	next;

	basin[r][c] = label;

	Fi(4)
	{
		nr = r + dr[i];
		nc = c + dc[i];

		if(nr < 0 || nr >= H || nc < 0 || nc >= W) continue;

		next = getNext(nr,nc);

		if(next.first == r && next.second == c)
			dfs(nr,nc,label);
	}
}

map <int,char>	basinChar;
int main()
{
	int	T,cs;
	vector <PIPII>	cell;
	int	i,j,k;

	scanf("%d",&T);

	rab(cs,1,T)
	{
		scanf("%d %d",&H, &W);

		cell.clear();

		Fi(H) Fj(W)
		{
			scanf("%d",&alt[i][j]);
			cell.push_back(PIPII(alt[i][j],PII(i,j)));
		}
		memset(basin,0,sizeof(basin));
		sort(cell.begin(),cell.end());
		int	l = 1;

		Fk(sz(cell))
		{
			PII	start = cell[k].second;

			if(basin[start.first][start.second] == 0)
			{
				assert(l <= 26);
				dfs(start.first, start.second, l++);
			}
		}
		printf("Case #%d:\n",cs);

		basinChar.clear();
		char	label = 'a';

		Fi(H)
		{
			Fj(W)
			{
				if(j != 0) printf(" ");
				char	ch;

				if(basinChar.find(basin[i][j]) == basinChar.end())
					basinChar[basin[i][j]] = label++;
				printf("%c",basinChar[basin[i][j]]);
			}
			printf("\n");
		}
	}
	return 0;
}
