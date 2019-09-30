#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define int long long
#define MOD7 1000000007
#define MOD9 1000000009

#define rep(i, n) for (int i = 0; i < (n); i++)
#define itrep(i, a) for (auto i = (a).begin(); i != (a).end(); i++)
#define REP(i, a, n) for (int i = (a); i <= (n); i++)
#define all(a) (a).begin(), (a).end()
#define mp(a, b) make_pair((a), (b))

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

template<class T> void inputVector(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}

const double EPS = 1e-8;
double memo[210][210];

signed main() {
	rep(i, 200) rep(j, 200) memo[i][j] = 0;

	int N;
	cin >> N;

	map<string, int> m;
	map<int, string> rm;
	rep(i, N) {
		string A, B;
		int n;
		cin >> A >> n >> B;

		if (m.count(A) == 0) {
			rm[m.size()] = A;
			m[A] = m.size();
		}
		if (m.count(B) == 0) {
			rm[m.size()] = B;
			m[B] = m.size();
		}

		memo[m[A]][m[B]] = n;
	}

	rep(i, 20) {
		bool modify = false;

		rep(k, m.size()) rep(i, m.size()) rep(j, m.size()) {
			if (memo[i][k] >= EPS && memo[k][j] >= EPS && memo[i][j] <= EPS) {
				memo[i][j] = memo[i][k] * memo[k][j];
				modify = true;
			}
			if (memo[i][k] >= EPS && memo[j][k] >= EPS && memo[i][j] <= EPS) {
				memo[i][j] = (double) memo[i][k] / memo[j][k];
				modify = true;
			}
		}

		if (!modify) break;
	}

	int ret = 0;
	string big, small;
	rep(i, m.size()) {
		rep(j, m.size()) {
			if (ret < memo[i][j]) {
				ret = memo[i][j] + 0.01;
				big = rm[i];
				small = rm[j];
			}
		}
	}

	cout << 1 << big << "=" << ret << small << endl;

    return 0;
}