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

void solve() {
	int n, l, h;
	cin >> n >> l >> h;
	vector<int> c(n);
	for (int i = 0; i < n; ++i) cin >> c[i];
	for (int ans = l; ans <= h; ++ans) {
		bool good = true;
		for (int i = 0; i < n; ++i) {
			if (ans % c[i] != 0 && c[i] % ans != 0) {
				good = false;
				break;
			}
		}
		if (good) {
			cout << ans << endl;
			return;
		}
	}
	cout << "NO" << endl;
}             

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)  {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
