#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// Need a table that shows the add mask for each letter for each word
// Need a table that shows the possilbitiy mask for each mask of each word

#define MAXN 10000
#define MAXLEN 10

string SS[MAXN];
vector<int> LNLST[MAXLEN + 1];
int LTRS[MAXN];
int LMSK[MAXN][26];

int POS[1 << MAXLEN];
int NV[MAXN];

pair<int, int> search(const string& G, vector<int> V, int x, int fail) {
  if(V.empty()) return make_pair(1, -1);
  if(x == G.size()) return make_pair(-fail, *min_element(V.begin(), V.end()));
  int lt = G[x] - 'a';

  memset(POS, 0, sizeof(POS));
  memcpy(NV, &V[0], sizeof(int) * V.size());
  for(int i = 0; i < V.size(); i++) {
    ++POS[LMSK[NV[i]][lt]];
  }
  for(int i = 1; i < 1 << MAXLEN; i++) {
    POS[i] += POS[i - 1];
  }
  for(int i = 0; i < V.size(); i++) {
    V[--POS[LMSK[NV[i]][lt]]] = NV[i];
  }

  int lstmsk = LMSK[V[0]][lt];
  vector<int> V2(1, V[0]);
  pair<int, int> res(1, -1);
  for(int i = 1; i < V.size(); i++) {
    if(LMSK[V[i]][lt] != lstmsk) {
      res = min(res, search(G, V2, x + 1, fail + !lstmsk));
      V2.clear();
    }
    lstmsk = LMSK[V[i]][lt];
    V2.push_back(V[i]);
  }
  res = min(res, search(G, V2, x + 1, fail));

  return res;
}

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    int N, M; cin >> N >> M;
    for(int i = 0; i <= MAXLEN; i++) LNLST[i].clear();
    for(int i = 0; i < N; i++) {
      string S; cin >> S; SS[i] = S;
      LTRS[i] = 0;
      for(int j = 0; j < 26; j++) {
        LMSK[i][j] = 0;
      }
      for(int j = 0; j < S.size(); j++) {
        int ch = S[j] - 'a';
        LTRS[i] |= 1 << ch;
        LMSK[i][ch] |= 1 << j;
      }
      LNLST[S.size()].push_back(i);
    }
    printf("Case #%d:", t);
    for(int i = 0; i < M; i++) {
      string G; cin >> G;
      pair<int, int> best(1, -1);
      for(int ln = 1; ln <= MAXLEN; ln++) {
        best = min(best, search(G, LNLST[ln], 0, 0));
      }
      printf(" %s", SS[best.second].c_str());
    }
    printf("\n");
  }
}
