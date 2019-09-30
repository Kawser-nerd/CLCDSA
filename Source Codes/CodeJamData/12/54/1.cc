#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int K, c[128][128];

char replace(char ch) {
  if (ch == 'o') return '0';
  if (ch == 'i') return '1';
  if (ch == 'e') return '3';
  if (ch == 'a') return '4';
  if (ch == 's') return '5';
  if (ch == 't') return '7';
  if (ch == 'b') return '8';
  if (ch == 'g') return '9';
  return 0;
}

main() {
  int T, prob=1;

  for (cin >> T; T--;) {
    string S;
    cin >> K >> S;
    memset(c, 0, sizeof(c));
    for (int i = 0; i+1 < S.size(); i++) {
      c[S[i]][S[i+1]] = true;
      c[replace(S[i])][S[i+1]] = true;
      c[S[i]][replace(S[i+1])] = true;
      c[replace(S[i])][replace(S[i+1])] = true;
    }
    int ret = 0, ins = 0;
    for (int i = 1; i < 128; i++) {
      int deg = 0;
      for (int j = 1; j < 128; j++) if (c[i][j]) ret++;
      for (int j = 1; j < 128; j++) if (c[i][j]) deg++;
      for (int j = 1; j < 128; j++) if (c[j][i]) deg--;
      if (deg > 0) ins += deg;
    }
    if (ins == 0) ins = 1;
    cout << "Case #" << prob++ << ": " << ret+ins << endl;
  }
}
