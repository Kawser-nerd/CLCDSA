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

#define MAXN 10007
int N,d[MAXN],l[MAXN],D,best[MAXN];

int main(){ 
	int T;
	cin >> T;
	FOR(t,1,T){
		//in
		scanf("%d",&N);
		FOR(i,1,N) scanf("%d%d",&d[i],&l[i]);
		scanf("%d", &d[N+1]);
		//sol
		CLR(best,0);
		best[1] = d[1];
		priority_queue<P> Q;
		Q.push(P(best[1], 1));
		bool res = false;
		while(!Q.empty() && !res){
			P p = Q.top(); Q.pop();
			if(best[p.Y] != p.X) continue;
			int poz = p.Y, lin = p.X;
//			cout << poz << " " << lin << endl;
			int i = poz;
			while(i>1 && d[poz] - d[i - 1] <= lin) i--;
			while(i <= N+1 && abs(d[poz] - d[i]) <= lin) {
				if(i == N+1){
					res = true;
					break;
				}
				int dlug = min(l[i], abs(d[poz] - d[i]));
				if(dlug > best[i]){
					best[i] = dlug;
					Q.push(P(dlug, i));
				}
				i++;
			}
		}
		//res
		cout << "Case #" << t << ": " << (res ? "YES" : "NO" ) << endl;
	}
    return 0;
}
