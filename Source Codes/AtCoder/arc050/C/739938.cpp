#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

long long gcd(long long a, long long b) {
  while (b > 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}

long long pow(long long x, long long p, long long m) {
  long long y = 1;
  while (p > 0) {
    if (p % 2 > 0) {
      y = (y * x) % m;
    }
    x = x * x % m;
    p /= 2;
  }
  return y;
}

long long extract(long long x, long long w, long long n, long long m) {
  long long d = pow(10, w, m);
  long long y = 0;
  while (n > 0) {
    if (n % 2 > 0) {
      y = (y * d + x) % m;
    }
    x = (x * d + x) % m;
    d = d * d % m;
    n /= 2;
  }
  return y;
}

int main() {
  long long a, b, m, k;
  cin >> a >> b >> m;
  k = gcd(a, b);
  cout << extract(1, 1, a, m) * extract(1, k, b / k, m) % m << endl;
  return 0;
}