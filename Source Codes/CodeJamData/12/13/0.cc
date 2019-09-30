#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int N, con[51][51];
int cpos[51], cspd[51];
char clane[51];

bool fcmp(const pair<int, int>& a, const pair<int, int>& b) {
  return a.first * b.second < b.first * a.second;
}

char seen[51];
bool doit(int c, char ln) {
  if (ln != clane[c] && clane[c] != '?') return false;
  if (seen[c]) return ln == seen[c];
  seen[c] = ln;
  for (int c2 = 0; c2 < N; c2++)
    if (con[c][c2] && !doit(c2, (ln=='L'?'R':'L')))
      return false;
  return true;
}

main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    vector<pair<int, int> > tv;
    tv.push_back(make_pair(0, 1));
    cin >> N;
    for (int i = 0; i < N; i++) cin >> clane[i] >> cspd[i] >> cpos[i];
    for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      if (cpos[i] > cpos[j]+5 && cspd[j] > cspd[i]) {
        tv.push_back(make_pair(cpos[i]-(cpos[j]+5), cspd[j]-cspd[i]));
      }
      if (cpos[i] > cpos[j] && cspd[j] > cspd[i]) {
        tv.push_back(make_pair(cpos[i]-cpos[j], cspd[j]-cspd[i]));
      }
      if (cpos[i]+5 > cpos[j] && cspd[j] > cspd[i]) {
        tv.push_back(make_pair((cpos[i]+5)-cpos[j], cspd[j]-cspd[i]));
      }
    }
    sort(tv.begin(), tv.end(), fcmp);

    memset(con, 0, sizeof(con));
    int safetnum = 0, safetden = 1, ti;
    for (ti = 0; ti < tv.size(); ti++) {
      int tnum = tv[ti].first, tden = tv[ti].second;
      for (int i = 0; i < N; i++) {
        bool coll = false;
        for (int j = 0; j < N; j++) if (j != i) {
          int cpos1 = cpos[i] * tden + cspd[i] * tnum;
          int cpos2 = cpos[j] * tden + cspd[j] * tnum;
          if (abs(cpos1-cpos2) < 5 * tden) {
            con[i][j] = 1;
            coll = true;
          }
        }
        if (!coll) {
          for (int j = 0; j < N; j++) con[i][j] = 0;
          for (int j = 0; j < N; j++) con[j][i] = 0;
          clane[i] = '?';
        }
      }
      for (int i = 0; i < N; i++) {
        if (clane[i] == '?') {
          memset(seen, 0, sizeof(seen));
          bool lv = doit(i, 'L');
          memset(seen, 0, sizeof(seen));
          bool rv = doit(i, 'R');
          if (!lv && !rv) goto done;
          if (!lv && rv) clane[i] = 'R';
          if (lv && !rv) clane[i] = 'L';
        } else {
          memset(seen, 0, sizeof(seen));
          if (!doit(i, clane[i])) goto done;
        }
      }
      safetnum = tnum; safetden = tden;
    }

done:
    if (ti == tv.size()) {
      printf("Case #%d: Possible\n", prob++);
    } else {
      printf("Case #%d: %.10lf\n", prob++, (double)safetnum/safetden);
    }
  }
}
