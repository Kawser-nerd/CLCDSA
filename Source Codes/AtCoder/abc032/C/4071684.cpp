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
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve(){

}
int main(){
    /* ?????? */
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n+1);

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            cout << n << endl;
            return 0;
        }
    }


    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }

    a[n] = 1e9+10;
    n++;

    long long sum = 1;
    int right = 0;

    for (int left = 0; left < n; ++left) {
        /* sum ? a[right] ?????????? right ???? */
        while (right < n && sum <= k) {
            sum *= a[right];
            ++right;
        }

        ans = max(ans,(ll)right - left-1);
        sum /= a[left];
    }

    cout << ans << endl;

    return 0;
}