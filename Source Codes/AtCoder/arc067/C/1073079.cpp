#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<vector>
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
const ll MLL = 1e18L + 9;
#pragma unused(M)
#pragma unused(MLL)
#ifdef LOCAL
#include"basic.hpp"
#else
template <class... T> void printl(T&&...){ }
template <class... T> void printc(T&&...){ }
template <class... T> void prints(T&&...){ }
#endif

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

ll modFact(ll n, ll m){
	if(!n){ return 1; }
	for(ll i=n-1;i>1;i--){
		n = n * i % m;
	}
	return n;
}

pair<ll, pair<ll, ll>> exGCD(ll a, ll b){
	bool inv = false;
	if(a < b){
		swap(a, b);
		inv = true;
	}
	vector<ll> r = {a, b}, ks;
	while(b){
		ks.push_back(a / b);
		r.push_back(a = a % b);
		swap(a, b);
	}
	ll gcd = a;

	ll x = 0, y = 1, u = 1, v = -ks[0];
	for(unsigned long i=1;i<ks.size();i++){
		ll k = ks[i];
		ll x2 = u, y2 = v,
		   u2 = x - k * u, v2 = y - k * v;
		x = x2; y = y2; u = u2; v = v2;
	}

	if(inv){
		swap(x, y);
	}
	return {gcd, {x, y}};
}

ll modInv(ll n, ll m){
	return modPow(n, m-2, m);
	auto p = exGCD(n, m);
	return (p.second.first + m) % m;
}

ll modC(ll n, ll k, ll m){
	return modFact(n, m) * modInv(modFact(k, m) * modFact(n-k, m) % m, m) % m;
}

ll dp[1010][1010];
vector<ll> fact(1010), ifact(1010);
int main(){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    fact[0] = 1;
    ifact[0] = 1;
    for(int i=1;i<=n;i++){
        fact[i] = 1ll * fact[i - 1] * i % M;
        ifact[i] = modInv(fact[i], M);
    }
    // prints(fact, ifact);
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=a;i<=b;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<=d;k++){
                // prints(i, j, k);
                if(j - i * k < 0){ continue; }
                dp[i][j] += dp[i - 1][j - i * k] * fact[n - j + i * k] % M * ifact[n - j] % M * modPow(ifact[i], k, M) % M * ifact[k] % M;
                dp[i][j] %= M;
                // if(j == 3){ prints(i, j, k, dp[i][j], dp[i - 1][j - i * k] , fact[n - j + i * k] ,  ifact[n - j] ,  modPow(ifact[i], k, M) ,  ifact[k] % M); }
                if(k == 0){
                    // prints(i, j, dp[i][j], dp[i - 1][j - i * k] , fact[n - j + i * k] ,  ifact[n - j] ,  modPow(ifact[i], k, M) ,  ifact[k] % M);
                    k = c - 1;
                }
            }
        }
    }
    // for(int i=0;i<=b;i++){
    //     for(int j=0;j<=n;j++){
    //         cout << dp[i][j] << ' ';
    //     }cout << endl;
    // }
    cout << dp[b][n] << '\n';
    return 0;
}

// map<pair<int, int>, int> m;
// int n, a, b, c, d;
// int memo[1010][1010];
// bool visited[1010][1010];
// int func(int prev, int rem){
//     // if(prev > 1000 || rem > 1000){exit(1);}
//     //zero?
//     // static int cnt2 = 0;
//     if(visited[prev][rem]){ return memo[prev][rem]; }
//     // m[{prev, rem}]++;
//     if(rem == 0){
//         return 1;
//         int ret = 1;
//         visited[prev][rem] = true;
//         return memo[prev][rem] = ret;
//         // return ret;
//     }
//     static int cnt = 0;
//     cnt++;
//     if(cnt % 10000 == 0){
//         prints(cnt);
//         // prints(cnt2);
//     }
//     // if(prev == 1){
//     //     return;
//     // }
//     ll ans = 0;
//     for(int i = min(prev, rem); i>=1; i--){
//     // for(int i=1; i<prev && i<= rem; i++){
//         ll ret = 1;
//         for(int j = rem / i; j >= 1; j--){
//         // for(int j=1;rem >= i * j;j++){
//             int _rem = rem;
//             // for(int k=0;k<j;k++){
//             //     static map<pair<int, int>, int > memoc;
//             //     if(memoc.count({_rem, i})){
//             //         ret = ret * memoc[{_rem, i}] % M;
//             //     }else{
//             //         ret = ret * (memoc[{_rem, i}] = modC(_rem, i, M)) % M;
//             //     }
//             //     _rem -= i;
//             // }
//             static map<int, int> memoi;
//             if(memoi.count(j)){
//                 ret = ret * memoi[j] % M;
//             }else{
//                 // ret = ret * (memoi[j] = modInv(modFact(j, M), M)) % M;
//             }
//             ret = ret * func(i - 1, rem - i * j) % M;
//         }
//         // ret = (ret + func(i, rem - i * j)) % M;
//         ans = (ans + ret) % M;
//     }
//     visited[prev][rem] = true;
//     return memo[prev][rem] = ans;
// }
//
// int main(){
//     cin >> n >> a >> b >> c >> d;
//     // func(n, n);
//     cout << func(n, n) << '\n';
//     // prints(modC(7, 3, M));
//     //TODO
//     // prints(m);
//     for(auto p : m){
//         prints(p.first, p.second);
//     }
//     return 0;
// }