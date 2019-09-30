#include <iostream>
using namespace std;

using ll = long long;

int main(){
    ll N; cin >> N;
    ll ans = 0;
    ll x[N], y[N];
    for(int i = 0; i < N; ++i){
        cin >> x[i] >> y[i];
    }

    for(int i = 2;i < N; ++i){
        for(int j = 1; j < i; ++j){
            for(int k = 0; k < j; ++k){
                ll x1 = x[i] - x[j];
                ll x2 = x[j] - x[k];
                ll y1 = y[i] - y[j];
                ll y2 = y[j] - y[k];
                ll t = x1*y2 - x2*y1;
                if(t % 2 == 0 && t != 0) ans++;
            }
        }

    }
    cout << ans << endl;

    return 0;
}