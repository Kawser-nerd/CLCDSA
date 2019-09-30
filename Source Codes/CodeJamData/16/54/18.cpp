#include <bits/stdc++.h>

using namespace std;

const int M = 120;

int n, l;
string s[M], b;


void read() {
  cin >> n >> l;
  for (int i = 0; i < n; ++i)
    cin >> s[i];
  cin >> b;
}

int ex(int x) {
  return x ^ 1;
}

void kill() {
  for (int i = 0; i < n; ++i)
    if (s[i] == b) {
      cout << "IMPOSSIBLE\n";
      return;
    }

  for (int i = 0; i < l; ++i) {
    int x = b[i] - '0';
    cout << ex(x) << "?";
  }
  cout << " ";

  for (int i = 0; i < l; ++i) {
    int x = b[i] - '0';
    cout << ex(x);
    if (i != l - 1)
      cout << x;
  }
  cout << endl;
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
