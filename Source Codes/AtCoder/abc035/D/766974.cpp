#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

typedef long long ll;
typedef tuple<ll, int> pass;
typedef tuple<ll, int> state;
const ll infty = 100000000000000;

vector<pass> V[2][100010];

int main() {
  int N, M;
  ll T;
  cin >> N >> M >> T;
  ll A[100010];
  for (auto i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (auto i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    V[0][a].push_back(make_tuple(c, b));
    V[1][b].push_back(make_tuple(c, a));
  }
  ll minimum[2][100010];
  fill(&minimum[0][0], &minimum[0][0]+2*100010, infty);
  for (auto k = 0; k < 2; k++) {
    priority_queue<state, vector<state>, greater<state> > Q;
    Q.push(make_tuple(0, 0));
    while(!Q.empty()) {
      ll cost = get<0>(Q.top());
      int src = get<1>(Q.top());
      Q.pop();
      if (minimum[k][src] == infty) {
        minimum[k][src] = cost;
        //cerr << "minimum[" << k << "][" << src << "] = " << cost << endl;
        for (auto x : V[k][src]) {
          ll c = get<0>(x);
          int dst = get<1>(x);
          if (minimum[k][dst] == infty) {
            Q.push(make_tuple(cost + c, dst));
          }
        }
      }
    }
  }
  ll hunt[100010];
  fill(hunt, hunt+100010, 0);
  for (auto i = 0; i < N; i++) {
    ll time = T - minimum[0][i] - minimum[1][i];
    if (time <= 0) continue;
    hunt[i] = time * A[i];
  }
  ll ans = 0;
  for (auto i = 0; i < N; i++) {
    ans = max(ans, hunt[i]);
  }
  cout << ans << endl;
}