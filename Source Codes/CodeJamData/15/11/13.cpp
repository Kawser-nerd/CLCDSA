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
int t, n, a[1111];
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("output.txt","w", stdout);
	cin >> t;
	for(int tc = 1; tc <= t; ++tc) {
		cin >> n;
		for(int i = 0; i < n; ++i) cin >> a[i];
		int a1 = 0;
		for(int i = 0; i < n - 1; ++i) {
			if (a[i + 1] < a[i]) a1 += a[i] - a[i + 1];
		}

		double rate = 0.;
		for(int i = 0; i < n - 1; ++i) {
			if (a[i +1] < a[i]) {
				rate = max(rate, (a[i] - a[i + 1]) / 10.);
			}
		}
	//	cerr << rate << endl;
	//	if (rate == 10) rate = 9;
		double a2 = 0;
		for(int i = 0; i < n - 1; ++i) {
			a2 += min(1. * a[i], rate * 10);
		}
		cout << "Case #" << tc << ": " << a1 << " " << (int)(a2 + 1e-9) << endl;
	}

}
