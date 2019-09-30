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

bool unmalt[2000][2000];
int num[2000];
int malt[2000];
bool ismalt[2000];
bool sat[2000];

int main() {
	int ccc;
	cin >> ccc;
	REP(cc,ccc) {
		int n, m;
		cin >> n >> m;
		REP(i,m) REP(j,n)
			unmalt[i][j] = false;
		REP(i,m)
			num[i] = 0;
		REP(i,m)
			malt[i] = -1;
		REP(j,n)
			ismalt[j] = false;
		REP(i,m)
			sat[i] = false;
		REP(i,m) {
			int t;
			cin >> t;
			REP(j,t) {
				int a, b;
				cin >> a >> b;
				if (b)
					malt[i] = a-1;
				else {
					unmalt[i][a-1] = true;
					num[i]++;
				}
			}
		}
		queue<int> q;
		REP(i,m)
			if (num[i] == 0 && !ismalt[malt[i]]) {
				ismalt[malt[i]] = true;
				q.push(malt[i]);
			}
		bool poss = true;
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			REP(i,m) {
				if (malt[i] == f)
					sat[i] = true;
				if (!sat[i] && unmalt[i][f]) {
					num[i]--;
					if (num[i] == 0) {
						if (malt[i] == -1) {
							poss = false;
							goto end;
						} else {
							if (!ismalt[malt[i]]) {
								ismalt[malt[i]] = true;
								q.push(malt[i]);
							}
						}
					}
				}
			}
		}
end:
		cout << "Case #" << cc + 1 << ":";
		if (poss) {
			REP(j,n)
				cout << " " << ismalt[j];
		} else
			cout << " IMPOSSIBLE";
		cout << endl;
	}
}
