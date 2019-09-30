#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// c++11
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#define mp make_pair
#define mt make_tuple
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1 << 29;
const double EPS = 1e-9;
const ll MOD = 1000000007;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int N;
const int MAX_N = 10000;
vector<ll> A;
ll sum[2];
bool del_values[MAX_N];
int main() {
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
    if (A[i] > 0){
      sum[i % 2] += A[i];
    }else{
      del_values[i] = true;
    }
  }
  ll result = max(sum[0], sum[1]);
  if (result == 0){
      int pos = max_element(A.begin(), A.end()) - A.begin();
      del_values[pos] = false;
      cout << A[pos] << endl;
  }else{
    for (int i = 0; i < N; i++){
      if (sum[i % 2] < sum[(i + 1) % 2]){
        del_values[i] = true;
      }
    }
    cout << result << endl;
  }
  vector<int> procedures;
  int r = N - 1;
  while (del_values[r]){
    procedures.push_back(r);
    r--;
  }
  int l = 0;
  while (del_values[l]){
    procedures.push_back(0);
    l++;
  }
  for (l += 2; l <= r; l += 2){
    procedures.push_back(del_values[l] ? 2 : 1);
  }
  cout << procedures.size() << endl;
  for (const auto &val : procedures){
    cout << val + 1 << endl;
  }
  return 0;
}