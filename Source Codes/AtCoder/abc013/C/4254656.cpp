#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#include <set>
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve(){

}
int main(){
    ll N,H,A,B,C,D,E;
    cin >> N >> H >> A >> B >> C >> D >>E;
    ll ans = LLONG_MAX;
    for (int i = 0; i <= N; i++) {
        //ll k = floor(((double)((N-i)*E - H - B * i) / (D+E))) + 1;
        ll k = floor((double)((N - i) * E - (H + i * B)) / (D + E)) + 1;
        if (k >= 0 && k <= N - i) {
            ll t = A * i + C * k;
            ans = min(ans, t);
        } else if (k < 0) {
            ll t = A * i;
            ans = min(ans, t);
        }
    }
    cout << ans << endl;

    return 0;
}