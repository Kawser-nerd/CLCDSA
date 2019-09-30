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
    int N;
    cin >> N;
    vector<int> A(N),B(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }

    ll ans = 0;
    for (int i = N-1; i >= 0; --i) {
        ll cost = 0;
        cost = (B[i] - ((A[i] + ans) % B[i])) % B[i];
        ans += cost;
    }
    cout << ans << endl;


    return 0;
}