#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
#include <map>
#include <sstream>
#include <unordered_map>
#include <set>

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
static ull tenq = 1000000000;
static ull mod = tenq + 7;

using namespace std;

template<typename T>
T gcd(T a, T b) {
  if (a > b) {
    T tmp = b;
    b = a;
    a = tmp;
  }
  while (a > 0){
    T tmp = b % a;
    b = a;
    a = tmp;
  }
  return b;
}

template<typename T>
T lcm(T a, T b) {
  return a / gcd<T>(a, b) * b;
}


int main()
{
  ll N;
  cin >> N;
  vector<ll> as(N);
  for (auto i = 0; i < N; i++) cin >> as[i];
  ll res = as[0];
  for(auto i = 1; i < N; i++) {
    res = gcd(res, as[i]);
  }

  cout << res << endl;

  return 0;
}