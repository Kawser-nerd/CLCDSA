	#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
#define REP(i, a, b) for(int i = int(a); i <= int(b); i++)
#define LOOP(i, v) for(int i = 0; i < v.size(); i++)
#define EPS 1e-9
#define INF 1e12
#define debug(x) cerr << "DEBUG : " << (#x) << " => " << (x) << endl

int visited1[205], visited2[205];

vi ngb[205];
vi vis;
vi match;

int augment(int l)
{
	if(vis[l]) return 0;
	vis[l] = 1;
	LOOP(i, ngb[l])
	{
		int r = ngb[l][i];
		if(!visited2[r])
		{
			if(match[r] == -1 || augment(match[r])) // If r is not matched we stop here. Otherwise we try to augment match[r]
			{
				match[r] = l;
				//fprintf(stderr, "match[%d] = %d\n", r, l);
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int T, N, M;
	char c;
	int x, y;
	
	scanf("%d\n", &T);

	REP(t, 1, T)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d: ", t);
		
		set<int> col, row;
		bool tablex[100][100];
		bool tablep[100][100];
		bool newx[100][100];
		bool newp[100][100];
		
		scanf("%d %d\n", &N, &M);
		
		REP(i, 0, N-1) REP(j, 0, N-1)
		{
			tablex[i][j] = false;
			tablep[i][j] = false;
			newx[i][j] = false;
			newp[i][j] = false;
		}
		
		REP(i, 0, N-1)
		{
			col.insert(i);
			row.insert(i);
		}
		
		REP(i, 0, 2*N-2)
		{
			ngb[i].clear();
			visited1[i] = false;
			visited2[i] = false;
		}
		
		REP(i, 0, N-1) REP(j, 0, N-1)
		{
			ngb[i+j].push_back(i-j+N-1);
			//fprintf(stderr, "%d -> %d\n", i+j, i-j+N-1);
		}
		
		REP(i, 0, M-1)
		{
			scanf("%c %d %d\n", &c, &x, &y);
			x--;
			y--;
			if(c == 'o' || c == 'x')
			{
				tablex[x][y] = true;
				newx[x][y] = true;
				row.erase(x);
				col.erase(y);
			}
			if(c == 'o' || c == '+')
			{
				tablep[x][y] = true;
				newp[x][y] = true;
				visited1[x+y] = true;
				visited2[x-y+N-1] = true;
			}
		}
		set<int>::iterator it, it2;
		it2 = col.begin();
		//cerr << "FOIS" << endl;
		for(it = row.begin(); it != row.end(); it++)
		{
			newx[*it][*it2] = true;
			//cerr << *it << " " << *it2 << endl;
			it2++;
		}
		
		//cerr << "PLUS" << endl;
		
		// Bipartite matching between diag1 and diag2
		match.assign(205, -1);
		REP(i, 0, 2*N-1)
		{
			if(!visited1[i])
			{
				vis.assign(205, 0);
				//fprintf(stderr, "Try to augment %d\n", i);
				augment(i);
			}
		}
		REP(i, 0, 2*N-1)
		{
			if(!visited2[i])
			{
				if(match[i] != -1)
				{
					int j = match[i];
					// x+y = j
					// x-y+N-1 = i ==> x-y = i+1-N
					// x = (j+i+1-N)/2
					x = (j+i+1-N)/2;
					y = j-x;
					newp[x][y] = true;
					//cerr << x << " " << y << endl;
				}
			}
		}
		int score = 0;
		int change = 0;
		vector<ii> changes;
		REP(i, 0, N-1)
		{
			REP(j, 0, N-1)
			{
				if(newp[i][j]) score++;
				if(newx[i][j]) score++;
				if(newp[i][j] != tablep[i][j] || newx[i][j] != tablex[i][j])
				{
					change++;
					changes.push_back(ii(i, j));
				}
			}
		}
		printf("%d %d\n", score, change);
		LOOP(i, changes)
		{
			x = changes[i].first;
			y = changes[i].second;
			if(newp[x][y] && newx[x][y]) printf("o %d %d\n", x+1, y+1);
			else if(newp[x][y]) printf("+ %d %d\n", x+1, y+1);
			else printf("x %d %d\n", x+1, y+1);
		}
	}
	
	return 0;
}
