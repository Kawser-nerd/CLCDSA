#include <iostream>
#define MAX_N 100000
using namespace std;
typedef long long ll;
ll N, K;
ll a[MAX_N];

int main(){
    cin >> N >> K;
    for(ll i = 0; i < N; ++i) cin >> a[i];
    ll ans = 0;
    for(ll i = 0; i < N; ++i){
        ans += a[i] * min(min(K, N-K+1), min(i+1, N-i));
    }
    cout << ans << endl;
    return 0;
}