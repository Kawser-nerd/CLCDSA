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
    int n;
    cin >> n;
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++){
        ans = min(ans,abs(i - n/i) + n % i);
    }
    cout << ans << endl;

    return 0;
}