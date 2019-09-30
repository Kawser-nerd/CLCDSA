#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

int main(){
    ll a,b,ans=0,n,m;
    cin>>n>>m;
    ll c[n];
    for (ll i=0; i<n; i++) {
        cin>>a>>b;
        c[i]=a*10000000+b;
    }
    sort(c,c+n);
    for (ll i=0; m>0; i++) {
        ans+=c[i]/10000000*min(c[i]%1000000,m);
        m-=min(c[i]%1000000,m);
    }
    cout<<ans<<endl;
}