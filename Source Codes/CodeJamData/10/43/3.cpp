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

pii p[1111111], q[1111111];
int n, s[1111111], d[1111111];

int S(int x) { return s[x] == x ? x : s[x] = S(s[x]); }

int F(int x, int y) {
	int i = lower_bound(p, p + n, pii(x, y)) - p;
	return i != n  && p[i].X == x && p[i].Y == y ? i : -1;
}

void unite(int x, int y) {
	x = S(x), y = S(y);
	s[x] = y;
	q[y].X >?= q[x].X;
	q[y].Y >?= q[x].Y;
}

void Solve(){
	n = 0;
	int R;
	cin >> R;
	REP (i, R) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x <= x2; ++x)
			for (int y = y1; y <= y2; ++y)
				p[n++] = pii(x, y);
	}
	sort(p, p + n), n = unique(p, p + n) - p;
	REP (i, n) s[i] = i, q[i] = p[i], d[i] = 1;
	REP (i, n) {
		int j = F(p[i].X - 1, p[i].Y);
		if (~j) {
			unite(i, j);
			d[i] = max(d[i], d[j] + 1);
		}
		j = F(p[i].X, p[i].Y - 1);
		if (~j) {
			unite(i, j);
			d[i] = max(d[i], d[j] + 1);
		}
		j = F(p[i].X - 1, p[i].Y + 1);
		if (~j) unite(i, j);
	}
	int res = 0;
	REP (i, n) {
		int j = S(i);
		res >?= d[i] + (q[j].X - p[i].X) + (q[j].Y - p[i].Y);
	}
	cout << res << endl;
}

int main(){
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	int a = 0, b;
	for(cin >> b; a++ < b ; Solve()) printf("Case #%d: ", a);
	return 0;
}
