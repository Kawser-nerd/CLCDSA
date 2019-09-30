#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1005;

vector <int> V[MAX];
int pref[MAX], kol[MAX];
int sz, brljud, brkar;

int main()
{
  int brt;
  scanf("%d", &brt);

  FOR(tt, 1, brt+1) {
    memset(pref, 0, sizeof pref);
    memset(kol, 0, sizeof kol);
    REP(i, MAX) V[i].clear();

    scanf("%d%d%d", &sz, &brljud, &brkar);
    //    TRACE(sz _ brljud _ brkar);
    
    REP(i, brkar) {
      int poz, cov;
      scanf("%d%d", &poz, &cov); poz--; cov--;
      V[cov].push_back(poz);
      kol[poz]++;
      pref[poz]++;
    }

    FOR(i, 1, MAX)
      pref[i] += pref[i-1];

    int rje = 0;
    REP(i, MAX) {
      rje = max(rje, (int) V[i].size());
      rje = max(rje, (pref[i] + i) / (i+1));
    }

    int prom = 0;
    REP(i, sz)
      prom += max(0, kol[i] - rje);
   
    printf("Case #%d: %d %d\n", tt, rje, prom);
  }

  return 0;
}
