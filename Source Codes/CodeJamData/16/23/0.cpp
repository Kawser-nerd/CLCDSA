#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 1010;

vector<int> E[MAX];

int dad[MAX];
int bio[MAX], cookie;
  
bool match(int x) {
  if (x == -1) return true;
  if (bio[x] == cookie) return false;
  bio[x] = cookie;
  for (int y: E[x])
    if (match(dad[y])) {
      dad[y] = x;
      return true;
    }
  return false;
}

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp, fflush(stdout)) {
    int N;
    scanf("%d", &N);

    map<string, int> MA, MB;
    REP(i, N) {
      static char A[22];
      static char B[22];
      scanf("%s %s", A, B);

      if (!MA.count(A)) {
        int idx = MA.size();
        MA[A] = idx;
      }
      if (!MB.count(B)) {
        int idx = MB.size();
        MB[B] = idx;
      }

      E[MA[A]].push_back(MB[B]);
    }

    int NA = MA.size();
    int NB = MB.size();

    REP(i, NB) dad[i] = -1;
    int matching = 0;
    REP(i, NA) {
      cookie++;
      matching += match(i);
    }
    
    int ans = N - (NA + NB - matching);
    printf("Case #%d: ", tp);
    printf("%d\n", ans);
    
    REP(i, NA) E[i].clear();
  }
  return 0;
}
