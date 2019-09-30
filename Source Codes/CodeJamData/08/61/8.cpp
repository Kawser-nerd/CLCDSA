#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

#define all(c) ((c).begin()), ((c).end()) 
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end()) 
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long ll;

const int INF = 999999999;

int X[1010], Y[1010];
bool B[1010];

int main() {
  int C;
  scanf("%d", &C);

  for (int t = 1; t <= C; t++) {
    int N, M;
    scanf("%d ", &N);
    
    int xmi = INF, xma = -INF, ymi = INF, yma = -INF;

    rep (i, N) {
      string str, tmp;
      getline(cin, str);
      stringstream ss(str);
      ss >> X[i] >> Y[i] >> tmp;
      B[i] = (tmp == "BIRD");
      if (B[i]) {
        xmi = min(X[i], xmi); xma = max(X[i], xma);
        ymi = min(Y[i], ymi); yma = max(Y[i], yma);
      }
    }
    
    scanf("%d", &M);

    printf("Case #%d:\n", t);
    rep (i, M) {
      int x, y;
      scanf("%d%d", &x, &y);

      int txmi = xmi, txma = xma, tymi = ymi, tyma = yma;
      txmi = min(x, txmi); txma = max(x, txma);
      tymi = min(y, tymi); tyma = max(y, tyma);

      // mujun suru?
      bool bird = true;
      rep (j, N) {
        bool b = (txmi <= X[j] && X[j] <= txma && tymi <= Y[j] && Y[j] <= tyma);
        if (b != B[j]) bird = false;
      }
      
      bool notbird = !(xmi <= x && x <= xma && ymi <= y && y <= yma);

      if (bird && !notbird) {
        puts("BIRD");
      }
      else if (!bird && notbird) {
        puts("NOT BIRD");
      }
      else
        puts("UNKNOWN");

      /*
      if (xmi <= x && x <= xma) {
        if (ymi <= y && y <= yma) puts("BIRD");
        else {

          // ToDo
        }
      }
      else if (x < xmi) {
        int ymaa = INF, ymii = -INF;
        rep (j, N) {
          if (B[j]) continue;
          if (x <= X[j] && X[j] < xmi) {
            if (y <= Y[j]) 
          }
        }
      }
      */
    }
  }
}

