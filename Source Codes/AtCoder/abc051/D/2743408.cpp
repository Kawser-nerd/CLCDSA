#include <iostream>
#include <vector>
#include <utility>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <queue>

#define rep(i, m, n) for (int(i)(m); (i) < (n); ++(i))
#define repv(i, v) for (int(i)(0); (i) < (v.size()); ++(i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vb>;

class P {
  public:
	int i;
	int l;
	P(int a, int b)
		: i(a), l(b){};
};

bool operator>(const P &pl, const P &pr) {
	return pl.l > pr.l;
}

int main() {
	int N, M;
	cin >> N >> M;
	vvi T;
	rep(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		vi v = {a, b, c};
		T.push_back(v);
	}
	vvi minT(N + 1, vi(N + 1, 1000));
	rep(i, 1, N + 1) {
		priority_queue<P, vector<P>, greater<P> > q;
		q.push(P(i, 0));
		while (!q.empty()) {
			P p = q.top();
			q.pop();
			repv(j, T) {
				if (p.i == T[j][0] || p.i == T[j][1]) {
					int ni(T[j][p.i == T[j][0] ? 1 : 0]);
					int nl(p.l + T[j][2]);
					if (minT[i][ni] > nl) {
						minT[i][ni] = nl;
						q.push(P(ni, nl));
					}
				}
			}
		}
	}
	int sum(0);
	repv(i, T) {
		if (minT[T[i][0]][T[i][1]] < T[i][2]) {
			++sum;
		}
	}
	cout << sum << endl;
	return 0;
}