#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<list>
#include<map>
#include<queue>

#define FOR(i,a,b) for(int i=(int)(a); i<(int)(b); ++i)
#define FORE(it,C) for(__typeof(C.begin()) it=C.begin(); it!=C.end(); ++it)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

using namespace std;

struct Intersect {
	int S,W,T;
};

const int INF = 2000000000;

int N,M;
Intersect tabN[25][25];
int res[25][25][2][2];

int waitForS(int x, int y, int ti)
{
	int S = tabN[x][y].S;
	int W = tabN[x][y].W;
	int T = tabN[x][y].T;
	T = T%(S+W);
	ti %= S+W;
	ti -= T;
	if(ti<0)
		ti += S+W;
	if(ti+1<=S)
		return 0; else
		return S+W-ti;
}

int waitForW(int x, int y, int ti)
{
	int S = tabN[x][y].S;
	int W = tabN[x][y].W;
	int T = tabN[x][y].T;
	T = T%(S+W);
	ti %= S+W;
	ti -= T;
	if(ti<0)
		ti += S+W;
	if(ti>=S && ti+1<=S+W)
		return 0; else if(ti<S)
		return S-ti; else
		return S;
}



void testcase(int testNr) {

	scanf("%d %d",&N,&M);
	FOR(i,0,N) FOR(j,0,M)
		scanf("%d %d %d", &tabN[i][j].S, &tabN[i][j].W, &tabN[i][j].T);
		
	FOR(i,0,N) FOR(j,0,M) FOR(a,0,2) FOR(b,0,2)
		res[i][j][a][b] = INF;
		
	res[N-1][0][1][0] = 0;
	
	while(true) {
		int cN = -1;
		int cM = -1;
		int cA = -1;
		int cB = -1;
		int best = INF;
		FOR(i,0,N) FOR(j,0,M) FOR(a,0,2) FOR(b,0,2)
			if(res[i][j][a][b] >= 0 && res[i][j][a][b]<best) {
				best = res[i][j][a][b];
				cN = i;
				cM = j;
				cA = a;
				cB = b;
			}
		if(best == INF)
			break;
			
		//printf("(%d,%d,%d,%d) = %d\n",cN,cM,cA,cB,best);
			
		res[cN][cM][cA][cB] = -best - 1;
		if(cA==0 && cN>0)
			res[cN-1][cM][1][cB] = min(res[cN-1][cM][1][cB], best + 2);
		if(cA==1 && cN<N-1)
			res[cN+1][cM][0][cB] = min(res[cN+1][cM][0][cB], best + 2);
		if(cB==0 && cM>0)
			res[cN][cM-1][cA][1] = min(res[cN][cM-1][cA][1], best + 2);
		if(cB==1 && cM<M-1)
			res[cN][cM+1][cA][0] = min(res[cN][cM+1][cA][0], best + 2);
			
		res[cN][cM][1-cA][cB] = min(res[cN][cM][1-cA][cB], best + 1 + waitForS(cN, cM, best));
		res[cN][cM][cA][1-cB] = min(res[cN][cM][cA][1-cB], best + 1 + waitForW(cN, cM, best));
	}
	
	printf("Case #%d: %d\n",testNr, -res[0][M-1][0][1] -1);
}

int main() {
	int t;
	scanf("%d",&t);
	FOR(i,0,t)
		testcase(i+1);
}
