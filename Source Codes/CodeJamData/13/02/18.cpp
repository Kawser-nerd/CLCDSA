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

const int MAXN = 110 ;
int t[MAXN][MAXN] ;
int maxRow[MAXN] ;
int maxColumn[MAXN] ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	int C ;
	cin >> C ;
	for(int tests=1 ; tests<=C ; tests++) {
		cout << "Case #" << tests << ": " ;
		int n, m, i, j ;
		cin >> n >> m ;
		CLEAR(maxRow) ;
		CLEAR(maxColumn) ;
		REP(i,n)
			REP(j,m) {
				cin >> t[i][j] ;
				maxRow[i] = max(maxRow[i], t[i][j]) ;
				maxColumn[j] = max(maxColumn[j], t[i][j]) ;
			}
		bool ok = true ;
		REP(i,n)
			REP(j,m)
				ok = ok && (maxColumn[j] <= t[i][j] || maxRow[i] <= t[i][j]) ;
		if(ok) cout << "YES" << endl ;
		else cout << "NO" << endl ;
	}
}

