#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
string a[128];

void read() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void solve() {
    vector<int> t;
    for (int i = 0; i < n; i++) t.push_back(i);

    do {
        int cur = t[0];
        for (int i = 1; i < n; i++) {
            if (a[cur][ t[i] ] == 'N') cur = t[i];
        }
        if (cur == k) {
            for (int i = 0; i < n; i++) printf ("%d%c", t[i], (i + 1 == n) ? '\n' : ' ');
            return ; 
        }
    } while (next_permutation(t.begin(), t.end()));
    printf ("IMPOSSIBLE\n");
}

int main() {
    int cases;

    cin >> cases;
    for (int i = 1; i <= cases; i++) {
        read();
        printf ("Case #%d: ", i);
        solve();
    }

    return 0;
}

