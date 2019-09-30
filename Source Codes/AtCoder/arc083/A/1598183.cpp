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
int A,B,C,D,E,F;
const int MAX_F = 3010;

int f(int sugar){
  int left = 0;
  int right = MAX_F;
  while (right - left > 1){
    int med = (right + left) / 2;
    int res = D * med;
    if (res <= sugar){
      left = med;
    }else{
      right = med;
    }
  }
  return left;
}


int main() {
  cin >> A >> B >> C >> D >> E >> F;
  double result = 0;
  int res1,res2;
  res1 = 100 * A;
  res2 = 0;
  for (int i = 0; i < MAX_F; i++){
    if (100 * A * i > F)break;
      for (int j = 0; j < MAX_F; j++){
        if (100 * A * i + 100 * B * j > F)break;
        int water = 100 * A  * i + 100 * B * j;
        if (water == 0)continue;
        for (int k = 0; k < MAX_F; k++){
          int sugar = min(F - water, E * water / 100);
          if (k * C > sugar)break;
          int l = f(sugar - k * C);
          double tmp = (double)100 * (k * C + l * D) / (k * C + l * D + water);
          if (tmp > result){
            result = tmp;
            // cerr << "result = " << result << endl;
            res1 = water + k * C + l * D;
            res2 = k * C + l * D;
          }
        }
    }
  }
  cout << res1 << " " << res2 << endl;
  return 0;
}