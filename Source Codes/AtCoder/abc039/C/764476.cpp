#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  string s;
  string wb = "WBWBWWBWBWBW";
  string scale[12] = {"Do", "", "Re", "", "Mi", "Fa", "", "So", "", "La", "", "Si"};
  cin >> s;
  for (int i = 0; i < 12; ++i) {
    if (s == (wb + wb + wb).substr(i, 20)) {
      cout << scale[i] << endl;
    }
  }
  return 0;
}