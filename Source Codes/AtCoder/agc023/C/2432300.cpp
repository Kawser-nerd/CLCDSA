#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll n;
ll mod = 1000000007;
ll rui[1234567];
const int NUM_ = 1234567;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
int main(){
    cin >> n;
    inv[1]=fact[0]=factr[0]=1;
    for (int i=2;i<=NUM_;++i) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mod, factr[i]=factr[i-1]*inv[i]%mod;
    ll ans = 0;
    for(ll i = n-1; i>=(n+1)/2; i--){
        rui[i] = fact[i];
        ll k = n-1-i;
        rui[i] = (rui[i]*fact[i-1]%mod)*factr[i-1-k]%mod;
    }
    for(ll i = (n+1)/2; i<n;i++){
        ans += i*(rui[i]-rui[i-1]+mod);
        ans%=mod;
    }
    cout << ans << endl;
}