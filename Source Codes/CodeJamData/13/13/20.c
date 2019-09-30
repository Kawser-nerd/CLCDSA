#define DEBUG 1

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() {
  int tc, cn, i, j, R, N, M, K, a[12], best;
  set<int> s[126];
  double p[6][6][6], bestp;

  scanf("%d", &tc);
  for(cn = 1; cn <= tc; cn++) {
    scanf("%d%d%d%d", &R, &N, &M, &K);
    printf("Case #%d:\n", cn);
    for(a[0] = 2; a[0] <= M; a[0]++)
      for(a[1] = 2; a[1] <= M; a[1]++)
        for(a[2] = 2; a[2] <= M; a[2]++) {
          s[1].insert(a[0] * 100 + a[1] * 10 + a[2]);
          s[a[0]].insert(a[0] * 100 + a[1] * 10 + a[2]);
          s[a[1]].insert(a[0] * 100 + a[1] * 10 + a[2]);
          s[a[2]].insert(a[0] * 100 + a[1] * 10 + a[2]);
          s[a[0] * a[1]].insert(a[0] * 100 + a[1] * 10 + a[2]);
          s[a[0] * a[2]].insert(a[0] * 100 + a[1] * 10 + a[2]);
          s[a[1] * a[2]].insert(a[0] * 100 + a[1] * 10 + a[2]);
          s[a[0] * a[1] * a[2]].insert(a[0] * 100 + a[1] * 10 + a[2]);
        }

    while(R--) {  
      for(a[0] = 2; a[0] <= M; a[0]++)
        for(a[1] = 2; a[1] <= M; a[1]++)
          for(a[2] = 2; a[2] <= M; a[2]++)
            p[a[0]][a[1]][a[2]] = 1.0;
      for(i = 0; i < K; i++) {
        scanf("%d", &j);
        for(a[0] = 2; a[0] <= M; a[0]++)
          for(a[1] = 2; a[1] <= M; a[1]++)
            for(a[2] = 2; a[2] <= M; a[2]++)
              if(s[j].find(a[0] * 100 + a[1] * 10 + a[2]) == s[j].end())
                p[a[0]][a[1]][a[2]] = 0.0;
              else
                p[a[0]][a[1]][a[2]] /= s[j].size();
      }
      best = 222;
      bestp = 0.0;
        for(a[0] = 2; a[0] <= M; a[0]++)
          for(a[1] = 2; a[1] <= M; a[1]++)
            for(a[2] = 2; a[2] <= M; a[2]++)
              if(p[a[0]][a[1]][a[2]] > bestp) {
                best = a[0] * 100 + a[1] * 10 + a[2];
                bestp = p[a[0]][a[1]][a[2]];
              }
      printf("%d\n", best);
    }
  }
  return 0;
}
