#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll numd(ll N) {
	return N ? numd(N / 10) + 1 : 0;
}

ll p10(ll n) {
	return n ? 10 * p10(n - 1) : 1;
}

ll rev(ll n) {
	ll r = 0;
	while(n) {
		r *= 10;
		r += n % 10;
		n /= 10;
	}
	return r;
}

map<ll, ll> dp;
void slow() {
	dp[0] = 0;
	queue<ll> q;
	q.push(0);
	for(int i = 0; i < 1000000; i++) {
		ll v = q.front(); q.pop();
		ll n;
		n = v + 1;
		if(!dp.count(n)) {
			dp[n] = dp[v] + 1;
			q.push(n);
		}
		n = rev(v);
		if(!dp.count(n)) {
			dp[n] = dp[v] + 1;
			q.push(n);
		}
	}
}

ll go(ll N) {
	ll cur = 0;
	ll res = 0;
	while(cur < N) {
		ll nxt = min(cur * 10 + 9, N);

		if(cur == 0) {
			res += nxt;
		} else {
			res++, cur++;
			ll d = numd(nxt);

			ll suff = nxt % p10((d + 1) / 2);
			ll pref = rev(nxt - suff);
			if(pref == 1) {
				res += suff;
			} else if (suff >= 1) {
				// increment tail up to the prefix
				res += pref;
				// flip
				res++;
				// increment tail up to suffix
				res += suff - 1;
			} else {
				assert(suff == 0);
				assert(pref > 1);
				suff = p10((d + 1) / 2);
				pref = rev(nxt - suff);

				if(pref == 1) {
					res += suff;
				} else {
					res += pref + suff;
				}
			}
		}

		cur = nxt;
	}
	return res;
}

int main() {
	int T; cin >> T;
	for(int i = 0; i < T; i++) {
		ll n; cin >> n;
		ll r = go(n);
		cout << "Case #" << i+1 << ": " << r << '\n';
	}

	return 0;
}
