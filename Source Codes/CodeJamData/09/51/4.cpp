#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <numeric>
using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define REPD(i, n) for (int i((n)-1); i >= 0; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int64;
typedef unsigned long long uint64;

template<typename T> int size(const T& c) { return (int)c.size(); }
template<typename T> void remin(T& a, const T& b) { if (b < a) a = b; }
template<typename T> void remax(T& a, const T& b) { if (b > a) a = b; }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }

typedef pair<int,int> pii;

int r, c, n;
bool wall[12][12];
vector<pii> pos;

bool near(const pii& p1, const pii& p2) {
	return p1.first == p2.first && abs(p1.second-p2.second) == 1
		|| p1.second == p2.second && abs(p1.first-p2.first) == 1;
}

bool isConnected(const vector<pii>& pos) {
	vector<bool> was(n, false);
	was[0] = true;
	for (;;) {
		bool changed = false;
		REP(i, n) if (was[i])
			REP(j, n) if (!was[j] && near(pos[i], pos[j])) {
				was[j] = true;
				changed = true;
			}
		if (!changed) break;
	}
	REP(i, n)
		if (!was[i])
			return false;
	return true;
}

bool isFree(int i, int j) {
	if (i < 0 || i >= r || j < 0 || j >= c || wall[i][j]) return false;
	REP(k, n)
		if (pos[k].first == i && pos[k].second == j)
			return false;
	return true;
}

const int di[] = {-1, 0, 1, 0}, dj[] = {0, -1, 0, 1};

int solve(int64 p1, int64 p2) {
	if (p1 == p2) return 0;
	map<int64,int> dist;
	dist[p1] = 0;
	queue<int64> que;
	que.push(p1);
	pos.resize(n);
	while (!que.empty()) {
		int64 s = que.front();
		int64 p = s;
		que.pop();
		REP(i, n) {
			int cell = int(s%(r*c));
			pos[i] = make_pair(cell/c, cell%c);
			s /= (r*c);
		}
		assert(s == 0);
		bool conn = isConnected(pos);
		REP(i, n) REP(dir, 2) {
			int ci = pos[i].first, cj = pos[i].second;
			if (isFree(ci+di[dir], cj+dj[dir]) && isFree(ci+di[dir+2], cj+dj[dir+2])) {
				vector<pii> npos = pos;
				npos[i] = make_pair(ci+di[dir], cj+dj[dir]);
				bool nconn = isConnected(npos);
				if (conn || nconn) {
					sort(ALL(npos));
					int64 q = 0;
					REP(j, n) {
						int cell = npos[j].first*c+npos[j].second;
						q = q*r*c+cell;
					}
					if (!dist.count(q)) {
						dist[q] = dist[p]+1;
						que.push(q);
						if (q == p2) return dist[q];
					}
				}

				npos = pos;
				npos[i] = make_pair(ci+di[dir+2], cj+dj[dir+2]);
				nconn = isConnected(npos);
				if (conn || nconn) {
					sort(ALL(npos));
					int64 q = 0;
					REP(j, n) {
						int cell = npos[j].first*c+npos[j].second;
						q = q*r*c+cell;
					}
					if (!dist.count(q)) {
						dist[q] = dist[p]+1;
						que.push(q);
						if (q == p2) return dist[q];
					}
				}
			}
		}
	}
	return dist.count(p2) ? dist[p2] : -1;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int ntests;
	scanf("%d", &ntests);
	FOR(test, 1, ntests) {
		printf("Case #%d: ", test);
		scanf("%d%d", &r, &c);
		int64 p1 = 0, p2 = 0;
		n = 0;
		int n2 = 0;
		REP(i, r) REP(j, c) {
			char ch;
			scanf(" %c", &ch);
			if (ch == '#') 
				wall[i][j] = true;
			else {
				wall[i][j] = false;
				int cell = i*c+j;
				if (ch == 'o' || ch == 'w') {
					p1 = p1*r*c+cell;
					++n;
				}
				if (ch == 'x' || ch == 'w') {
					p2 = p2*r*c+cell;
					++n2;
				}
			}
		}
		assert(n == n2);
		printf("%d\n", solve(p1, p2));
		fflush(stdout);
	}

	exit(0);
}
