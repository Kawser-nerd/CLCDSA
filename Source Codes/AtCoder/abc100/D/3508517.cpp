#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main() {
	ll N, M;
    cin >> N >> M;

	vector<vector<ll>> goodness(8);

	for(ll i=0; i<N; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		goodness[0].push_back(x+y+z);
		goodness[1].push_back(x+y-z);
		goodness[2].push_back(x-y+z);
		goodness[3].push_back(x-y-z);
		goodness[4].push_back(-x+y+z);
		goodness[5].push_back(-x+y-z);
		goodness[6].push_back(-x-y+z);
		goodness[7].push_back(-x-y-z);
	}

	ll ans = numeric_limits<ll>::min();
	for(int i=0; i<8; i++) {
		sort(goodness[i].begin(), goodness[i].end());
		reverse(goodness[i].begin(), goodness[i].end());

		ll x = 0;

		for(ll j=0; j<M; j++) {
			x += goodness[i][j];
		}
		ans = max(ans, x);
	}

	cout << ans << endl;
}