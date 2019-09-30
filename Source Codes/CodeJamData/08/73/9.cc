#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
#include <glpk.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORI(i,v) FOR(i,(int)v.size())
#define FR(i,a,b) for(int i=a;i<b;i++)
#define BEND(v) v.begin(),v.end()
#define dump(x) cerr << #x << " = " << (x) << endl;
//#define dump(...)
typedef long long ll; typedef long double ld;

int cas=0;
const int K = 4;
int M,Q;
double P[32][K];
const double eps = 1e-8;
struct State {
  int i,j;
  double lnp;
};
const double inf = 1e8;
bool operator<(const State& a, const State& b) {
  return a.lnp < b.lnp;
}
void doit() {
  scanf("%d%d",&M,&Q);
  FOR(i,Q) {
    FOR(j,K) {
      scanf("%lf",&P[i][j]);
    }
    sort(&P[i][0], &P[i][K]);
    reverse(&P[i][0], &P[i][K]);
  }
  State init;
  init.i = 0;
  init.j = 0;
  init.lnp = 0;
  FOR(i,Q) init.lnp += log(P[i][0]);
  vector<double> feh;

  priority_queue<State> q;
  q.push(init);

  while ((int)feh.size() < M && q.size()) {
    State s = q.top();
    q.pop();
    if (!(s.lnp >= -inf)) continue;
    feh.push_back(s.lnp);

    if (s.j < K-1) {
      State t = s;
      t.j++;
      t.lnp -= log(P[s.i][s.j]);
      t.lnp += log(P[t.i][t.j]);
      q.push(t);
    }
    FR(i,s.i+1,Q) {
      State t = s;
      t.i = i;
      t.j = 1;
      t.lnp -= log(P[t.i][0]);
      t.lnp += log(P[t.i][1]);
      q.push(t);
    }
  }

  M = min(M,(int)feh.size());
  double ans = 1;
  double pp = 1;
  FOR(i,M) {
    ans *= 1 - exp(feh[i]) / pp;
    pp -= exp(feh[i]);
  }
  ans = 1 - ans;
  printf("Case #%d: %lf\n",++cas,ans);
}
int T;
int main() {
scanf("%d",&T);
FOR(i,T)doit();
}
