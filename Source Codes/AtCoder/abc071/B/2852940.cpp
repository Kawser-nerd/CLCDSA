#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string s; cin >> s;
  vector<char> cv;
  char ans;
  bool flag = true;

  for (int i = 0; i < s.length(); i++) {
    char x = s[i];
    cv.push_back(x);
  }

  sort(cv.begin(), cv.end());
  cv.erase(unique(cv.begin(), cv.end()), cv.end());

  for (int i = 0; i < 26; i++) {
    // cout << cv[i] << endl;
    int asc = 97 + i;
    if (cv[i] != asc) {
      ans = asc;
      flag = false;
      break;
    }
  }

  if (flag) cout << "None" << endl;
  else      cout << ans << endl;

  return 0;
}