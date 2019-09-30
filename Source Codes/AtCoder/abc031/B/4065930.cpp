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
    int L,H,N;
    cin >> L >> H >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        int ans = 0;
        if (a[i] < L) {
            ans = L - a[i];
        } else if (a[i] > H) {
            ans = -1;
        }
        cout << ans << endl;
    }
            



    return 0;
}