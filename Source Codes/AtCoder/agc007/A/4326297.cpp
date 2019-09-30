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
    int H,W;
    cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; ++i) {
        cin >> A[i];
    }
    int cnt = 0;
    for (int i = 0; i < H; ++i) {
        for (int k = 0; k < W; ++k) {
            if (A[i][k] == '#') {
                cnt++;
            }
        }
    }
    if (cnt == H+W-1) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}