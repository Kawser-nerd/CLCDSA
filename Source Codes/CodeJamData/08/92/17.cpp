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

int W, H, sx, sy;
int dx[2], dy[2];
const int INF = 0x3fffffff;

int sgn(int x) {return x>=0?1:-1;}
int abs(int x) {return x*sgn(x);}
int techo(int a, int b) {
	if (sgn(a) == sgn(b)) {
		a = abs(a); b = abs(b);
		return (a+b-1)/b;
	} else {
		a = abs(a); b = abs(b);
		return -(a/b);
	}
}
int piso(int a, int b) {
	if (sgn(a) == sgn(b)) {
		a = abs(a); b = abs(b);
		return a/b;
	} else {
		a = abs(a); b = abs(b);
		return -((a+b-1)/b);
	}
}

bool valid(int x, int y) {
	return x >= 0 && x < W &&  y >= 0 && y < H;
};

void change(int &left, int &right, int start, int delta, int lrange, int range) {
	if (delta > 0) {
		left = max(left, techo(lrange - start, delta));
		right = min(right, techo(range - start, delta) - 1);
	} else if (delta < 0) {
		left = max(left, piso(range - start, delta) + 1);
		right = min(right, piso(lrange - start, delta));
	} else if (delta == 0) {
		if (start < 0 || start >= range) {
			left = 0;
			right = -1;
		}
	}
}

pi contar(int sx, int sy, int dx, int dy, int left, int right, int mw, int w, int mh, int h) {
	change(left, right, sx, dx, mw, w);
	change(left, right, sy, dy, mh, h);
	return make_pair(left, right);
}

int main() {
	int casos;
	ll res;
	cin >> casos;
	REP(caso, casos) {
		res = 0;
		cin >> W >> H;
		REP(i,2) cin >> dx[i] >> dy[i];
		cin >> sx >> sy;
		if (dx[0]*dy[1] == dx[1]*dy[0]) {
			// simular
			set<pi> seen;
			queue<pi> q;
			int x, y;
			q.push(make_pair(sx, sy)); seen.insert(make_pair(sx,sy));
			while (!q.empty()) {
				res++;
				x = q.front().first, y = q.front().second; q.pop();
				REP(i,2) if (valid(x + dx[i], y + dy[i])) {
					if (seen.find(make_pair(x + dx[i], y + dy[i])) == seen.end()) {
						seen.insert(make_pair(x+dx[i], y+dy[i]));
						q.push(make_pair(x+dx[i], y+dy[i]));
					}
				}
			}
		} else {
			for (;;) {
				//cout << sx << " " << sy << endl;
				pi p = contar(sx, sy, dx[0], dy[0], 0, INF, 0, W, 0, H);
				if (p.first <= p.second) {
					//cout << p.second - p.first + 1 << endl;
					res += p.second - p.first + 1;
				}
				pi p2 = contar(sx, sy, dx[0], dy[0], p.first, p.second, -dx[1], W - dx[1], -dy[1], H - dy[1]);
				//printf("%d %d\n", p2.first, p2.second);
				if (p2.first > p2.second) break;
				sx += dx[1]; sy += dy[1];
			}
		}
		cout << "Case #" << caso+1 << ": " << res << endl;
	}
	return 0;
}
