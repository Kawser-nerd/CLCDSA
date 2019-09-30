#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iomanip>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int t = 500;

    vector<vector<int>> x(a, vector<int>(b, t));

    for (int i = 0; i + c - 1 < a; i += c) {
        for (int j = 0; j + d - 1 < b; j += d) {
            x[i + c - 1][j + d - 1] = -t * (c * d - 1) - 1;
        }
    }

    long long s = 0;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            s += x[i][j];
        }
    }

    if (s <= 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                cout << x[i][j] << " \n"[j + 1 == b];
            }
        }
    }
}