#include<iostream>
#include<vector>
using namespace std;

bool solve(const vector<vector<int>>& t, int now, int cur, int n, int k) {
    bool flag = true;
    for (int i = 0; i < k && flag; i++) {
        if (now == n - 1) {
            if ((cur ^ t[now][i]) == 0) {
                return false;
            }
        } else {
            flag = solve(t, now+1, cur ^ t[now][i], n, k);
        }
    }
    return flag;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> t(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> t[i][j];
        }
    }
    if (solve(t, 0, 0, n, k)) {
        cout << "Nothing" << endl;
    } else {
        cout << "Found" << endl;
    }
}