#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main ()
{
  string w;
  int count;

  cin >> w;

  for (char x : w) {
    for (int i = 0; i < w.length(); i++) {
      if (x == w[i]) {
        count++;
      }
    }
    if (count % 2 != 0) break;
  }
  if (count % 2 != 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}