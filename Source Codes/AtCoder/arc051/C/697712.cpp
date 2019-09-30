#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll pow(ll x, ll e){
	ll v = 1;
	for(;e;e>>=1){
		if(e & 1){
			v = v * x % MOD;
		}
		x = x * x % MOD;
	}
	return v;
}

int main(){
	int N;
	cin >> N;
	ll A, B;
	cin >> A >> B;
	vector<ll> a(N);
	for(int i=0;i<N;i++){
		cin >> a[i];
	}

	if(A == 1){
		sort(a.begin(), a.end());
		for(ll x : a){
			cout << x << endl;
		}
		return 0;
	}

	while(B > 0){
		ll mini_k = 0;
		ll maxi_k = 0;
		for(int i=0;i<N;i++){
			if(a[i] < a[mini_k]){
				mini_k = i;
			}
			if(a[i] > a[maxi_k]){
				maxi_k = i;
			}
		}
		if(a[mini_k] * A >= a[maxi_k]){
			break;
		}
		a[mini_k] *= A;
		--B;
	}
	sort(a.begin(), a.end());

	ll pw = pow(A, B / N);
	for(ll &x : a){
		x = x * pw % MOD;
	}
	int rem = B % N;
	for(int i=0;i<rem;i++){
		a[i] = a[i] * A % MOD;
	}
	rotate(a.begin(), a.begin() + rem, a.end());

	for(ll x : a){
		cout << x << endl;
	}
	return 0;
}