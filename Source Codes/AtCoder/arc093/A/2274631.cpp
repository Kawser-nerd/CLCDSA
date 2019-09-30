#include<algorithm>
#include<cmath>
#include<cstdint>
#include<cstdio>
#include<functional>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;

#define loop(i,a,b) for(int i=(a); i<(b); ++i)
#define rep(i,n) for(int i=0; i<n; ++i)
#define all(v) begin(v), end(v)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const double PI = acos(-1.0);

int main() {
  std::ios::sync_with_stdio(false);

  int n, sum = 0;
  cin >> n;
  n+=2;
  vector<int> A(n);
  rep(i,n-2) cin >> A[i+1];
  rep(i,n-1) sum += abs(A[i+1] - A[i]);
  rep(i,n-2) cout << sum - (abs(A[i] - A[i+1]) + abs(A[i+1] - A[i+2])) + abs(A[i] - A[i+2]) << endl;

  return 0;
}