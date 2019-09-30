#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  int ans = 0;

  string temp;
  int a = s.size();
  int z = 0;
  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      if (i < a) a = i;
    }
    if (s[i] == 'Z') {
      if (i > z) z = i;
    }
  }
  cout << z - a + 1 << endl;
  return 0;
}