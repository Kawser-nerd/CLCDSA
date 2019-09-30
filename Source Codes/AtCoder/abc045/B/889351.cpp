#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>
#include "math.h"

using namespace std;
int main(int argc, char const *argv[]) {
  vector<string> s;
  int index[3];
  string a;
  for (size_t i = 0; i < 3; i++) {
    cin >> a;
    s.push_back(a);
    index[i] = 0;
  }
  int j = 0;
  string t;
  while(index[j] < s[j].size()) {
    t = s[j][index[j]];
    index[j]++;
    if (t == "a") {
      j = 0;
    } else if (t == "b") {
      j = 1;
    } else {
      j = 2;
    }
  }
  transform(t.begin(), t.end(), t.begin(), ::toupper);
  cout << t << endl;
  return 0;
}