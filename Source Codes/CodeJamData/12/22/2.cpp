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

#define MAXN 107
int t,n,m,h,pod[MAXN][MAXN], suf[MAXN][MAXN];
int best[MAXN][MAXN];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int time(int x, int y, int t, int a, int b){
//	cout << "try " << x << " " << y << " -> " << a << " " << b << "    " << suf[a][b] << "-" << pod[a][b] << "  " << suf[x][y] << "-" << pod[x][y] << endl;
	if(a == 0 || a == n+1 || b == 0 || b == m+1) return INF;
	if(suf[a][b] - pod[a][b] < 50) return INF;
	if(suf[a][b] - pod[x][y] < 50) return INF;
//	cout << " go " << x << " " << y << " -> " << a << " " << b << endl;
	if(suf[x][y] - pod[a][b] < 50) return INF;
	int wait = max(0, (h-t)-(suf[a][b]-50));
	if(t == 0 && wait == 0) return 0;
	return t + wait + (h-t-wait >= pod[x][y]+20 ? 10 : 100);
}

int main(){ 
	int T;
	cin >> T;
	FOR(t,1,T){
		//in
		scanf("%d%d%d",&h,&n,&m);
		FOR(i,1,n)
			FOR(j,1,m) scanf("%d",&suf[i][j]);
		FOR(i,1,n)
			FOR(j,1,m) scanf("%d",&pod[i][j]);
		//sol
		REP(i,n+2)
			REP(j,m+2)
				best[i][j] = INF;
		best[1][1] = 0;
		priority_queue<PP> Q;
		Q.push(PP(0, P(1,1)));
		while(!Q.empty()){
			PP pp = Q.top(); Q.pop();
			int x = pp.Y.X;
			int y = pp.Y.Y;
			int c = -pp.X;
			if(best[x][y] != c) continue;
//			cout << x << " " << y << " " << c << endl;
			if(x == n && y == m){
				cout << "Case #" << t << ": " << ((double)c)/10 << endl;
				break;
			}
			REP(k,4){
				int xx=x+dx[k];
				int yy=y+dy[k];
				int cc=time(x,y,c,xx,yy);
				if(cc < best[xx][yy]){
					best[xx][yy] = cc;
					Q.push(PP(-cc,P(xx,yy)));
				}
			}
		}
//		cout << "OK" << endl;
		//out
	}
    return 0;
}
