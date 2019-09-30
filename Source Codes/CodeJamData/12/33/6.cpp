#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int T, N, A[110], B[110], M;
long long a[110], b[110];
typedef pair< pair<int, int>, pair<pair<int, long long>, pair<int, long long> > > State;
map<State, long long> dp;

long long calc(int x, int y, int resXType, long long resXCount, int resYType, long long resYCount) {
  State s = make_pair(make_pair(x,y), make_pair(make_pair(resXType, resXCount), make_pair(resYType, resYCount)));
  if (dp.find(s) != dp.end())
    return dp[s];
  
  if (x>0 && (resXCount == 0 || resXType == A[x-1])) {
    x--;
    resXType = A[x];
    resXCount += a[x];
  }
  if (y>0 && (resYCount == 0 || resYType == B[y-1])) {
    y--;
    resYType = B[y];
    resYCount += b[y];
  }
  if (resXCount == 0 && x == 0 || resYCount == 0 && y == 0) 
    return 0;
  
  if (resXType == resYType) {
    long long produced = min(resXCount, resYCount);
    return dp[s] = calc(x, y, resXType, resXCount - produced, resYType, resYCount - produced) + produced;
  }
  
  return dp[s] = max(calc(x, y, resXType, 0, resYType, resYCount), calc(x, y, resXType, resXCount, resYType, 0));
}

int main() {
  scanf("%d", &T);
  for (int ttt=1; ttt<=T; ttt++) {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
      scanf("%lld %d", a+i, A+i);
    }
    for (int i=0; i<M; i++) {
      scanf("%lld %d", b+i, B+i);
    }
    dp.clear();
    printf("Case #%d: %lld\n", ttt, calc(N,M,0,0,0,0));
  }
}