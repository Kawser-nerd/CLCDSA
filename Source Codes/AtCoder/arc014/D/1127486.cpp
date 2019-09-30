// This template is based on http://ctylim.hatenablog.com/entry/2015/08/30/191553, provided by ctylim.
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <utility>

#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define mrepd(i,a,b) for (int i=(b-1);i>=(a);i--)
#define rep(i,n) repd(i,0,n)
#define mrep(i,n) mrepd(i,0,n)
#define LL long long
#define MOD 1000000007
using namespace std;

template <typename T>
void show_array(T arr[]) {
  rep(i, sizeof(*arr)/sizeof(arr[0])) cout << arr[i] << ' ';
  cout << endl;
}


template <typename T>
void show_vec(vector<T> vec) {
  rep(i, vec.size()) cout << vec[i] << ' ';
  cout << endl;
}

bool debug_mode = false;

int main() {
  int all, N, M;
  cin >> all >> N >> M;
  int x, y;
  vector<int> L(N);
  vector<int> D(N-1), D_sum(N);
  rep(i, N) cin >> L[i];
  rep(i, N-1) D[i] = L[i+1] - L[i] - 1;
  sort(D.begin(), D.end());
  D_sum[0] = 0;
  rep(i, N-1) D_sum[i+1] = D[i] + D_sum[i];

  // answer
  // cout << "D_sum[d]"  << ' ' <<  "(N - 1 - d) * (x + y)"  << ' ' <<  "min(x, L[0]-1)" << ' ' <<  "min(y, all - L[N-1])" << endl;
  int d, sum;
  rep(i, M) {
    cin >> x >> y;
    d = distance(D.begin(), lower_bound(D.begin(), D.end(), x+y));
    sum = D_sum[d] + (N - 1 - d) * (x + y) + min(x, L[0]-1) + min(y, all - L[N-1]) + N;
    // cout << D_sum[d]  << ' ' <<  (N - 1 - d) * (x + y)  << ' ' <<  min(x, L[0]-1) << ' ' <<  min(y, all - L[N-1]) << endl;
    cout << sum << endl;
  }
  return 0;
}