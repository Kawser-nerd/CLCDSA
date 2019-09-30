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

array<array<int, 5>,5> t;

int N,K;

bool dfs(int numQ, int v) {
    if (numQ == N) return (v == 0);
    for (int i = 0; i < K; i++) {
        if (dfs(numQ+1,v^t[numQ][i])) return true;
    }
    return false;
}

int main(){
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < K; k++) {
            cin >> t[i][k];
        }
    }
    if (dfs(0,0)){
        cout << "Found" << endl;
    } else {
        cout << "Nothing" << endl;
    }

    return 0;
}