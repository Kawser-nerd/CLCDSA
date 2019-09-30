#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  string w;
  cin >> w;

  map<char, int> count;
  for (auto s : w) {
    count[s] += 1;
  }
  for (auto itr = count.begin(); itr != count.end(); itr++) {
    if (itr->second % 2 == 1) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}