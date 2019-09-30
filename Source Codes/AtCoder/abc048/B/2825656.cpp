#include <iostream>

using std::cin;
using std::cout;
using std::endl;

long long x;

long long count(long long n) {
  long long sum = 0;
  if (n != -1) sum = n / x + 1;
  else sum = 0;
  return sum;
}

int main() {
  long long a, b;

  cin >> a >> b >> x;

  cout << (count(b) - count(a - 1)) << endl;

  return 0;
}