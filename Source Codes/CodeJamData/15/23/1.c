#define DEBUG 1

#include "../../stdc++.h"
using namespace std;

int main() {
  long long cn, tc, N, D[2], M[2], H, ans;
  scanf("%lld", &tc);
  for(cn = 1; cn <= tc; cn++) {
    scanf("%lld", &N);
    if(N == 1) {
      scanf("%lld%lld%lld", &D[0], &H, &M[0]);
      if(H == 2)
	N = 2, D[1] = D[0], M[1] = M[0] + 1;
    } else {
      scanf("%lld%lld%lld", &D[0], &H, &M[0]);
      scanf("%lld%lld%lld", &D[1], &H, &M[1]);
    }
    if(N == 1)
      ans = 0;
    else if(M[0] == M[1])
      ans = 0;
    else {
      if(M[0] < M[1]) {
	swap(M[0], M[1]);
	swap(D[0], D[1]);
      }
      //M[1] is now faster, go as fast as M[1]
      if((360 - D[0]) * M[0] < (720 - D[1]) * M[1])
	ans = 0;
      else
	ans = 1;
    }
    printf("Case #%lld: %lld\n", cn, ans);
  }
  return 0;
}
