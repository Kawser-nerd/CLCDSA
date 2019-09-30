#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int Q, H, S, D, N;

int main(){
    cin >> Q >> H >> S >> D;
    cin >> N;

    H = min(H, Q * 2);
    S = min(S, H * 2);
    D = min(D, S * 2);

    //cout << Q << H << S << D;

    ll ans = N / 2LL * D + N % 2LL * S;

    cout << ans << endl;
}