#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <set>
#include <algorithm>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define VI vector<int>
#define all(s) (s).begin(),(s).end()
#define L(s) (int)(s).size()
int t, n;
vector<pii> a, b;
pii mid;
inline bool cmpp(const pii&a, const pii&b) {
	double a1 = atan2(a.y, a.x);
	double a2 = atan2(b.y, b.x);
	if (abs(a1 - a2) > 1e-9) {
		return a1 < a2;
	}
	return false;
}
inline ll vec(const pii&a, const pii&b) {
	return (ll)a.x * b.y - (ll)b.x * a.y;
}
int main() {
	freopen("C-large.in" ,"r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for(int tc = 1; tc <= t; ++tc) {
		cerr << tc << endl;
		cin >> n;
		a.clear();
		for(int i = 0; i < n; ++i) {
			int x, y; cin >> x >> y;
			a.pb(mp(x, y));
		}
		cout << "Case #" << tc << ":\n";
		for(int iter = 0; iter < n; ++iter) {
			b = a;
			mid = b[iter];
			b.erase(b.begin() + iter);
			for(int j = 0; j < n - 1; ++j) {
				b[j].x -= mid.x;
				b[j].y -= mid.y;
			}
			sort(all(b), cmpp);
			for(int j = 0; j < n - 1; ++j) {
				b.pb(b[j]);
		//		cout << b[j].x << " " << b[j].y << endl;
			}
		//	cout << endl;
			int cur = n - 1;
			for(int j = 0, k = 0; j < n - 1; ++j) {
				while(k < (j + n - 1) && vec(b[k], b[j]) <= 0) ++k;
			//	cout << iter << ": " << j << " " << k << endl;
				cur = min(cur, j + n - 1 - k);
			}
			cout << cur << endl;
		}
	}
}
