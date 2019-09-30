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

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
static ull tenq = 1000000000;
static ull mod = tenq + 7;

using namespace std;

int main()
{
  ll N;
  cin >> N;
  vector<ll> rates(9, 0);

  for (auto i = 0; i < N; i++) {
    ll x;
    cin >> x;
    ll rate = 8;
    for (auto j = 0; j < 8; j++) {
      if (j * 400 <= x && x < (j+1) * 400) {
        rate = j;
        break;
      }
    }
    rates[rate]++;
  }

  ll n = 0;
  ll c = rates[8];
  for (auto i = 0; i < 8; i++) {
    if (rates[i] > 0) n++;
  }
//  cout << "n=" << n << " c=" << c << endl;
  cout << max(1LL, n) << " " << n + c << endl;

//  ll minv = 0;
//  ll maxv = 0;
//  for (auto i = 0; i < 8; i++) {
//    if (rates[i] == 0 && rates[8] > 0) {
//      maxv++;
//      rates[8]--;
//    } else if (rates[i] > 0) {
//      minv++;
//      maxv++;
//    }
//  }
//
//  cout << (minv == 0 ? 1 : minv) << " " << maxv << endl;

  return 0;
}