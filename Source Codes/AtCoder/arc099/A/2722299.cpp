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
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

const double eps = 1e-6;
const ll MOD = 1000000007;
const ll INF = 1e15;

int main() {
	ll N, K;
	cin >> N >> K;
	vector<ll> A(N);
	for (int i = 0;i < N;i++)
		cin >> A[i];
	ll mini = INF;
	for (int i = 0;i < N;i++)
		mini = min(mini, A[i]);
	vector<ll> v(1, -1);
	for (int i = 0;i < N;i++)
		if (A[i] == mini)
			v.push_back(i);
	v.push_back(N);
	ll ans = 0;
	ll ok = -1;
	for (int i = 0;i < v.size() - 1;i++) {
		if (v[i + 1] - 1 <= ok)
			continue;
		v[i] = max(v[i], ok);
		ll length = v[i + 1] - v[i] - 1;
		if (length <= 0)
			continue;
		ll now = (length + K - 2) / (K - 1);
		ans += now;
		ok = v[i] + now * (K - 1) + 1;
	}

	cout << ans << endl;
	return 0;
}