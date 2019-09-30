#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pul pair<ull, ull>
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);--i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)

void YES() { cout << "YES" << endl; }
void NO() { cout << "NO" << endl; }
void Yes() { cout << "Yes" << endl; }
void No() { cout << "No" << endl; }
void yes() { cout << "yes" << endl; }
void no() { cout << "no" << endl; }
void Taka() { cout << "Takahashi" << endl; }
void Aoki() { cout << "Aoki" << endl; }
void digit(int d) { cout << fixed << setprecision(d); }
void IOup() { cin.tie(0); ios::sync_with_stdio(false); }

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	
	double mx = 0;
	int ans1 = 100 * a, ans2 = 0;
	for (int i = 0; i <= 30; i += a) {
		for (int j = 0; j <= 30; j += b) {
			for (int k = 0; k <= 3000; k += c) {
				for (int l = 0; l <= 3000; l += d) {
					int w = 100 * (i + j);
					int s = k + l;
					if (w + s > f || s > w * e / 100.0 || w + s == 0)
						continue;
					double noud = s * 100.0 / (w + s);
					if (mx < noud) {
						mx = noud;
						ans1 = w + s;
						ans2 = s;
					}
				}
			}
		}
	}

	cout << ans1 << " " << ans2 << endl;

	return 0;
}