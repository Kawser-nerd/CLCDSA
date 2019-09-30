#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ALL(a)  (a).begin(),(a).end()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define dump(x)  cerr << #x << " = " << (x) << endl;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) {
    cin >> A[i];
  }
  
  vector<int> wrap(1e5);
  int res = 1;
  int start=0, end=1;
  for(; start<N; ++start) {
    while (end<N+1 && wrap[A[end-1]-1] == 0) {
      wrap[A[end-1]-1]++;
      end++;
    }
    res = max(res, end - start - 1);
    wrap[A[start]-1]--;
  }

  cout << res << endl;

  return 0;
}