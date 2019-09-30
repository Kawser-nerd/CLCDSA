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

    int ans = 1;
    for (int i = 0; i < N; ++i) {
        if (ans * 2 < ans + K) {
            ans *= 2;
        } else {
            ans += K;
        }
    }
    cout << ans << endl;

    return 0;
}