#include<cstdio>
#include<algorithm>
using namespace std;
using LL = long long;
LL N, M, S;
LL A[50];
inline LL ceil(LL d, LL n) {return (d+n-1)/n;}
inline bool ok(LL x) {
  if(M < S-x) return false;
  LL s = 0;
  for(auto i=0; i<N; ++i) s += max(0ll, ceil(A[i]+x+1-N, N+1));
  return s <= x;
}
int main() {
  scanf("%lld", &N);
  M=N*(N-1);
  for(auto i=0; i<N; ++i) scanf("%lld", A+i), S+=A[i];
  LL l = -1, h = 1e18;
  while(l+1 < h) {
    LL m = (l+h)>>1;
    if(ok(m)) h = m;
    else      l = m;
  }
  for(auto x=max(0ll,h-N*N); x<=h; ++x) if(ok(x)) {
    printf("%lld\n",x);
    break;
  }
}