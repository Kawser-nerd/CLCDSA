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

vector<int> perm;
bool adj1[20][20], adj2[20][20];

int main() {
  int C;
  scanf("%d", &C);
  for (int t = 1; t <= C; t++) {
    int N;
    scanf("%d", &N);

    memset(adj1, 0, sizeof(adj1));
    memset(adj2, 0, sizeof(adj2));

    rep (i, N - 1) {
      int a, b;
      scanf("%d%d", &a, &b);
      a--; b--;
      adj1[a][b] = adj1[b][a] = true;
    }

    int M;
    scanf("%d", &M);

    rep (i, M - 1) {
      int a, b;
      scanf("%d%d", &a, &b);
      a--; b--;
      adj2[a][b] = adj2[b][a] = true;
    }

    perm = vector<int>(N);
    rep (i, N) perm[i] = i;

    bool ok = false;
    do {
      rep (i, M) {
        int v = perm[i];
        rep (j, M) {
          int w = perm[j];
          if (adj1[v][w] != adj2[i][j]) goto dmp;
        }
      }
      ok = true;
    dmp:
      ;
      
    } while (next_permutation(all(perm)));

    printf("Case #%d: %s\n", t, ok ? "YES" : "NO");
  }
}

