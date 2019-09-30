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
    int A,B,C,K,S,T;
    cin >> A >> B >> C >> K >> S >> T;
    int ans = A * S + B * T;
    int sum = S+T;
    if (sum >= K) {
        ans -= C * sum;
    }
    cout << ans << endl;

    return 0;
}