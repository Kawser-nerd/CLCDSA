#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	ll n, c;
	cin >> n >> c;
	vector<ll> pos(n);
	vector<ll> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> pos[i] >> v[i];
	}
	vector<ll> bst(n + 1);
	{
		ll cal = 0;
		for (int i = 1; i <= n; ++i) {
			cal += v[i - 1];
			bst[i] = max(bst[i - 1], cal - pos[i - 1]);
		}
	}
	ll ans = bst[n];
	ll cal = 0;
	for (int i = n - 1; i >= 0; --i) {
		cal += v[i];
		ll cur = cal - (c - pos[i]) + max(0ll, bst[i] - (c - pos[i]));
		ans = max(cur, ans);
	}
	reverse(pos.begin(), pos.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < n; ++i) {
		pos[i] = c - pos[i];
	}
	{
		ll cal = 0;
		for (int i = 1; i <= n; ++i) {
			cal += v[i - 1];
			bst[i] = max(bst[i - 1], cal - pos[i - 1]);
		}
	}
	cal = 0;
	for (int i = n - 1; i >= 0; --i) {
		cal += v[i];
		ll cur = cal - (c - pos[i]) + max(0ll, bst[i] - (c - pos[i]));
		ans = max(cur, ans);
	}
	cout << ans << endl;
}