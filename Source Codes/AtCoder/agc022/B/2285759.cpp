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

int main() {
	ll N;
	cin >> N;
	if (N == 3) {
		cout << "2 5 63" << endl;
		return 0;
	}
	vector<ll> ans{2, 4, 3, 9};
	N -= 4;
	for (ll i = 4;(i + 1) * 2 <= 30000 && N >= 2;i+=3) {
		N -= 2;
		ans.push_back(2 * i);
		ans.push_back(2 * (i + 1));
	}
	for (ll i = 5;(i + 2) * 3 <= 30000 && N >= 2; i += 4) {
		N -= 2;
		ans.push_back(3 * i);
		ans.push_back(3 * (i + 2));
	}
	ll i = 1;
	while (N > 0) {
		ans.push_back(i * 6);
		i++;
		N--;
	}
	for (int i = 0;i < ans.size();i++) {
		cout << ans[i];
		if (i == (ll)ans.size() - 1)
			cout << endl;
		else
			cout << " ";
	}
	return 0;
}