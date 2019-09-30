#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/* PREWRITTEN CODE */

#define ALL(x) x.begin(),x.end()
#define PB push_back


#define FOR(i,p,k) for (int i=p; i<k; i++)
#define REP(i,n) for (int i=0; i<n; i++)
#define SIZE(x) (int)x.size()
/* COMPETITION CODE */
    
char buffer[100];    
int appears[300];    
int taken[300];    
int mapto[300];
    
int main() {
  int T;
  scanf("%d", &T);
  REP (tests, T) {
    scanf("%s", buffer);
    REP (i, 300) appears[i] = 0;
    int blen = 0; while(buffer[blen]) blen++;
    REP (i, blen) appears[(int)buffer[i]] = 1;
    int bas = 0;
    REP (i, 300) bas += appears[i];
    if (bas == 1) bas = 2;
    REP (i, 300) taken[i] = 0;
    REP (i, 300) mapto[i] = -1;
    long long tot = 0LL;
    REP (i, blen) {
      if (!i) {
        tot += 1LL;
        mapto[(int) buffer[i]] = 1;
        taken[1] = 1;
      } else {
        tot *= (long long) bas;
        if (mapto[(int) buffer[i]] == -1) {
          int best = 0;
          while (taken[best]) best++;
          mapto[(int) buffer[i]] = best;
          taken[best] = 1;
        }        
        tot += (long long) mapto[(int) buffer[i]];
      }
    }
    printf("Case #%d: %lld\n", tests+1, tot);
  }
  return 0;
}
