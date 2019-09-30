#include <bits/stdc++.h>

using namespace std;

const int M = 100;
const int inf = 1e9;

int n, m;
int p[M];
int a[M][M];
int x[M];
int l[M][M], r[M][M];

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
        sort(a[i], a[i] + m);
        for (int j = 0; j < m; ++j) {
            int x = a[i][j];
            l[i][j] = (100 * x + 110 * p[i] - 1) / (110 * p[i]);
            r[i][j] = (100 * x) / (90 * p[i]);
        }
    }
}

void kill() {
    int ans = 0;
    fill(x, x + n, m - 1);
    while (*min_element(x, x + n) >= 0) {
        int lx = 0, rx = inf;
        int best = 0;
        for (int i = 0; i < n; ++i) {
            lx = max(lx, l[i][x[i]]);
            rx = min(rx, r[i][x[i]]);
            if (l[i][x[i]] > l[best][x[best]]) {
                best = i;
            }
        }
        if (lx <= rx) {
            ++ans;
            for (int i = 0; i < n; ++i)
                --x[i];
        } else {
            --x[best];
        }
    }
    cout << ans << endl;
}


int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    read();
    kill();
    cerr << "Case #" << i << " done.\n";
  }
  return 0;
}
