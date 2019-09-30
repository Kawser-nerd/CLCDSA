#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
using ulong = unsigned long;
using ll = long long;
ll mod = 1e9+7;
ll facts[(int)2e5+10];

ll modPow(ll base, ll ex, ll m) {
	ll ret = 1;
	while(ex){
		if(ex & 1){
			ret = ret * base % m;
		}
		ex >>= 1;
		base = base * base % m;
	}
	return ret;
}

ll modInv(ll n, ll m){
	return modPow(n, m-2, m);
}

ll modC(ll n, ll k, ll m){
	return facts[n] * modInv(facts[k] * facts[n-k] % m, m) % m;
}

ll solve(ll h, ll w, ll mod){
	return modC(h + w- 2, w - 1, mod);
}

void setFact(ll m){
	facts[0] = 1;
	for(int i=1;i<2e5+10;i++){
		facts[i] = facts[i-1] * i % m;
	}
}

int main(){
	int h, w, a, b;
	cin >> h >> w >> a >>b;
	setFact(mod);
	ll ans = 0, h1 = h - a, w1 = b + 1;
	while(w1 <= w && h1 >= 1){
		ans = (ans + solve(h1, w1, mod) * solve(h - h1 + 1, w - w1 + 1, mod))% mod;
		w1++;
		h1--;
	}
	cout << ans << endl;
	return 0;
}