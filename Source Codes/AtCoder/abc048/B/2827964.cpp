#include <iostream>

using namespace std;

int main() {
  long long a, b, x;
  cin >> a >> b >> x;
  long long r = b / x + 1;
  long long l = 0;
  if (a != 0) {
    l = (a-1) / x + 1;
  }
  long long count = r - l;
  //cout << r << "," << l << endl;
  cout << count << endl;
}