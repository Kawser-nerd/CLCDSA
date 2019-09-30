#include <iostream>
#include <string>
using namespace std;
int main() {
  string a;
  cin >> a;
  if (a == "a")
    a = "-1";
  else if (a.size() >= 2)
    a.pop_back();
  else
    a[0] -= 1;
  cout << a;
}