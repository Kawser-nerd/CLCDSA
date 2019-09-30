#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    cout << "Case #" << ta << ": ";
    string s;
    cin >> s;
    s += "+";
    int ans=0;
    for (int i=1; i<s.size(); ++i) {
      if (s[i-1] != s[i])
        ans++;
    }
    cout << ans << endl;
  }
}