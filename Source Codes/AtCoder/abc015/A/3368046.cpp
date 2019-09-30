#include <iostream>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  if (a.size() > b.size()) {
    cout << a;
  } else {
    cout << b;
  }
  cout << endl;
}