#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s;
  string t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    s.push_back(t);
  }

  int cnt = 0;
  bool flag;
  for (int i = 0; i < n; i++) {
    flag = true;
    for (int j = 0; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        if (s[j][(k+i)%n] != s[k][(j+i)%n]) {
          flag = false;
          break;
        }
      }
      if (!flag) {
        break;
      }
    }
    if (flag) {
      cnt += 1;
    }
  }

  cout << cnt*n << endl;

  return 0;
}