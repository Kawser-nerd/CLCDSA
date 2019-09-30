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
#define two(x) (1<<(x))

typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<string> vs; typedef long long ll;

int R, C;
int startr, startc;

bool empty(int b, int r, int c) {
	//printf("%d %d %d %d %d %d\n", r, R, c, C, b, two(4*r+c));
	return r>=0 && r<R && c>=0 && c<C && !(b & two(4*r+c));
}

char memo[100000][5][5];
bool canwin(int b, int r, int c) {
	char &res = memo[b][r][c];
	if (res == -1) {
		res = false;
		for (int nextr = r-1; nextr <= r+1; nextr++) {
			for (int nextc = c-1; nextc <= c+1; nextc++) {
				if ((nextr != r || nextc != c) && empty(b, nextr, nextc)) {
					if (!canwin(b | two(4*r+c), nextr, nextc)) {
						return (res = true);
					}
				}
			}
		}
	}
	return res;
}
	
int main() {
	string s;
	int casos;
	int board;
	cin >> casos;
	REP(caso, casos) {
		cin >> R >> C;
		board = 0;
		REP(r, R) {
			cin >> s;
			REP(c, C) {
				if (s[c] == '#') {
					board |= two(4*r+c);
				} else if (s[c] == 'K') {
					startr = r; startc = c;
				}
			}
		}
		CLEAR(memo, -1);
		cout << "Case #" << caso+1 << ": " << (canwin(board, startr, startc)?"A":"B") << endl;
	}
	return 0;
}
