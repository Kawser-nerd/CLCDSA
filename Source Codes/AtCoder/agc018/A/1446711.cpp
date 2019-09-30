#include <iostream>
#include <algorithm>
using namespace std;

unsigned gcd(unsigned u, unsigned v) {
    while ( v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int main()
{
    int k,n;
    cin >> n >> k;
    int i,j;
    int a[n];
    for(i = 0; i < n; i++) cin >> a[i];
    int maxi = a[0];
    int gcdr = a[0];
    for(i = 1; i < n; i++){
       gcdr = gcd(a[0],a[i]);
       maxi = (maxi < a[i])? a[i] : maxi;
    }
    if(maxi < k) cout << "IMPOSSIBLE" << "\n";
    else{
        if(k % gcdr == 0)cout << "POSSIBLE" <<"\n";
        else cout << "IMPOSSIBLE" << "\n";
    }
  return 0;
}