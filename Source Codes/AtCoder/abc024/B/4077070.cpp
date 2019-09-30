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

const int mod = 1e9 + 7;

void solve(){

}
int main(){
    int n,t;
    cin >> n >> t;
    vector<int> a(n);
    for (auto& x: a){
        cin >> x;
    }
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += min(t,abs(a[i] - a[i-1]));
    }
    ans += t;
    cout << ans << endl;



    return 0;
}