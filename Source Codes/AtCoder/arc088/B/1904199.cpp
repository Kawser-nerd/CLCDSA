#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
  string s;
  cin >> s;
  int res = s.size();
  for (int i = 0; i < s.size()-1; ++i) {
    if (s[i] != s[i+1])
        res = min(res, max(i+1, (int)s.size()-i-1));
  }
  cout << res << endl;
  return 0;
}