#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string x[200], y[200];
bool z[200];

int main() {
    int T, N, L;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        cin >> N >> L;
        for (int i = 0; i < N; ++i) cin >> x[i];
        for (int i = 0; i < N; ++i) cin >> y[i];
        vector<string> B;
        for (int i = 0; i < N; ++i) B.push_back(y[i]);
        sort(B.begin(), B.end());
        int ans = 10000;
        for (int i = 0; i < N; ++i) {
            memset(z, 0, sizeof(z));
            int temp = 0;
            for (int j = 0; j < L; ++j) {
                if (x[0][j] != y[i][j]) {
                    z[j] = true;
                    ++temp;
                }
            }
            vector<string> X;
            for (int k = 0; k < N; ++k) {
                string Q;
                for (int j = 0; j < L; ++j) {
                    if (!z[j]) {
                        Q = Q + x[k][j];
                    } else {
                        if (x[k][j] == '1') Q = Q + '0'; else Q = Q + '1';
                    }
                }
                X.push_back(Q);
            }
            sort(X.begin(), X.end());
            if (X == B) {
                if (temp < ans) ans = temp;
            }
        }
        cout << "Case #" << times << ": ";
        if (ans == 10000) {
            cout << "NOT POSSIBLE" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
