#include <iostream>
#include <cmath>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;

int main(void) {
    ll n, i, ans=0;
    cin >> n;
    ll a[n+1], cnt[n+1];
    for(i=0; i<=n; i++)
        cnt[i]=0;
    for(i=1; i<=n; i++)
        cin >> a[i];
    
    ll j=1;
    while(1) {
        j=a[j];
        ans++;
        if(j==2) {
            cout << ans << endl;
            return 0;
        }
        if(cnt[j]>=1) {
            cout << -1 << endl;
            return 0;
        }
        cnt[j]++;
    }
}