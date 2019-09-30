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

int main()
{
  ll N;
  cin >> N;
  vector<ll> as(N);
  vector<ll> memo(N);
  for (auto i = 0; i < N; i++) {
    cin >> as[i];
  }

  memo[N-2] = abs(as[N-1]-as[N-2]);
  for (auto i = N-3; i >= 0; i--) {
    memo[i] = min(memo[i+1] + abs(as[i]-as[i+1]), memo[i+2] + abs(as[i]-as[i+2]));
  }

  cout << memo[0] << endl;

  return 0;
}