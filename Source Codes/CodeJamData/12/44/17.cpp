#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <bitset>
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,w) memset((x),w,sizeof (x))
#define X first
#define Y second
#define INF 1000000007
typedef long long int lli;
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef vector<int> VI;
typedef bitset<3700> BITS;

#define MAXN 63
string pl[MAXN];
bool vis[MAXN][MAXN];
int ile,R,C;

int dx[]={1,0,0};
int dy[]={0,1,-1};

void dfs(int x,int y){
	vis[x][y] = true;
	ile++;
	REP(k,3){
		int xx=x-dx[k];
		int yy=y-dy[k];
		if(pl[xx][yy] != '#' && !vis[xx][yy])
			dfs(xx,yy);
	}
}

BITS move(BITS b, int k){
	BITS res;
	REP(x,R) REP(y,C)
		if(b[x*C+y]){
			int xx=x+dx[k];
			int yy=y+dy[k];
			if(pl[xx][yy] == '#')
				res[x*C+y] = true;
			else
				res[xx*C+yy] = true;
		}
	return res;
}

struct SS{
	BITS b;
	bool operator<(const SS& x) const{
		REP(i,R*C)
			if(b[i] != x.b[i])
				return (b[i] < x.b[i]);
		return false;
	}
	SS(BITS bb):b(bb){};
};

bool luck;
set<SS> S;
BITS zle;

void go(BITS b){
	SS ss(b);
	S.insert(ss);
	if(b.count() == 1)
		luck = true;
	REP(k,3){
		if(luck) break;
		BITS v = move(b, k);
		if((v&zle).any())
			continue;
		SS ss(v);
		if(!S.count(ss))
			go(v);
	}
}

int main(){ 
	int T;
	cin >> T;
	FOR(t,1,T){
		//in
		cin >> R >> C;
		REP(i,R) cin >> pl[i];
		//sol
		cout << "Case #" << t << ":" << endl;
		REP(q,10){
			ile=0;
			CLR(vis, 0);
			REP(i,R) REP(j,C)
				if(pl[i][j] == '0' + q)
					dfs(i,j);
			//
			BITS all;
			REP(i,R) REP(j,C)
				if(vis[i][j])
					all[i*C+j]=true;
			REP(i,R*C) zle[i] = !all[i];
			S.clear();
			luck = false;
			go(all);
			//
			if(ile)
				cout << q << ": " << ile << " " << (luck ? "Lucky" : "Unlucky") << endl;
		}
	}
    return 0;
}
