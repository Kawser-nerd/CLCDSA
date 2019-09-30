#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll A, K;
ll tgt = 2000000000000LL;
int main(){
    cin >> A >> K;

    if(K == 0) {
        cout << tgt - A << endl;
        return 0;
    }
    int ans = 0;
    ll t = A;
    while(t < tgt) {
        t = t * (K + 1) + 1;
        ans++;
    }
    cout << ans << endl;
}