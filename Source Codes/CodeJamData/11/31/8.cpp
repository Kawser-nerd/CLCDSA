#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T a) {return a > 0 ? a : (-a); }
template<class T> T sqr(T a) {return a * a; }

using namespace std;

int n, m;
vector<string> s;

bool good(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m || s[i][j] != '#')
		return false;
	return true;
}

void solve(int testnum) {
	cout << "Case #" << testnum << ":" << endl;

	cin >> n >> m;
	s.resize(n);
	for (int i = 0; i < n; ++i) cin >> s[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == '#') {
				if (!good(i, j + 1) || !good(i + 1, j) || !good(i + 1, j + 1)) {
					cout << "Impossible" << endl;
//					cout << i << " " << j << endl;
					return;
				}
				s[i][j] = '/';
				s[i + 1][j + 1] = '/';
				s[i][j + 1] = s[i + 1][j] = '\\';
			}
	for (int i = 0; i < n; ++i) cout << s[i] << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) solve(i);
	return 0;
}
