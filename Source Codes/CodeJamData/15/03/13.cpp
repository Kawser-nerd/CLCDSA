#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define FOR(prom, a, b) for(int prom = (a); prom < (b); prom++)
#define FORD(prom, a, b) for(int prom = (a); prom > (b); prom--)
#define FORDE(prom, a, b) for(int prom = (a); prom >= (b); prom--)

#define DRI(a) int a; scanf("%d ", &a);
#define DRII(a, b) int a, b; scanf("%d %d ", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d ", &a, &b, &c);
#define DRIIII(a, b, c, d) int a, b, c, d; scanf("%d %d %d %d ", &a, &b, &c, &d);
#define RI(a) scanf("%d ", &a);
#define RII(a, b) scanf("%d %d ", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d ", &a, &b, &c);
#define RIIII(a, b, c, d) scanf("%d %d %d %d ", &a, &b, &c, &d);

#define PB push_back
#define MP make_pair

#define ll long long
#define ull unsigned long long

#define MM(co, cim) memset((co), (cim), sizeof((co)))

#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;

int M[4][4] = {
  {0,1,2,3},
  {1,0,3,2},
  {2,3,0,1},
  {3,2,1,0}
};

int S[4][4] = {
  {1,1,1,1},
  {1,-1,1,-1},
  {1,-1,-1,1},
  {1,1,-1,-1}
};

int main ()
{
  int reqResultM = M[M[1][2]][3]; // 1->0
  int reqResultS = S[S[1][2]][3]; // -
  //cout << reqResultM << " " << reqResultS <<endl;
  DRI(T);
  FOR(t,0,T) {
    ll L,X;
    cin >> L >> X;
    string st;
    cin >> st;
    int m = 0;
    int s = 1;
    FOR(i,0,L) {
      s *= S[m][st[i]-'h'];
      m = M[m][st[i]-'h'];
    }
    //cout << m << " " <<s << endl;
    int cnt = X%4LL;
    if(cnt == 0) cnt = 4;
    int rm = 0;
    int rs = 1;
    FOR(i,0,cnt) {
      rs *= S[rm][m];
      rs *= s;
      rm = M[rm][m];
    }
    if(rm != reqResultM || rs != reqResultS) {
      printf("Case #%d: NO\n", t+1);
      continue;
    }
    st += st;
    st += st;
    // TODO debug
    //cout << st << endl;
    int b = -1, e = -1;
    m = 0;
    s = 1;
    FOR(i,0,4*L) {
      s *= S[m][st[i]-'h'];
      m = M[m][st[i]-'h'];
      if(m == 1 && s == 1) {
        b = i+1;
        break;
      }
    }
    m = 0;
    s = 1;
    FORDE(i,4*L-1,0) {
      s *= S[st[i]-'h'][m];
      m = M[st[i]-'h'][m];
      if(m == 3 && s == 1) {
        e = 4*L-i;
        break;
      }
    }
    //cout << b << " " << e <<endl;
    if(b == -1 || e == -1 || L*X <= (ll)b+(ll)e) printf("Case #%d: NO\n", t+1);
    else printf("Case #%d: YES\n", t+1);
  }
  return 0;
}
