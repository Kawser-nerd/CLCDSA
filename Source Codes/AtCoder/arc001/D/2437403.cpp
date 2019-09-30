#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
 
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, K, M, T;
int A, B;
string s[8];

string ans[8];

int dfs(int n, string b[8], int y, int x) {
    if (n == 8) {
        for (int i = 0; i < 8; i++) ans[i] = b[i];
        return 1;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (s[i][j] == 'Q') continue;
            bool flag = true;
            for (int k = 0; k < 8; k++) {
                if (s[k][j] == 'Q') flag = false;
            }
            for (int k = 0; k < 8; k++) {
                if (s[i][k] == 'Q') flag = false;
            }
            for (int k = -8; k < 8; k++) {
                if (i+k < 0 || i+k > 7 || j+k < 0 || j+k > 7) continue;
                if (s[i+k][j+k] == 'Q') flag = false;
            }
            for (int k = -8; k < 8; k++) {
                if (i+k < 0 || i+k > 7 || j-k < 0 || j-k > 7) continue;
                if (s[i+k][j-k] == 'Q') flag = false;
            }
            if (flag) {
                b[i][j] = 'Q';
                int res = dfs(n+1, b, i, j);
                if (res) return 1;
                b[i][j] = '.';
            }
        }
    }
    return 0;
}

int main() {
    for (int i = 0; i < 8; i++) cin >> s[i];
    bool flag = true;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (s[i][j] == '.') continue;
            for (int k = 0; k < 8; k++) {
                if (k == i) continue;
                if (s[k][j] == 'Q') flag = false;
            }
            for (int k = 0; k < 8; k++) {
                if (k == j) continue;
                if (s[i][k] == 'Q') flag = false;
            }
            for (int k = -8; k < 8; k++) {
                if (k == 0) continue;
                if (i+k < 0 || i+k > 7 || j+k < 0 || j+k > 7) continue;
                if (s[i+k][j+k] == 'Q') flag = false;
            }
            for (int k = -8; k < 8; k++) {
                if (k == 0) continue;
                if (i+k < 0 || i+k > 7 || j-k < 0 || j-k > 7) continue;
                if (s[i+k][j-k] == 'Q') flag = false;
            }
        }
    }
    int res = dfs(3, s, -1, -1);
    if (res && flag) {
        for (int i = 0; i < 8; i++) cout << ans[i] << endl;
    } else {
        cout << "No Answer" << endl;
    }
    // cout << ans << endl;
    return 0;
}