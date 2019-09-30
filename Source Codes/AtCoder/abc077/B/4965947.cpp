#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <bitset>
#include <list>
using namespace std;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define rrep(i,a,n) for(ll i=n;i>=a;i--)
#define elif else if
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF = 1e+17;
const ll MODcdf = 998244353;
bool pairCompare(const P& firstElof,const P& secondElof){
    return firstElof.first<secondElof.first;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;cin>>n;
    ll ans,memo;
    memo=1;
    rep(i,1,n+1){
        ans=memo;
        memo=pow(i,2);
        if(memo>n)break;
    }
    cout<<ans<<endl;
}