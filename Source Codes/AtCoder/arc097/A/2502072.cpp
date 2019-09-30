#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;

  int a;
  cin >> a;

  string rank[5];
  for (int i = 0; i < 5; i++) {
    rank[i] = "";
  }

  int cnt = 0;
  for (int i = 0; i < s.length(); i++) {
    bool flag = false;
    for (int j = 1; j <= s.length() - i; j++) {
      auto ss = s.substr(i, j);
      for (int k = 0; k < 5; k++) {
        if (ss == rank[k]) goto next;
        if (rank[k] == "" || ss < rank[k]) {
          for (int l = 4; k < l; l--) {
            rank[l] = rank[l - 1];
          }
          rank[k] = ss;
          goto next;
        }
      }
      flag = true;
    next:
      if (flag) break;
    }
  }

  cout << rank[a - 1] << endl;
}