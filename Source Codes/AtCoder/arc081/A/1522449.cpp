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

#define ll long long
#define ull unsigned long long
#define INF (1 << 29)
#define LLINF (1LL << 61)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10
#define P pair<int, int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pul pair<ull, ull>
#define all(a) (a).begin(), (a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);--i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)
#define TO_STRING(VariableName) # VariableName

void YES() { cout << "YES" << endl; }
void NO() { cout << "NO" << endl; }
void Yes() { cout << "Yes" << endl; }
void No() { cout << "No" << endl; }
void yes() { cout << "yes" << endl; }
void no() { cout << "no" << endl; }

map<ll, int> mp;

int main() {
	int n, a;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		mp[a]++;
	}

	ll m1 = 0, m2 = 0;
	for (auto x : mp) {
		if (x.second > 1) {
			m1 = max(m1, x.first);
		}
	}
	for (auto x : mp) {
		if (x.second > 3) {
			m2 = max(m2, x.first);
		}
		else if (x.second > 1 && m1 != x.first) {
			m2 = max(m2, x.first);
		}
	}

	cout << m1 * m2 << endl;

	return 0;
}