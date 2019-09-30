#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;

  int k;
  cin >> k;

  vector<string> list;
  for (int i = 0; i < s.length(); i++) {
    for (int j = 1; j + i <= s.length() && j <= 5; j++) {
      list.push_back(s.substr(i, j));
    }
  }
  sort(list.begin(), list.end());
  list.erase(unique(list.begin(), list.end()), list.end());

  cout << list[k - 1] << endl;
}