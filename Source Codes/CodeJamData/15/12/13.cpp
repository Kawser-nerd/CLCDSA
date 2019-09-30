#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
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
#define inf 1000000000
int t, n;
int b, m[1111];
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for(int tc = 1; tc <= t; ++tc) {
		cin >> b >> n;
		for(int i = 0; i < b; ++i) cin >> m[i];
		ll low = -1, high = (ll)1000000 * inf;
		while(high - low > 1) {
			ll mid = (high + low) / 2, tot = 0;
			for(int i = 0; i < b; ++i) {
				tot += mid / m[i] + 1;
			}
			if (tot >= n) {
				high = mid;
			} else {
				low = mid;
			}
		}

		for(int i = 0; i < b; ++i) {
			int add = high / m[i] + 1;
			if (high % m[i] == 0) --add;
			n -= add;
		}
		int ans = -1;
		for(int i = 0; i < b; ++i) {
			if (high % m[i] == 0) {
				--n;
				if (!n) {
					ans = i;
					break;
				}
			}
		}
		cout << "Case #" << tc << ": " << ans + 1 << endl;
	}
}
