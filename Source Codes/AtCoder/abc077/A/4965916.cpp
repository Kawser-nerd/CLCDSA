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
    string s,n;cin>>s>>n;
    if(s[0]!=n[2])cout<<"NO"<<endl;
    elif(s[1]!=n[1])cout<<"NO"<<endl;
    elif(s[2]!=n[0])cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}