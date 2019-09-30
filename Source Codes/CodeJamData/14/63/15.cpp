/* Writen by Filip Hlasek 2014 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111
vector<int> graph[MAXN];
int N;
int col[MAXN];

map<pair<int, int>, string> dp_code;

string get_code (int root, int father) {
  pair<int, int> state (root, father);
  if (dp_code.count(state)) return dp_code[state];
  string code;
  code.push_back(col[root] + 'A');
  vector<string> codes;
  REP(i, graph[root].size()) if (graph[root][i] != father) {
    codes.push_back(get_code(graph[root][i], root));
  }
  sort(codes.begin(), codes.end());
  code.push_back('(');
  REP(i, codes.size()) code += codes[i];
  code.push_back(')');
  return dp_code[state] = code;
}

map<pair<int, int>, bool> dp_symetric;

bool symetric (int root, int father) {
  pair<int, int> state (root, father);
  if (dp_symetric.count(state)) return dp_symetric[state];
  vector<pair<string, int> > sons;
  REP(i, graph[root].size()) if (graph[root][i] != father) {
    sons.push_back(make_pair(get_code(graph[root][i], root), graph[root][i]));
  }
  sort(sons.begin(), sons.end());
  int pos = 0, sym = 0;
  while (pos < sons.size()) {
    if (pos + 1 == sons.size() || sons[pos].first != sons[pos + 1].first) {
      if (!symetric(sons[pos].second, root)) return dp_symetric[state] = false;
      pos++;
      sym++;
    }
    else pos += 2;
  }
  if (father == -1) return dp_symetric[state] = (sym <= 2);
  return dp_symetric[state] = (sym <= 1);
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  FOR(testcase, 1, T) {
    dp_symetric.clear();
    dp_code.clear();
    scanf("%d", &N);
    REP(i, N) graph[i].clear();
    char c[10];
    REP(i, N) { scanf("%s", c); col[i] = c[0] - 'A'; }
    REP(i, N - 1) {
      int a, b;
      scanf("%d%d", &a, &b);
      a--; b--;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    printf("Case #%d: ", testcase);
    bool ok = false;
    REP(i, N) if (symetric(i, -1)) { ok = true; break; }

    REP(i, N) REP(j, graph[i].size()) if (get_code(i, graph[i][j]) == get_code(graph[i][j], i)) ok = true;

    if (ok) printf("SYMMETRIC\n");
    else printf("NOT SYMMETRIC\n");
  }
  return 0;
}
