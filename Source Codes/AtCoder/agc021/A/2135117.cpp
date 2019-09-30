/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-24 20:50:09
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>   // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set>
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

ll N;

int main()
{
  cin >> N;
  string X = to_string(N);
  bool all_nine = true;
  for (auto x : X)
  {
    if (x != '9')
    {
      all_nine = false;
      break;
    }
  }
  int ans = 0;
  for (auto x : X)
  {
    ans += x - '0';
  }
  int tans = 0;
  if (all_nine)
  {
    for (auto x : X)
    {
      tans += 9;
    }
  } else {
    int s = X.size();
    for (auto i = 0; i < s; i++)
    {
      if (i == 0)
      {
        tans += X[i] - '0' - 1;
      } else {
        tans += 9;
      }
    }
  }
  cout << max(ans, tans) << endl;
  return 0;
}