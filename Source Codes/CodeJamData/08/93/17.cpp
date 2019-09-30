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

typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<string> vs; typedef long long ll;

int R, C;
int clue[100][100];
bool mine[100][100];

bool valid(int r, int c) {
	return r>=0 && c>=0 && r<R && c<C;
}
int getclue(int r, int c) {
	int t = 0;
	for (int dr = r-1; dr <= r+1; dr++) {
		for (int dc = c-1; dc <= c+1; dc++) {
			if (valid(dr, dc)) t += mine[dr][dc];
		}
	}
	return t;
}

int main() {
	int casos, res;
	cin >> casos;
	REP(caso, casos) {
		res = 0;
		cin >> R >> C;
		REP(r, R) REP(c, C) cin >> clue[r][c];
		REP(map, 1<<(R*C)) {
			REP(r, R) REP(c, C) mine[r][c] = (map & (1<<(r*C+c))) > 0;
			bool valid = true;
			REP(r, R) REP(c, C) if (getclue(r, c) != clue[r][c]) {
				valid = false;
				break;
			}
			if (valid) {
				int can = 0;
				REP(c, C) can += mine[R/2][c];
				res = max(res, can);
			}
			/*REP(r, R) {
				REP(c, C) printf("%d ", mine[r][c]);
				printf("\n");
			}
			printf("\n");*/
		}
		cout << "Case #" << caso+1 << ": " << res << endl;
	}
	return 0;
}
