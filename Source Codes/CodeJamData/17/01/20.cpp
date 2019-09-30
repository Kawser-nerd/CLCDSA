#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  int numCases;
  cin >> numCases;
  for (int testCase=1; testCase<=numCases; ++testCase) {
    cout << "Case #" << testCase << ": ";
    string s;
    int k;
    cin >> s >> k;
    bool valid = true;
    int ans = 0;
    for (int i=0; i<s.size(); ++i) {
      if (s[i] == '-') {
        if (i+k > s.size())
          valid = false;
        else {
          ans++;
          for (int j=i; j<i+k; ++j) {
            s[j] = '+'+'-'-s[j];
          }
        }
      }
    }
    if (!valid)
      cout << "IMPOSSIBLE" << endl;
    else
      cout << ans << endl;
  }
}