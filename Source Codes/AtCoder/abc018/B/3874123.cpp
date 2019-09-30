#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  for (int i=0; i<n; ++i) {
    int l, r;
    cin >> l >> r;
    string tmp = s.substr(l-1, r-l+1);
    reverse(tmp.begin(), tmp.end());
    for (int i=l-1; i<r; ++i) {
      s[i] = tmp[i-l+1];
    }
  }
  cout << s << endl;
  return 0;
}