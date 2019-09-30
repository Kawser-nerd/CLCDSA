#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string s; cin >> s;
  vector<char> cv;
  char ans = '\0';

  for (int i = 0; i < s.length(); i++) {
    char x = s[i];
    cv.push_back(x);
  }

  sort(cv.begin(), cv.end());
  cv.erase(unique(cv.begin(), cv.end()), cv.end());

  for (int i = 0; i < 26; i++) {
    int asc = 97 + i;
    if (cv[i] != asc) {
      ans = asc;
      break;
    }
  }

  if (ans == '\0') cout << "None" << endl;
  else             cout << ans << endl;

  return 0;
}