#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FOREACH(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define SZ(x) ((int)(x).size())
#define test(a,b) (((a)&(1<<(b)))?1:0)

typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<string> vs; typedef long long ll;

int M, N;
string board[100];
int best[16][16][1<<16];

int main() {
	int casos, res;
	cin >> casos;
	REP(caso, casos) {
		cin >> M >> N;
		REP(m, M) cin >> board[m];
		CLEAR(best, 0x80);
		REP(b, 1<<N) {
			if (test(b, 0)) {
				if (board[0][0] != '.') best[0][0][b] = 4;
			} else {
				best[0][0][b] = 0;
			}
		}
		REP(m, M) REP(n, N) {
			if (!m && !n) continue;
			int prevn = n-1, prevm = m;
			if (prevn < 0) prevn = N-1, prevm = m-1;
			REP(prevb, 1<<N) {
				if (board[m][n] != '#') {
					best[m][n][prevb & ~(1<<n)] = max(best[m][n][prevb & ~(1<<n)], best[prevm][prevn][prevb]);
				}
				if (board[m][n] != '.') {
					best[m][n][prevb | (1<<n)] = max(best[m][n][prevb | (1<<n)], best[prevm][prevn][prevb] + 4 - 2*test(prevb, n) - 2*(n>0?test(prevb, n-1):0));
				}
			}
			//REP(b, 1<<N) printf("%d %d %d %d\n", m, n, b, best[m][n][b]);
		}
		res = 0;
		REP(b, 1<<N) res = max(res, best[M-1][N-1][b]);
		cout << "Case #" << caso+1 << ": " << res << endl;
	}
	return 0;
}
