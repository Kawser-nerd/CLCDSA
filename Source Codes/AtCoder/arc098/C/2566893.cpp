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

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

const double eps = 1e-6;
const ll MOD = 1000000007;
const ll INF = 1e15;

int main() {
	ll N, K, Q;
	cin >> N >> K >> Q;
	vector<ll> A(N);
	vector<P> b(N);
	for (int i= 0;i < N;i++) {
		cin >> A[i];
		b[i] = P(A[i], i);
	}
	sort(A.begin(), A.end());
	sort(b.begin(), b.end());
	ll can = N - K + 1;
	ll ans = A[Q-1] - A[0];
	set<ll> div;
	div.insert(-1);
	div.insert(N);
	for (ll rm = 0;rm + Q < N;rm++) {
		div.insert(b[rm].second);
		bool ok = true;
		map<ll, ll> mp;
		ll cnt = 0;
		ll now = rm + 1;
		while (now < N && cnt < Q) {
			auto iter = div.lower_bound(b[now].second);
			ll right = *iter;
			iter--;
			ll left = *iter;
			ll can = max(0LL, (right - left - K));
			if (mp.find(left) == mp.end())
				mp[left] = 0;
			can = can - mp[left];
			mp[left]++;
			if (can > 0)
				cnt++;
			now++;
		}
		if (cnt == Q)
			ans = min(ans, A[now - 1] - A[rm + 1]);
	}
	cout << ans << endl;
	return 0;
}
/*
5 1 3
9 10 1 3 8
*/