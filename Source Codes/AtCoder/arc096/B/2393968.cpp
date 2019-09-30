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
typedef tuple<ll, ll, ll> T;

const double eps = 1e-6;
const ll MOD = 1000000007;
const ll INF = 1e15;

int main() {
	ll N, C;
	cin >> N >> C;
	vector<ll> x(N + 1);
	vector<ll> v(N + 1);
	vector<ll> imos(N + 3);
	x[0] = 0;
	v[0] = 0;
	for (int i = 1;i <= N;i++) {
		cin >> x[i] >> v[i];
	}
	x.push_back(C);
	v.push_back(0);
	for (int i = 1;i <= N + 2;i++)
		imos[i] += imos[i - 1] + v[i - 1];
	vector<ll> migi(1, 0);
	ll point = 0;
	for (int i = 1;i <= N + 1;i++) {
		if (imos[i + 1] - x[i] > point) {
			point = imos[i + 1] - x[i];
			migi.push_back(i);
		}
	}

	vector<ll> hidariv(1, N + 1);
	point = 0;
	for (int i = N;i >= 0;i--) {
		if (imos[N + 2] - imos[i] - (C - x[i]) > point) {
			point = imos[N + 1] - imos[i] - (C - x[i]);
			hidariv.push_back(i);
		}
	}
	ll ans = 0;
	for (int hidari = N;hidari >= 1;hidari--) {
		ans = max(ans, imos[N + 2] - imos[hidari] - (C - x[hidari]));
		while (migi.back() >= hidari)
			migi.pop_back();
		ans = max(ans, imos[N + 2] - imos[hidari] - (C - x[hidari]) * 2 + imos[migi.back() + 1] - x[migi.back()]);
	}
	for (int r = 0;r <= N;r++) {
		ans = max(ans, imos[r + 1] - x[r]);
		while (hidariv.back() <= r)
			hidariv.pop_back();
		ans = max(ans, imos[N + 2] - imos[hidariv.back()] - (C - x[hidariv.back()]) + imos[r + 1] - x[r] * 2);
	}

	cout << ans << endl;
	/*for (int i = 0;i <= N+1;i++) {
	ans = max(ans, imos[i + 1] - x[i]); // ???
	if (i <= migi && i < hidari)
	ans = max(ans, imos[i + 1] - x[i] * 2 + imos[N + 2] - imos[hidari] - (C - x[hidari]));
	ans = max(ans, imos[N + 1] - imos[i] - (C - x[i])); // ???
	if(i > migi && i >= hidari)
	ans = max(ans, imos[migi + 1] - x[migi] + imos[N + 2] - imos[i] - (C - x[i]) * 2);
	}
	ll bigdiff = 0;
	for (int i = 1;i < x.size();i++)
	bigdiff = max(bigdiff, x[i] - x[i - 1]);
	ans = max(ans, imos.back() + bigdiff);
	cout << ans << endl;*/
	return 0;
}