#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define REP(i,n) FOR(i,0,n)
#define REPD(i,n) FORD(i,0,n)
#define VAR(v,w) __typeof(w) v=(w)
#define FORE(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define PB push_back
#define ALL(c) (c).begin(),(c).end()
#define SIZE(c) ((int)(c).size())
#define MP make_pair
#define FT first
#define SD second
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<double> VD;
typedef vector<LD> VLD;
typedef vector<LL> VLL;
typedef vector<bool> VB;
typedef istringstream ISS;
typedef ostringstream OSS;

int n;
string col[10];
int start[10], end[10];

inline int ONES(int x) {
	x = (0x55555555&x)+(0x55555555&(x>>1));
	x = (0x33333333&x)+(0x33333333&(x>>2));
	x = (0x0f0f0f0f&x)+(0x0f0f0f0f&(x>>4));
	x = (0x00ff00ff&x)+(0x00ff00ff&(x>>8));
	x = (0x0000ffff&x)+(0x0000ffff&(x>>16));
	return x;
}

int main() {
	int ccc;
	cin >> ccc;
	REP(cc,ccc) {
		cin >> n;
		REP(i,n) {
			cin >> col[i] >> start[i] >> end[i];
		}
		int nn = 1 << n;
		int res = 1000000000;
		REP(m,nn) {
			bool fence[10000];
			REP(i,10000)
				fence[i] = 0;
			int cols = 0;
			REP(i,n) if (m&(1<<i)) {
				bool been = 0;
				REP(j,i) if (m&(1<<j))
					if (col[i] == col[j])
						been = 1;
				if (!been)
					cols++;
			}
			if (cols > 3)
				continue;
			REP(i,n) if (m&(1<<i))
				FOR(k,start[i]-1,end[i])
					fence[k] = 1;
			bool blank = 0;
			REP(i,10000)
				if (!fence[i])
					blank = 1;
			if (!blank)
				res = min(res,ONES(m));
		}
		if (res == 1000000000)
			cout << "Case #" << cc+1 << ": IMPOSSIBLE" << endl;
		else
			cout << "Case #" << cc+1 << ": " << res << endl;
	}
}
