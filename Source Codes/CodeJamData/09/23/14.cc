using namespace std;
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>
#include <numeric>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef istringstream ISS;

#define PB push_back
#define ALL(x) ((x).begin()),((x).end())
#define FOR(i,c) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(int i=0; i<(n); ++i)

const int infty = 999999999;

#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

const int dx[8] = { 0, 1, 0,-1, 1, 1,-1,-1};
const int dy[8] = {-1, 0, 1, 0,-1, 1, 1,-1};

VS square;
int W, Q;

const int maxn = 350;

struct pos {
	int x, y, n;

	pos() {};
	pos(int _x, int _y, int _n): x(_x), y(_y), n(_n) {};
};

struct val {
	string expr;

	val() {};
	val(string _expr): expr(_expr) {};
};

int operator <(pos a, pos b)
{
	if ( a.n!=b.n ) return a.n<b.n;
	if ( a.x!=b.x ) return a.x<b.x;
	return a.y<b.y;
}

int operator <(val a, val b)
{
	if ( a.expr.length()!=b.expr.length() ) return a.expr.length()<b.expr.length();
	return a.expr<b.expr;
}

map<pos,val> best;

int main()
{
	int nruns;

	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		cin >> W >> Q;
		square = VS(W);
		REP(i,W) cin >> square[i];

// 		debug("W = %d, Q = %d\n",W,Q);
// 		REP(i,square.size()) debug("%s\n",square[i].c_str());

		best.clear();
		queue<pos> que;
		REP(y,W) REP(x,W) if ( isdigit(square[y][x]) ) {
			pos p(x,y,square[y][x]-'0');
			best[p] = val(string(1,square[y][x]));
			que.push(p);
		}

		while ( !que.empty() ) {
			pos p = que.front(); que.pop();

			REP(d1,4) {
				int x1 = p.x + dx[d1];
				int y1 = p.y + dy[d1];
				if ( x1<0 || x1>=W ||
				     y1<0 || y1>=W ) continue;

				REP(d,4) {
					int x = x1 + dx[d];
					int y = y1 + dy[d];
					if ( x<0 || x>=W ||
					     y<0 || y>=W ) continue;

					int dig = square[y][x]-'0';
					if ( square[y1][x1]=='-' ) dig *= -1;

					pos q(x,y,p.n + dig);
					if ( abs(q.n)>maxn ) continue;

					val v(best[p].expr+square[y1][x1]+square[y][x]);
					if ( best.count(q)==0 || v<best[q] ) {
						best[q] = v;
						que.push(q);
					}
				}
			}
		}

		printf("Case #%d:\n",run);

		REP(i,Q) {
			int n;

			cin >> n;

			val res(string(999,'z'));
			REP(y,W) REP(x,W) {
				pos p(x,y,n);
				if ( best.count(p) && best[p]<res ) res = best[p];
			}

			cout << res.expr << endl;
		}
	}

	return 0;
}
