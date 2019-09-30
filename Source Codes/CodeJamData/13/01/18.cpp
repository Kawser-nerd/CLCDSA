#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cassert>
#include <cstring>
#include <ext/numeric>
using namespace std ;
using namespace __gnu_cxx ;
typedef long long LL ;
const int INF = 1000*1000*1000 ;
const LL INFLL = (LL)INF * (LL)INF ;
#define REP(i,n) for(i=0;i<(n);++i)
#define ALL(c) c.begin(),c.end()
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define CLEAR(t) memset(t,0,sizeof(t))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

char t[4][4] ;

inline bool ok(int i, int j, char x) {
	return t[i][j] == 'T' || t[i][j] == x ;
}

int f() {
	int i, j ;
	char player[2] = {'O', 'X'} ;
	for(int pl=0 ; pl<2 ; pl++) {
		REP(i,4) {
			REP(j,4)
				if(!ok(i,j,player[pl])) break ;
			if(j==4) return pl ;
		}
		REP(j,4) {
			REP(i,4)
				if(!ok(i,j,player[pl])) break ;
			if(i==4) return pl ;
		}
		REP(i,4)
			if(!ok(i,i,player[pl])) break ;
		if(i==4) return pl ;
		REP(i,4)
			if(!ok(i,3-i,player[pl])) break ;
		if(i==4) return pl ;
	}
	REP(i,4)
		REP(j,4)
			if(t[i][j] == '.') return 3 ;
	return 2 ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	int C ;
	cin >> C ;
	for(int tests=1 ; tests<=C ; tests++) {
		cout << "Case #" << tests << ": " ;
		int i, j ;
		REP(i,4)
			REP(j,4) cin >> t[i][j] ;
		int ret = f() ;
		if(ret == 0) cout << "O won" << endl ;
		else if(ret == 1) cout << "X won" << endl ;
		else if(ret == 2) cout << "Draw" << endl ;
		else cout << "Game has not completed" << endl ;
	}
}

