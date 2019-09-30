#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)      (a).begin(),(a).end()
#define sz(a)       int((a).size())
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define REP(i,n)    FOR(i,0,n)
#define UN(v)       sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)     memset(a,b,sizeof a)
#define pb          push_back
#define X           first
#define Y           second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> point;

int a[128][128], n;

inline bool eq(int x, int y) { return y < 0 || x == y; }

void Solve(){
	cin >> n;
	int k = 0;
	CL(a, -1);
	REP (i, n) {
		++k;
		REP (j, k) cin >> a[i + 1][64 - i + j * 2];
	}
	REP (i, n - 1) {
		--k;
		REP (j, k) cin >> a[i + n + 1][66 - (n - i) + j * 2];
	}
	int res = -1u/4;
	FOR (i, 1, 127) 
		FOR (j, 1, 127)
			try {
				int m = 0;
				REP (x, 128) REP (y, 128) 
					if (~a[x][y]) {
						int X = 2 * i - x, Y = 2 * j - y, v = a[x][y];
						if (X >= 0 && X < 128) {
							if (Y >= 0 && Y < 128 && a[X][Y] >= 0 && a[X][Y] != a[x][y]) throw 0;
							if (a[X][y] >= 0 && a[X][y] != a[x][y]) throw 0;
						} 
						if (Y >= 0 && Y < 128 && a[x][Y] >= 0 && a[x][Y] != a[x][y]) throw 0;
						m >?= abs(i - x) + abs(j - y);
					}
				res <?= m + 1;
			} catch (int x) { }
	cout << res * res - n * n << endl;
}

int main(){
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	int a = 0, b;
	for(cin >> b; a++ < b ; Solve()) printf("Case #%d: ", a);
	return 0;
}
