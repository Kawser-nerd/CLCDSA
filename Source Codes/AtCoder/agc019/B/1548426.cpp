#include <iostream>
using namespace std;

int main() {
  string a;
  cin >> a;
  int64_t n = a.length();
  int64_t answer = 1 + n * (n - 1) / 2;
  for (char c = 'a'; c <= 'z'; c++) {
    int64_t ct = 0;
    for (int32_t i = 0; i < n; i++) {
      if (a.at(i) == c) {
        ct++;
      }
    }
    answer -= (ct * (ct - 1)) / 2;
  }
  cout << answer << endl;
  return 0;
}