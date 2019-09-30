#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007LL;
map<pair<ll,ll>, ll> um;

ll func(ll s, ll x){
  	//cout << s << ":" << x << endl;
  	if(s==0) return 1;
    //ch(s,x);
    if(um.find(make_pair(s,x))!=um.end()) return um[make_pair(s,x)];
    ll ret=0;
        ret += func(s/2, x/2);
        if(s>0&&x>0)ret += func( (s-1) / 2,(x - 1) / 2); 
  		ret %= MOD;
        if(s>1)ret += func( (s-2) / 2, x/2);
    um[make_pair(s,x)] = ret % MOD;
    return (ret % MOD);
}

int main(){
    ll n;
    cin >> n;
    cout << func(n,n) << endl;
    return 0;
}