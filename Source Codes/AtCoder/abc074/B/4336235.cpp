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
    int N,K;
    cin >> N >> K;
    vector<int> x(N);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        int d = min(abs(x[i] - 0),abs(K - x[i]));
        d *= 2;
        ans += d;
    }
    cout << ans << endl;

    return 0;
}