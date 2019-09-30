#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

int N, F[1001], ans, l[1001];

bool valid(int i) {
  for(int j = 0; j < i; j++)
    if(F[l[j]] != l[(j + 1) % i] && F[l[j]] != l[(j + i - 1) % i])
      return false;
  return true;
}

int main() {
  int tc, cn, i;
  scanf("%d", &tc);
  for(cn = 1; cn <= tc; cn++) {
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
      scanf("%d", &F[i]);
      F[i]--;
      l[i] = i;
    }
    ans = 0;
    do {
      if(DEBUG) {
	for(i = 0; i < N; i++)
	  printf("%d ", l[i]);
	puts("");
      }
      for(i = max(ans + 1, 2); i <= N; i++) { //check up to i
	if(DEBUG)
	  printf("testing %d, ans = %d\n", i, ans);
	if(valid(i))
	  ans = i;
      }
    } while(next_permutation(l, l + N));
    printf("Case #%d: %d\n", cn, ans);
  }
}
