#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int A[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    vector <int> idx(n, 0);
    vector <bool> removed(m+1, false);
    int mn = n;

    while (true) {
        map <int, int> mp;
        int mx = 0;
        int mx_team;
        for (int i = 0; i < n; i++) {
            int t = A[i][idx[i]];
            if (++mp[t] > mx) {
                mx = mp[t];
                mx_team = t;
            }
        }

        mn = min(mn, mx);
        removed[mx_team] = true;

        bool breaker = false;
        for (int i = 0; i < n; i++) {
            while (removed[A[i][idx[i]]]) {
                if (++idx[i] >= m) {
                    breaker = true;
                    break;
                }
            }
        }

        if (breaker) break;
    }

    cout << mn << "\n";
    return 0;
}