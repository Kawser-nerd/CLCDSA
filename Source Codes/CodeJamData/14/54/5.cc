#define NDEBUG
#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

template<typename T, typename U> inline void makemin(T &res, const U &x) {
  if (x < res) {
    res = x;
  }
}
template<typename T, typename U> inline void makemax(T &res, const U &x) {
  if (x > res) {
    res = x;
  }
}
template<typename List, typename Element> inline bool inlist( const List &L, const Element &E ) { return find( L.begin(), L.end(), E ) != L.end(); }

const int MAXN = 80;

int n;
int G[MAXN];
vector<int> adj[MAXN];

vector<int> path[2];

bool used_edge(const vector<int> &path, int a, int b) {
  for (int i=0; i<(int)path.size()-1; ++i) {
    if ((path[i] == a && path[i+1] == b) ||
        (path[i] == b && path[i+1] == a)) {
      return true;
    }
  }
  return false;
}

int calc(int turn, int nonmoves) {
  if (nonmoves == 2) {
    return 0;
  }

  int ret = INT_MIN/2;
  bool possible = false;
  int a = path[turn].back();

  // fprintf(stderr, "calc(turn=%d, nonmoves=%d), a = %d\n", turn, nonmoves, a);

  for (int b : adj[a]) {
    if (used_edge(path[0], a, b) ||
        used_edge(path[1], a, b)) {
      continue;
    }

    possible = true;
    int score = !inlist(path[0], b) && !inlist(path[1], b) ? G[b] : 0;
    // debug(b);
    // debug(score);
    path[turn].push_back(b);
    makemax(ret, score - calc(!turn, 0));
    path[turn].pop_back();
  }
  if (!possible) {
    makemax(ret, -calc(!turn, nonmoves+1));
  }
  return ret;
}

int solve() {
  cin >> n;
  for (int i=0; i<n; ++i) {
    adj[i].clear();
    cin >> G[i];
  }
  for (int i=0; i<n-1; ++i) {
    int j;
    cin >> j;
    --j;
    adj[i].push_back(j);
    adj[j].push_back(i);
  }
  // MINUSONE(memo);

  // path[0] = {7};
  // path[1] = {2};
  // debug(calc(0, 0));
  // return -808;

  int alpha = INT_MIN/2;
  for (int a=0; a<n; ++a) {
    int beta = INT_MAX/2;
    for (int b=0; b<n; ++b) {
      path[0] = {a};
      path[1] = {b};
      int score = G[a];
      if (a != b) {
        score -= G[b];
      }
      score += calc(0, 0);
      // fprintf(stderr, "a = %d, b = %d, score = %d\n", a, b, score);
      makemin(beta, score);
    }
    // fprintf(stderr, "a = %d, beta = %d\n", a, beta);
    makemax(alpha, beta);
  }
  return alpha;
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    printf("Case #%d: %d\n", tt, solve());
    fflush(stdout);
  }
}
