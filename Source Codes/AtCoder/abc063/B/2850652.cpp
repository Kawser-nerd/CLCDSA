#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string s; cin >> s;
  vector<char> sv;
  string ans = "yes";

  for (char x : s) sv.push_back(x);

  sort(sv.begin(), sv.end());
  for (int i = 0; i < sv.size(); i++) {
    if (sv[i + 1] == sv[i]) {
      ans = "no";
      break;
    }
  }

  cout << ans << endl;

  return 0;
}