#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int worstd[1010], bestd[1010];
vector<vector<int> > A, B, C;

main() {
  int T, N, M, P, prob=1;
  for (cin >> T; T--;) {
    cin >> N >> M >> P;
    A = B = C = vector<vector<int> >(N+1);
    vector<int> ru(M+1), rv(M+1), ra(M+1);
    for (int i = 0; i < M; i++) {
      int u, v, a, b;
      cin >> u >> v >> a >> b;
      ru[i+1] = u; rv[i+1] = v; ra[i+1] = a;
      C[u].push_back(v);
      A[u].push_back(a);
      B[u].push_back(b);
    }
    vector<int> pv(P);
    for (int i = 0; i < P; i++) cin >> pv[i];

    int curcity = 1, curd = 0, p;
    for (int i = 1; i <= N; i++) worstd[i] = 1000000001;
    for (p = 0; p < P; p++) {
      priority_queue<pair<int, int> > q;
      q.push(make_pair(-curd, curcity));
      while (!q.empty()) {
        int d = -q.top().first, c = q.top().second;
        q.pop();
        if (worstd[c] <= d) continue;
        worstd[c] = d;
        for (int i = 0; i < C[c].size(); i++)
          q.push(make_pair(-d-B[c][i], C[c][i]));
      }
//for (int i = 1; i <= N; i++) cout << ' ' << i << ":" << worstd[i];
//cout << endl;

      assert(curcity == ru[pv[p]]);
      curcity = rv[pv[p]];
      curd += ra[pv[p]];

      for (int i = 1; i <= N; i++) bestd[i] = worstd[i]+1;
      q.push(make_pair(-curd, curcity));
      bool found = false;
      while (!q.empty()) {
        int d = -q.top().first, c = q.top().second;
        q.pop();
        if (bestd[c] <= d) continue;
        bestd[c] = d;
        if (c == 2) found = true;
        for (int i = 0; i < C[c].size(); i++)
          q.push(make_pair(-d-A[c][i], C[c][i]));
      }
//for (int i = 1; i <= N; i++) cout << ' ' << i << ":" << bestd[i];
//cout << endl;
//cout << endl;

      if (!found) break;
    }

    cout << "Case #" << prob++ << ": ";
    if (p == P) {
      cout << "Looks Good To Me" << endl;
    } else {
      cout << pv[p] << endl;
    }
  }
}
