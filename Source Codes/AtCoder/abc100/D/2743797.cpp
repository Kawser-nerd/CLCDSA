#include <iostream>
#include <vector>
#include <utility>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>

#define rep(i, m, n) for (int (i)(m); (i)<(n); ++(i))
#define repv(i, v) for (int (i)(0); (i)<(v.size()); ++(i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vb>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

int main(){
	ll N, M;
	cin >> N >> M;
	vvll xyz;
	rep(i, 0, N) {
		ll x, y, z;
		cin >> x >> y >> z;
		xyz.push_back({x, y, z});
	}
	ll sign[8][3] = {{1,1,1},{1,1,-1},{1,-1,1},{-1,1,1},
				{1,-1,-1},{-1,1,-1},{-1,-1,1},{-1,-1,-1}};
	ll sum = 0;
	rep(i, 0, 8) {
		vll s;
		rep(j, 0, N) {
			s.push_back(xyz[j][0] * sign[i][0]
						+ xyz[j][1] * sign[i][1]
						+ xyz[j][2] * sign[i][2]);
		}
		sort(all(s), greater<ll>());
		ll t = 0;
		rep(j, 0, M) {
			t += s[j];
		}
		sum = max(sum, t);
	}
	cout << sum << endl;
}