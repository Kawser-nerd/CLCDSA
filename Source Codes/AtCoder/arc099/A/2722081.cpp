#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <queue>
#include <numeric>
#include <stack>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int N, K;
  cin >> N >> K;
  vector<int> as(N);
  rep (i, N) cin >> as[i];

  int ans;// = (N) / (K-1);
  if (N==K) ans = 1;
  else ans = 1+ (N-K) / (K-1) + (((N-K)%(K-1)>0) ? 1 : 0);
  cout << ans << endl;

  return 0;
}