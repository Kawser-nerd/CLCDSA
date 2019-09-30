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
    int x,y;
    cin >> x >> y;
    int ans = INT_MAX;
    int dx[4] = {1,1,-1,-1};
    int dy[4] = {1,-1,1,-1};

    for (int i = 0; i < 4; ++i) {
        int tx = x * dx[i];
        int ty = y * dy[i];
        if (tx <= ty) {
            int cnt = 0;
            if (dx[i] == -1) {
                cnt++;
            }
            if (dy[i] == -1) {
                cnt++;
            }
            ans = min(ans, (ty - tx) + cnt);
        }
    }
    cout << ans << endl;


    return 0;
}