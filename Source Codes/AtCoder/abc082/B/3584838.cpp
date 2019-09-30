#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end(), greater<>());
  int slen = s.size();
  int tlen = t.size();
  for (int i = 0; i < min(slen, tlen); ++i) {
    if (s[i] == t[i]) continue;
    cout << (s[i] < t[i] ? "Yes\n" : "No\n");
    return 0;
  }
  if (slen < tlen) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}