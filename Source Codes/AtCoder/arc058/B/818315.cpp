#include <iostream>

using namespace std;

#define MAX_H 100000
#define MAX_W 100000
#define MOD 1000000007

typedef long long ll;

ll inv_(ll a, ll m){
	// assert(0 < a < m && gcd(a,m) == 1 && 0 < ret < m)
	if(a == 1) return 1;
	return m+(1 - m * inv_(m % a, a)) / a;
}

ll inv(ll a, ll m){
	if(m < 0) m = -m;
	a %= m;
	return inv_((a < 0 ? a+m : a), m);
}


/*
(b-1)C0 * (h+p-2)C(p-1) + (b-1+1)C1 * (h+p-3)C(p-1) + … + (b-1+q-1)C(q-1) * (h+p-2+q-1)C(p-1)
*/
int main(){
	int h,w,a,b,h2;
	cin >> h >> w >> a >> b;
	int p = w-b;
	int q = h-a;
	
	ll l = 1,r=1,ans = 0;
	
	// r = (h+p-1)C(p-1)
	for(int i = 1;i < p;i++){
		r = r*(h+i)%MOD*inv(i, MOD)%MOD;
	}
	
	for(int i = 0;i < q;i++){
		if(i) l = l*(b-1+i)%MOD*inv(i, MOD)%MOD;
		r = r*inv(h+p-1-i, MOD)%MOD*(h-i)%MOD;
		ans = (ans + l*r%MOD) % MOD;
	}
	cout << ans << endl;
	return 0;
}