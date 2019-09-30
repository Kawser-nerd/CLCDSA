#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,a,b,c,d;
int main(void){
    cin>>a>>b>>c>>d>>n;
    ll one=min({a*4,b*2,c});
    ll two=min({a*8,b*4,c*2,d});
    cout<<n/2*two+n%2*one;
}