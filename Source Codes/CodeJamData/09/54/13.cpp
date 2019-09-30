#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <iomanip>
using namespace std;
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define FORD(i,a,b) for (int i=(a); i>=(b); --i)
#define FORE(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define debug(x) cerr << #x << " = " << x << "\n";
#define debugv(x) cerr << #x << " = "; FORE(it,(x)) cerr<< *it <<","; cerr<<"\n";
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset(x,0,sizeof x)
#define xx first
#define yy second
typedef long long int lli;
typedef pair<int, int> P;
typedef vector<int> vi;
#define MAXN 17
#define INF 100000007
#define MOD 1000000007
template <class Ty, class Tx>
Ty cast(const Tx &x) {
	 Ty y; stringstream ss(""); ss<<x; ss.seekg(0); ss>>y; return y;
}


int T;
lli L,R;
set<lli> pal;

int main(){
	REP(i,10000000) if(i){
		string s=cast<string>(i);
		string odw=s;
		reverse(ALL(odw));
		pal.insert(cast<lli>(s+odw.substr(1,string::npos)));
		if(s.size()<=6) pal.insert(cast<lli>(s+odw));
	}
	cin >> T;
	FOR(cas,1,T){
		//im
		cin >> L >> R;
		lli res[2];
		L--;
		R++;
		lli bit=0,pop=L;
		CLR(res);
		set<lli>::iterator i=pal.lower_bound(L+1);
		while(i != pal.end() && *i <= R-1){
			res[bit]+=*i-pop;
			bit=1-bit;
			pop=*i;
			i++;
		}
		res[bit]+=R-pop;
		res[0]%=MOD;
		res[1]%=MOD;
		lli odp=0LL;
		//cout << res[0] << " " << res[1] << endl;
		odp+=res[0]*(res[0]-1LL)/2LL;
		odp%=MOD;
		odp+=res[1]*(res[1]-1LL)/2LL;
		odp%=MOD;
		///out
		cout << "Case #" << cas << ": " << odp%MOD << endl;
	}
	return 0;
}
