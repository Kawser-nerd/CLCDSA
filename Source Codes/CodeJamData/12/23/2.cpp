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
typedef long long int lli;
typedef pair<int, int> P;
typedef vector<int> VI;
#define MAXN 507

lli N, a[MAXN];


void out(VI v){
	FORE(i,v) cout << a[*i] << " ";
	cout << endl;
}

VI gen(){
	VI res;
	REP(k,40){
		res.PB(rand()%N);
	}
	sort(ALL(res));
	res.erase(unique(ALL(res)), res.end());
	return res;
}

int main(){ 
	int T;
	cin >> T;
	FOR(t,1,T){
		//in
		cin >> N;
		REP(i,N) cin >> a[i];
		//sol
		map<lli, VI> M;
		while(1){
			VI v = gen();
			lli s=0;
			FORE(i,v) s += a[*i];
			if(M.count(s) && M[s] != v){
				cout << "Case #" << t << ":" << endl;
				out(M[s]);
				out(v);
				break;
			}
			M[s]=v;
		}
		//out
	}
    return 0;
}
