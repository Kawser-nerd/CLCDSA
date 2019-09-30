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
const int INF = 1001001001;
const ll LINF = 1e18;
void solve(){

}
int main(){
    ll A,B,C;
    cin >> A >> B >> C;
    ll total = A * B * C;
    ll ans = LINF;
    if (A % 2 == 1 && B % 2 == 1 && C % 2 == 1) {
        ans = min(ans, min(B*C,min(C*A,A*B)));
    } else {
        ans = 0;
    }
    cout << ans << endl;

    return 0;
}