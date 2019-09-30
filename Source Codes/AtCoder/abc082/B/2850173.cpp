#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  vector<char> s;
  vector<char> t;
  string a, b;
  cin >> a;
  cin >> b;

  bool ans = false;

  for (char x : a) {
    s.push_back(x);
  }
  for (char x : b) {
    t.push_back(x);
  }

  sort(s.begin(), s.end());
  sort(t.begin(), t.end(), greater<char>());

  for (int i = 0; i < b.length(); i++) {
    if (s[i] < t[i]) {
      ans = true;
      break;
    } else if (s[i] > t[i]) {
      break;
    }
  }

  // for (char x : s) {
  //   cout << x;
  // }
  // cout << "" << endl;
  //
  // for (char x : t) {
  //   cout << x;
  // }
  // cout << "" << endl;

  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}