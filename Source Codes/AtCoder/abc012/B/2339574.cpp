#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  int n;
  int h, m, s;
  cin >> n;
  h = n / 3600;
  m = (n % 3600) / 60;
  s = n % 60;
  cout << setfill('0') << setw(2) << h << ":";
  cout << setfill('0') << setw(2) << m << ":";
  cout << setfill('0') << setw(2) << s << endl;
  return 0;
}