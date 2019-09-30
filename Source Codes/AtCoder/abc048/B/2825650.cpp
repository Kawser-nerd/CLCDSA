#include <iostream>

using std::cin;
using std::cout;
using std::endl;

long long x;

long long f(long long n) {
  long long sum = 0;
  if (n != -1) sum = n / x + 1;
  else sum = 0;
  return sum;
}

int main() {
  long long a, b, ans;

  cin >> a >> b >> x;

  ans = f(b) - f(a - 1);

  cout << ans << endl;

  return 0;
}