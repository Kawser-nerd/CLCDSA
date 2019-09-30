#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstdio>

using namespace std;

#define MAXN 110
#define INF 0x3FFFFFFFFFFFFFFFLL;

int HE[MAXN];
int HS[MAXN];

long long D[MAXN][MAXN];

double D2[MAXN][MAXN];

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
      cin >> HE[i] >> HS[i];
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> D[i][j];
        if (i == j) {
          D[i][j] = 0;
        } else if (D[i][j] == -1) {
          D[i][j] = INF;
        }
      }
    }
    for (int k = 0; k < N; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
        }
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (D[i][j] <= HE[i]) {
          D2[i][j] = 1.0 * D[i][j] / HS[i];
        } else {
          D2[i][j] = 1e300;
        }
      }
    }

    for (int k = 0; k < N; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          D2[i][j] = min(D2[i][j], D2[i][k] + D2[k][j]);
        }
      }
    }

    cout << "Case #" << t << ":";
    for (int i = 0; i < Q; i++) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      printf(" %.9f", D2[u][v]);
    }
    cout << endl;
  }
  return 0;
}
