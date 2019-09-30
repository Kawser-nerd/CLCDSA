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
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

#define ll long long
#define ull unsigned long long
#define P pair<int, int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pul pair<ull, ull>
#define all(a) (a).begin(), (a).end()
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
void digit(int d) { cout << fixed << setprecision(d); }
void ioup() { cin.tie(0); ios::sync_with_stdio(false); }

int n, a[100001];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i + 1 == a[i]) {
			if (i < n - 1 && i + 2 == a[i + 1])
				swap(a[i], a[i + 1]);
			else if (i > 0 && i == a[i - 1])
				swap(a[i], a[i - 1]);
			else if (i > 0)
				swap(a[i], a[i - 1]);
			else if (i < n - 1)
				swap(a[i], a[i + 1]);
				
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}