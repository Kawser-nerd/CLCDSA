#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string s; cin >> s;
  vector<char> sv;
  bool flag = true;
  int s_len = s.length();

  for (char x : s) sv.push_back(x);

  // sort??
  sort(sv.begin(), sv.end());
  for (int i = 0; i < sv.size(); i++) {
    if (sv[i + 1] == sv[i]) {
      flag = false;
      break;
    }
  }

  if (flag) cout << "yes" << endl;
  else      cout << "no" << endl;

  return 0;
}