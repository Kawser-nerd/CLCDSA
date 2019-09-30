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
const int r = 110000;

void solve(){

}
int main(){
    int N;
    cin >> N;
    int dp[r] = {};
    for (int i = 0; i < r; ++i) {
        dp[i] = N;
    }
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int pow6 = 1; i + pow6 <= N; pow6 *= 6) {
            dp[i + pow6] = min(dp[i + pow6], dp[i] + 1);
        }
        for (int pow9 = 1; i + pow9 <= N; pow9 *= 9) {
            dp[i + pow9] = min(dp[i + pow9], dp[i] + 1) ;
        }
    }

    cout << dp[N] << endl;



    return 0;
}