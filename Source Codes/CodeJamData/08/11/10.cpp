#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
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

int main() {
	int ccc;
	cin >> ccc;
	REP(cc,ccc) {
		int n;
		cin >> n;
		VI v1(n), v2(n);
		REP(i,n)
			cin >> v1[i];
		REP(i,n)
			cin >> v2[i];
		sort(ALL(v1));
		sort(ALL(v2));
		reverse(ALL(v2));
		LL res = 0;
		REP(i,n)
			res += LL(v1[i]) * LL(v2[i]);
		cout << "Case #" << cc + 1 << ": " << res << endl;
	}
}
