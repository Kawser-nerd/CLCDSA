#pragma optimization_level 3
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int N;

long long M;
vector<int> p1, p2;
map<long long, int> T;

bool is_prime(long long x) {
  for (int i=2; i<=sqrt(x); i++) {
    if (x % i == 0) return false;
  }
  return true;
}

long long norm(long long x) {
  for (int k : p1) {
    while (x % (k*k*k) == 0) x /= k*k*k;
  }
  return x;
}

long long inv(long long x) {
  long long ret = 1;
  for (int k : p1) {
    int c = 0;
    while (x % k == 0) x /= k, c++;
    if (c > 0) {
      while (++c <= 3) {
        ret *= k;
        if (ret > M) return -1;
      }
    }
  }
  if (x == 1) return ret;

  // - p1^2  -> p1
  long long rt = sqrt(x);
  if (rt*rt == x) {
    ret *= rt;
    return ret>M?-1:ret;
  }

  auto it = lower_bound(p2.begin(), p2.end(), x);
  // - p1*p2 -> -1
  if (it == p2.end() || *it != x) return -1;
  // - p1 -> p1^2
  ret *= x; if (ret > M) return -1;
  ret *= x; if (ret > M) return -1;
  return ret;
}

int main() {
  cin >> N;
  for (int i=2; i<=2154; i++) {
    if (is_prime(i)) p1.push_back(i);
  }
  for (int i=2155; i<=100000; i++) {
    if (is_prime(i)) p2.push_back(i);
  }

  bool one = false;
  for (int i=0; i<N; i++) {
    long long s; cin >> s;
    long long n = norm(s);
    M = max(M, n);
    if (n == 1) one = true;
    else T[n]++;
  }

  int c = 0;
  for (auto p : T) {
    long long s = p.first;
    if (T[s] == 0) continue;
    long long v = inv(s);
    if (v == -1) c += p.second;
    else {
      c += max(T[v], p.second);
      T[v] = 0;
    }
  }
  cout << c + one << "\n";
  return 0;
}