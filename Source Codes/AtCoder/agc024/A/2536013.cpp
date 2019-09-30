#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <set>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;



#define LOCAL 1

#define pv(val) cerr << #val << " = " << (val) << endl
#define pvn(name, val) cerr << name << " = " << (val) << endl
#define pl cerr << '@' << __LINE__ << endl

template <class T>
ostream& operator<<(ostream& os, vector<T> const& vec) {
  if (vec.empty()) {
    os << "{}";
  } else {
    os << '{';
    for (size_t i = 0; i < vec.size() - 1; i++) os << vec[i] << ", ";
    os << vec.back() << '}';
  }
  return os;
}

template <class T, size_t S>
ostream& operator<<(ostream& os, array<T, S> const& arr) {
  if (arr.empty()) {
    os << "{}";
  } else {
    os << '{';
    for (size_t i = 0; i < arr.size() - 1; i++) os << arr[i] << ", ";
    os << arr.back() << '}';
  }
  return os;
}

template <class T, class U>
ostream& operator<<(ostream& os, pair<T, U> const& p) {
  os << '(' << p.first << ", " << p.second << ')';
  return os;
}

template <class T, class U>
pair<T, U> operator+(pair<T, U> const& lhs, pair<T, U> const& rhs) {
  return {lhs.first + rhs.first, lhs.second + rhs.second};
}

template <class T, class U>
pair<T, U> operator-(pair<T, U> const& lhs, pair<T, U> const& rhs) {
  return {lhs.first - rhs.first, lhs.second - rhs.second};
}

template <class T, class U>
U lowerBound(function<T(U)> f, T const& val, U l, U r) {
  while (l < r) {
    auto m = l + (r - l) / 2;
    auto fm = f(m);
    if (fm < val) {
      l = m;
    } else {
      r = m;
    }
  }
}

int main(void) {
  int64_t A, B, C, K;
  cin >> A >> B >> C >> K;

  if(abs(A - B) > 1e18) cout << "Unfair" << endl;
  else cout << ((K % 2 == 0) ? (A - B) : (B - A)) << endl;

  return 0;
}