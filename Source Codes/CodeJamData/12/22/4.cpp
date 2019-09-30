#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef stringstream ss;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define clr(t,v) memset((t),(v),sizeof(t))
#define p(a) cout << #a << ": " << a << endl;

#define rep(i,n) for(int i=0,_##i=(n);i<_##i;++i)
#define dwn(i,n) for(int i=(n);--i>=0;)
#define repr(i,l,r) for(int i=(l),_##i=(r);i<_##i;++i)
#define dwnr(i,l,r) for(int i=(r),_##i=(l);--i>=_##i;)
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(),_##i=(a).end();i!=_##i;++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(),_##i=(a).rend();i!=_##i;++i)

int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, -1, 0, 1};

int n, m;
int inith;
int floorh[110][110];
int ceilh[110][110];

int getlev(int i, int j, int t) {
	return max(floorh[i][j], inith - t);
}

bool within(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

bool canmove(int i, int j, int k, int t) {
	int ni = i + mx[k];
	int nj = j + my[k];
	if (!within(ni, nj)) return false;
	int minceil = min(ceilh[i][j], ceilh[ni][nj]);
	int maxfloor = max(getlev(i, j, t), getlev(ni, nj, t));
	return minceil >= maxfloor + 50;
}

int dist[110][110];

typedef pair<int, pii> state;

int main() { freopen("b.in","r",stdin); freopen("b.out","w",stdout);
	cout << fixed << setprecision(12);
	
	int testn;
	cin >> testn;
	for (int testc = 1; testc <= testn; ++testc) {
		cout << "Case #" << testc << ": ";
		
		cin >> inith >> n >> m;
		rep (i, n) {
			rep (j, m) {
				cin >> ceilh[i][j];
			}
		}
		rep (i, n) {
			rep (j, m) {
				cin >> floorh[i][j];
			}
		}
		priority_queue<state> pq;
		clr(dist, 31);
		
		pq.push(state(0, pii(0, 0)));
		dist[0][0] = 0;
		
		while (pq.size()) {
			state curstate = pq.top();
			pq.pop();
			
			int t = -curstate.fi;
			pii pos = curstate.se;
			int i = pos.fi;
			int j = pos.se;
			if (t != dist[i][j]) continue;
			if (i == n - 1 && j == m - 1) {
				cout << t / 10 << '.' << t % 10;
				break;
			}
			for (int k = 0; k < 4; k++) {
				int nx = i + mx[k];
				int ny = j + my[k];
				if (t == 0 && canmove(i, j, k, 0)) {
					if (dist[nx][ny] > 0) {
						pq.push(state(0, pii(nx, ny)));
						dist[nx][ny] = 0;
					}
				} else {
					int lo = t, hi = 10010, mid;
					while (lo + 1 < hi) {
						mid = (lo + hi - 1) / 2;
						if (canmove(i, j, k, mid)) {
							hi = mid + 1;
						} else {
							lo = mid + 1;
						}
					}
					if (canmove(i, j, k, lo)) {
						int nxtt = lo;
						if (getlev(i, j, lo) >= floorh[i][j] + 20) {
							nxtt += 10;
						} else {
							nxtt += 100;
						}
						if (dist[nx][ny] > nxtt) {
							pq.push(state(-nxtt, pii(nx, ny)));
							dist[nx][ny] = nxtt;
						}
					}
				}
			}
		}
		
		cout << '\n';
	}
}
