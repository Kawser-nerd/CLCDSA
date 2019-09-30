#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long int ll;
const ll MOD = 1000000007LL;

//This source code is in the case of n, k <= 2020 (in nCk)

ll fact[4040404], frev[4040404];
ll invs[4040404];
//fact[n] = n! mod MOD
//frev[n] = 1 / n! mod MOD
//invs[n] = 


ll C(int a, int b)
{
	if (a < b) return 0;
	return fact[a] * frev[b] % MOD * frev[a - b] % MOD;
}
ll P(int a, int b){
    if(a<b) return 0;
    return fact[a] * frev[a - b] % MOD;
}

ll modpow(ll a, ll p = MOD - 2)
{
	if (p == 0) return 1;
	ll tmp = modpow(a, p / 2);
	tmp = tmp * tmp % MOD;
	if (p % 2) tmp = tmp * a % MOD;
	return tmp;
}

void fill_combination_table(){
	fact[0] = 1; frev[0] = 1;
	invs[0] = 1;
	invs[1] = 1;
	for (int i = 2; i < 4040404; ++i) invs[i] = MOD - MOD / i * invs[MOD % i] % MOD;
	for (int i = 1; i < 4040404; ++i) {
		fact[i] = fact[i - 1] * i % MOD;
		frev[i] = frev[i - 1] * invs[i] % MOD;
	}
}

ll dp[1005][1005];
bool ch[1005][1005];
int n,a,b,c,d;
ll func(int i, int j){
    if(ch[i][j]) return dp[i][j];
    if(i<a && j==0) return 1;
    if(j>n || i<a) return 0;
    ll &ret = dp[i][j];
    ret = 0;
    //k = 0
    ret += func(i-1, j);
    for(int k=c; k<= min(d, j/i); k++){
        ret += func(i-1,j - i*k) * P(n - j+i*k, i*k) % MOD * frev[k] % MOD * modpow(frev[i], k) % MOD;
        ret %= MOD;
    }
    ch[i][j] = true;
    return ret;
}

int main(){
    cin >> n >> a >> b >> c >> d;
    for(int i=0;i<1005; i++) for(int j=0;j<1005;j++) ch[i][j] = false;
    fill_combination_table();
    cout << func(b,n) << endl;
    return 0;
}