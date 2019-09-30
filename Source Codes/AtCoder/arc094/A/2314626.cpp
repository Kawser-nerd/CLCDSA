#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1e15;
const double eps = 1e-6;
const ll MOD = 1000000007;

int cal(int base, int x) {
	if (base < x)
		return (x - base);
	int sa = abs(base - x);
	return (sa+1) / 2 + sa % 2;
}

int main() {
	ll A, B, C;
	cin >> A >> B >> C;
	ll ans = INF;
	for (int i = 0;i <= 50;i++) {
		ans = min(ans, (ll)cal(i, A) + cal(i, B) + cal(i, C));
	}
	cout << ans << endl;
	return 0;
}