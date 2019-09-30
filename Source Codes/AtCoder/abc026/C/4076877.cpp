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
    int N;
    cin >> N;
    vector<int> B(N-1),P(N+1);
    map<int,vector<int>> m;
    for (int i = 1; i <= N; i++) {
        m[i];
    }

    for (int i = 0; i < N-1; i++) {
        cin >> B[i];
        m[B[i]].push_back(i+2);
    }

    //????
    for (int i = N; i > 0; i--) {
        if (m[i].size() == 0) {
            P[i] = 1;
        } else {
            int maxv = 0;
            int minv = INT_MAX;
            for (auto x : m[i]) {
                maxv = max(maxv, P[x]);
                minv = min(minv, P[x]);
            }
            P[i] = maxv + minv + 1;
        }
    }

    cout << P[1] << endl;

    return 0;
}