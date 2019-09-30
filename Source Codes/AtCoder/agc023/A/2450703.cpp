#include <iostream>
#include <algorithm>
#include <string>
#include <functional> 
#include <vector>
#include <numeric>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <cstdlib>
typedef long long ll;
#define fi first
#define se second

using namespace std;

int main(){

    int n = 0;
    cin >> n;

    vector<ll> s(n+1);
    s[0] = 0;
    map<ll,ll> m;
    m[0] = 1;
    for(int i=1;i<=n;i++){
        ll a;
        cin >> a;
        s[i] = s[i-1] + a;
        m[s[i]]++;
    }
    ll ans=0;
    for(auto k:m) ans += k.second*(k.second-1)/2;
    cout << ans;


    return 0;
}