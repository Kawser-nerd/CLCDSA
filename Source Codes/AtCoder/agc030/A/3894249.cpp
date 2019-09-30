#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a,b,c;
    cin >> a >> b >> c;
    
    ll ans = 0;
    
    if (a+b > c) ans = b+c;
    else if (a+b < c) ans = a+b*2+1;
    else if (a+b == c) ans = a+b*2;
    
    cout << ans << '\n';
    
    return 0;
}