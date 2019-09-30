#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ll sum = 0;
    ll N;
    cin >> N;
    ll a[N];
    for(int i = 0; i < N; ++i){
        cin >> a[i];
        sum += a[i];
    }
    ll tmp = 0;
    ll ans = INT_MAX;
    if(N == 2){
        cout << abs(a[0]-a[1]) << endl;
        return 0;
    }
    for(int i = 0; i < N-1; ++i){
        tmp += a[i];
        ans = min(ans, abs(sum-2*tmp));
    }

    cout << ans << endl;

    return 0;
}