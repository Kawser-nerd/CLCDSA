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
ll calc(ll A) {

    if (A < 0) return 0;
    ll ans = 0;
    A++;
    for (int i = 0; i < 50; ++i) {
        //??
        ll loop = (1LL << (i + 1));
        //1?????
        ll cnt = (A / loop) * (loop / 2);

        //????
        cnt += max(0LL,(A % loop) - (loop / 2));
        if (cnt % 2 == 1) {
            ans += 1LL << i;
        }
    }
    return ans;
}
int main(){
    ll A,B;
    cin >> A >> B;
    ll ans = calc(B) ^ calc(A-1);
    cout << ans << endl;

    return 0;
}