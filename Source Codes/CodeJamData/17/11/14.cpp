#include <bits/stdc++.h>

using namespace std;

const int M = 50;

int n, m;
char a[M][M];
bool ok[M];

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
}

void kill() {
    for (int i = 0; i < n; ++i) {
        ok[i] = false;
        for (int j = 0; j < m; ++j)
            if (a[i][j] != '?')
                ok[i] = true;
    }

    for (int i = 0; i < n; ++i) { 
        for (int j = 0; j < m; ++j)
            if (a[i][j] != '?') {
                for (int x = 1; j - x >= 0; ++x)
                    if (a[i][j - x] == '?')
                        a[i][j - x] = a[i][j];
                    else
                        break;

                for (int x = 1; j + x < m; ++x)
                    if (a[i][j + x] == '?')
                        a[i][j + x] = a[i][j];
                    else
                        break;
            }

        if (ok[i]) {
            for (int x = 1; i - x >= 0; ++x)
                if (!ok[i - x]) {
                    copy(a[i], a[i] + m, a[i - x]);
                } else {
                    break;
                }
            for (int x = 1; i + x < n; ++x)
                if (!ok[i + x]) {
                    copy(a[i], a[i] + m, a[i + x]);
                } else {
                    break;
                }
        }
    }

    for (int i = 0; i < n; ++i, cout << endl)
        for (int j = 0; j < m; ++j)
            cout << a[i][j];
}


int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ":\n";
    read();
    kill();
    cerr << "Case #" << i << " done.\n";
  }
  return 0;
}
