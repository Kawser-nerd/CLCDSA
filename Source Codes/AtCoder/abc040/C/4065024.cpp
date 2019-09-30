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

const long long INF = 1LL << 60;

// DP ????
long long dp[100010];

const int MOD = 1e9 + 7;

void solve(){

}
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }

    for (int i = 0; i < 100010; ++i) {
        dp[i] = INF;
    }

    dp[0] = 0;
    dp[1] = abs(a[1] - a[0]);
    for (int i = 2; i < N; ++i) {
        dp[i] = min(dp[i],dp[i-1] + abs(a[i] - a[i-1]));
        dp[i] = min(dp[i],dp[i-2] + abs(a[i] - a[i-2]));
    }
    cout << dp[N-1] << endl;
    

    return 0;
}