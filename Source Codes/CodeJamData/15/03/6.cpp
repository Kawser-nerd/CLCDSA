#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define popb pop_back

#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)

#define maxN 10005

struct q {
  q() {}
  q(char c) : sym(c), pos(true) {}
  char sym;
  bool pos;
  q mul_by(q b);
  bool operator==(const q& other) { return sym == other.sym && pos == other.pos; }
  bool operator!=(const q& other) { return !(*this == other); }
};
q mul(q a, q b) {
  q res;
  res.pos = !(a.pos ^ b.pos);
  if (a.sym == '1') { res.sym = b.sym; return res; }
  if (b.sym == '1') { res.sym = a.sym; return res; }
  if (a.sym == b.sym) { res.sym = '1'; res.pos = !res.pos; return res; }
  if (a.sym == 'i') {
    if (b.sym == 'j') { res.sym = 'k'; return res; }
    if (b.sym == 'k') { res.sym = 'j'; res.pos = !res.pos; return res; }
  }
  if (a.sym == 'j') {
    if (b.sym == 'i') { res.sym = 'k'; res.pos = !res.pos; return res; }
    if (b.sym == 'k') { res.sym = 'i'; return res; }
  }
  if (a.sym == 'k') {
    if (b.sym == 'i') { res.sym = 'j'; return res; }
    if (b.sym == 'j') { res.sym = 'i'; res.pos = !res.pos; return res; }
  }
}
q q::mul_by(q b) { *this = mul(*this, b); return *this; }

int L;
long long X;
char str[maxN];
q x[maxN];

char mul(char a, char b) {
  if (a == '1') {
    return b;
  }
  if (b == '1') {
    return a;
  }
  if (a == b) return -1;
}

int main(){
  int T;
  scanf("%d", &T);
  FOR(t, 1, T) {
    scanf("%d%lld", &L, &X);
    scanf("%s", str);
    REP(i, L) {
      x[i] = q(str[i]);
    }
    q all('1');
    int X4 = X % 4;
    REP(j, X4) {
      REP(i, L) {
        all.mul_by(x[i]);
      }
    }
    if (all != mul(q('i'), mul(q('j'), q('k')))) {
      printf("Case #%d: NO\n", t); continue;
    }
    int firstI = -1;
    q start('1');
    REP(i, L * 5 + 2) {
//      printf("%c %d with %c %d: ", start.sym, start.pos, x[i % L].sym, x[i % L].pos);
      start.mul_by(x[i % L]);
//      printf("%c %d\n", start.sym, start.pos);
      if (start == q('i')) {
        firstI = i + 1;
        break;
      }
    }
    int lastK = -1;
    q end('1');
    REP(i, L * 5 + 2) {
      end = mul(x[(L * 9 - i - 1) % L], end);
      if (end == q('k')) {
        lastK = i + 1;
        break;
      }
    }
//    printf("%d %d\n", firstI, lastK);
    if (firstI == -1 || lastK == -1 || (firstI + lastK >= L * X)) {
      printf("Case #%d: NO\n", t);
    } else {
      printf("Case #%d: YES\n", t);
    }
  }


  return 0;
}
