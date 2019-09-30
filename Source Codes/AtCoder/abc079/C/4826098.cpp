#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>
#include <stack>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
//typedef pair<int, int> P;

#define rep(i, a, N) for(int i = a; i < N; i++)
#define rrep(i, a, N) for(int i = a; i >= N; i--)

int n[4];

void dfs(int i, int j, string op) {
    if (i == 4 && j == 7) {
        op += "=";
        rep(i, 0, 4) cout << n[i] << op[i];
        cout << "7" << endl;
        exit(0);
    }
    if (i == 4 && j != 7) {
        return;
    }
    dfs(i + 1, j + n[i], op + "+");
    dfs(i + 1, j - n[i], op + "-");
}

int main() {
    int s;
    cin >> s;
    rrep(i, 3, 0) {
        n[i] = s % 10;
        s /= 10;
    }
    dfs(1, n[0], "");
}