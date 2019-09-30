#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

int main(){
    ll a,n,m,c,d=0;
    cin>>n;
    if (n%2==0) {
        cout<<(n*(n-1))/2-n/2<<endl;
        for (ll i=1; i<n; i++) {
            for (ll j=i+1; j<=n; j++) {
                if (i+j-1!=n) {
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
    }
    if (n%2==1) {
        cout<<(n*(n-1))/2-n/2<<endl;
        for (ll i=1; i<n; i++) {
            for (ll j=i+1; j<=n; j++) {
                if (i+j!=n) {
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
    }
}