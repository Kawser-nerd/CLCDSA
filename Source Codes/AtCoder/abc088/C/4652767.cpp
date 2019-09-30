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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define rep(i, a, N) for(int i = a; i < N; i++)

int main() {
    int c[3][3];

    rep(i, 0, 3)
        rep(j, 0, 3)
            cin >> c[i][j];
    
    int column[3] = {};
    int row[3] = {};
    rep(i, 0, 3) {
        rep(j, 0, 3) {
            column[j] += c[i][j] - c[0][j];
            row[i] += c[i][j] - c[i][0];
        }
    }

    if (column[0] == column[1] && column[1] == column[2] && row[0] == row[1] && row[1] == row[2])
        cout << "Yes" << endl;
    else cout << "No" << endl;
}