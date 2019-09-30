#include<iostream>
#include<algorithm>
#include<vector>
using LL = long long;
LL N,w;
LL W, V;
LL size[4];
LL ans;
std::vector<LL> dp1,dp2,dp3,dp4;
void value(LL x, LL y, LL z, LL q) {
	LL sum = 0;
	for (LL aa = 0; aa < x; aa++) {
		sum += dp1[aa];
	}
	for (LL aa = 0; aa < y; aa++) {
		sum += dp2[aa];
	}
	for (LL aa = 0; aa < z; aa++) {
		sum += dp3[aa];
	}
	for (LL aa = 0; aa < q; aa++) {
		sum += dp4[aa];
	}
	ans = std::max(ans, sum);
}
void solve() {
	for (LL i = 0; i <= dp1.size(); i++) {
		for (LL j = 0; j <= dp2.size(); j++) {
			for (LL k = 0;k <= dp3.size(); k++) {
				for (LL l = 0; l <= dp4.size(); l++) {
					LL ww=0;
					ww += i*w;
					ww += j*(w + 1);
					ww += k*(w + 2);
					ww += l*(w + 3);
					if (ww <= W) {
						value(i, j, k, l);
					}
				}
			}
		}
	}
}
int main() {
	std::cin >> N >> W;
	std::cin >> w>> V;
	dp1.push_back(V);
	for (LL i = 1; i < N; i++) {
		LL tmp,Q;
		std::cin >> tmp >> Q;
		if (tmp - w == 0) dp1.push_back(Q);
		if (tmp - w == 1) dp2.push_back(Q);
		if (tmp - w == 2) dp3.push_back(Q);
		if (tmp - w == 3) dp4.push_back(Q);
 
	}
	std::sort(dp1.rbegin(), dp1.rend());
	std::sort(dp2.rbegin(), dp2.rend());
	std::sort(dp3.rbegin(), dp3.rend());
	std::sort(dp4.rbegin(), dp4.rend());
	solve();
	std::cout << ans ;
	return 0;
}