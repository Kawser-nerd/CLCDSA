#include <iostream>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  int slen = S.length();
  int tlen = T.length();
  for (int i{slen - tlen}; i >= 0; --i) {
    bool bingo{true};
    for (int j{}; j < tlen; ++j) {
      if (S[i + j] == '?')
        continue;
      if (S[i + j] != T[j]) {
        bingo = false;
        break;
      }
    }
    if (bingo) {
      for (int k{}; k < i; ++k) {
        if (S[k] == '?') {
          S[k] = 'a';
        }
      }
      S.replace(i, tlen, T);
      for (int k{i + tlen}; k < slen; ++k) {
        if (S[k] == '?') {
          S[k] = 'a';
        }
      }
      cout << S << endl;
      return 0;
    }
  }

  cout << "UNRESTORABLE" << endl;
  return 0;
}