#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <tuple>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const llint inf = 2e18;

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp, fflush(stdout)) {
    char sa[22], sb[22];
    scanf("%s %s", sa, sb);
    string A = sa, B = sb;

    llint best = inf;
    string C, J;

    auto test = [&] (string A, string B) {
      llint diff = abs(stoll(A) - stoll(B));
      if (make_tuple(diff, A, B) < make_tuple(best, C, J))
        best = diff, C = A, J = B;
    };
    
    int n = A.size();
    REP(it, 2) {
      REP(j, n + 1) {
        string a = A, b = B;
        bool ok = true;
        REP(k, j) {
          if (a[k] == '?' && b[k] == '?') a[k] = b[k] = '0';
          else if (a[k] == '?') a[k] = b[k];
          else if (b[k] == '?') b[k] = a[k];
          else if (a[k] != b[k]) { ok = false; break; }
        }

        if (!ok) break;

        if (j == n) {
          if (it) test(b, a);
          else test(a, b);
          continue;
        }

        REP(db, 10) REP(da, db)
          if (a[j] == '?' || a[j] == '0' + da)
            if (b[j] == '?' || b[j] == '0' + db) {
              string na = a, nb = b;
              na[j] = '0' + da;
              nb[j] = '0' + db;
              FOR(k, j + 1, n) {
                if (na[k] == '?') na[k] = '9';
                if (nb[k] == '?') nb[k] = '0';
              }
              if (it) test(nb, na);
              else test(na, nb);
            }
          
      }
      REP(j, n) swap(A[j], B[j]);
    }
    
    printf("Case #%d: ", tp);
    printf("%s %s\n", C.c_str(), J.c_str());
  }
  return 0;
}
