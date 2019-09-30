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
#define REP(i,n) for(lli i=0;i<(n);i++)
#define FOR(i,a,b) for(lli i=(a);i<=(b);i++)
#define FORD(i,a,b) for(lli i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,w) memset((x),w,sizeof (x))
#define X first
#define Y second
#define INF 1000000000
typedef long long int lli;
typedef pair<lli, lli> P;
typedef pair<lli, P> PP;
typedef vector<lli> VI;

#define MAXN 2007
lli N, best[MAXN], res[MAXN];

bool go(lli l, lli r, lli h){
	if(r <= l) return true;
//	cout << l << " - " << r << " h " << h << endl;
	lli spad = (res[r] - h + (r - l)) / (r - l);
	while(l != r){
		lli x = best[l];
		if(x <= l || x > r)
			return false;
		res[l] = res[r] - spad * (r-l);
		res[x] = res[r] - spad * (r-x);
		if(!go(l+1, x, res[l] - 1))
			return false;
		l = x;
	}
	return true;
}

int main(){ 
	lli T;
	cin >> T;
	FOR(t,1,T){
		//in
		cin >> N;
		FOR(i,1,N-1)
			cin >> best[i];
		//sol
		CLR(res, 0);
		res[N] = INF;
		bool ok = go(1,N,INF-1);
		//res
		cout << "Case #" << t << ": ";
		if(ok)
			FOR(i,1,N) cout << res[i] << " ";
		else
			cout << "Impossible";
		cout << endl;
	}
    return 0;
}
