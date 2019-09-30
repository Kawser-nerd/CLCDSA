#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long
#define P 150094669656737489LL

static ll memo[51][51] = {{}};

ll comb(int n, int k) {
	if(k==1) return n;
	if(k==0) return 1;
	if(n==k) return 1;
	if(memo[n][k]!=0) return memo[n][k];
	return memo[n][k] = comb(n-1, k-1)+comb(n-1,k);
}

int main() {
	int n, a, b;
	std::vector<ll> v;
	std::map<ll, int> m;
	scanf("%d %d %d", &n, &a, &b);
	for(int i=1; i<=n; i++) {
		ll tmp;
		scanf("%lld", &tmp);
		v.push_back(tmp);
	}
	std::sort(v.begin(), v.end(), std::greater<ll>());
	if(v[0]==v[a-1]) {
		double ans = (double)(v[0]*a)/a;
		int cnt = 0;
		for(int i=0; i<n; i++) {
			if(v[i]==v[0]) cnt++;
		}
		ll c = 0;
		for(int i=a-1; i<=b-1; i++) {
			if(v[i]!=v[0]) break;
			else c += comb(cnt, i+1);
		}
		printf("%f\n%lld\n", ans, c);
		return 0;
	} else {
		double ans = 0;
		for(int i=0; i<a; i++) {
			ans += v[i];
		}
		ans = ans / a;
		int cnt1 = 0;
		for(int i=0; i<n; i++) {
			if(v[i]==v[a-1]) cnt1++;
		}
		int cnt2=0;
		for(int i=0; i<a; i++) {
			if(v[i]==v[a-1]) cnt2++;
		}
		printf("%f\n%lld\n", ans, comb(cnt1, cnt2));
		return 0;
	}
	return 0;
}