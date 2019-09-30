#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

namespace Cygan {

#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, n, d) for (int i = (n); i >= (d); i--)
#define FOREACH(it, v) for (auto it = begin(v); it != end(v); ++it)
#define VI vector<int>
#define PB push_back

const int N=1000000;
VI implies[2*N]; //wymuszenia, 2*x to zmienna 2*x+1 to jej zaprzeczenie
int sat_val[2*N],sat_vis[2*N],sat_sort[2*N],sat_ile;

inline void sat_or(int a,int b){
  implies[a^1].PB(b);
  implies[b^1].PB(a);
}

void sat_dfs_mark(int x){
  sat_vis[x]=1; sat_val[x]=sat_val[x^1]==-1;
  FOREACH(it,implies[x]) if (!sat_vis[*it]) sat_dfs_mark(*it);
}

void sat_dfs(int x){
  sat_vis[x]=1;
  FOREACH(it,implies[x^1]) if (!sat_vis[*it^1]) sat_dfs(*it^1);
  sat_sort[sat_ile++]=x;
}

/*przekazujemy liczbe zmiennych*/
int sat2(int n){
  sat_ile=0;
  REP(i,2*n) sat_vis[i]=0,sat_val[i]=-1;
  REP(i,2*n) if (!sat_vis[i]) sat_dfs(i);
  REP(i,2*n) sat_vis[i]=0;
  FORD(i,2*n-1,0) if (!sat_vis[sat_sort[i]]) sat_dfs_mark(sat_sort[i]);
  REP(i,2*n) if (sat_val[i]) FOREACH(it,implies[i]) if (!sat_val[*it]) return 0;
  return 1;
}

void Clear(int n) {
  for (int i = 0; i < 2 * n; i++) {
    implies[i].clear();
    sat_val[i] = sat_vis[i] = sat_sort[i] = 0;
  }
  sat_ile = 0;
}

 //Begin of the code
int main(){
  int n=3;
  sat_or(2*0,2*1+1); //x_0 or !x_1
  sat_or(2*2+1,2*1); //!x_2 or x_1 
  printf("%d\n",sat2(n));
  REP(i,2*n) printf("%d ",sat_val[i]);
  printf("\n");
  return 0;
}

}  // namespace Cygan

using ll = long long;
using ld = long double;

constexpr int nax = 105;
constexpr int infty = 1000 * 1000 * 1000 + 5;
constexpr int mod = 1000 * 1000 * 1000 + 7;

constexpr int Up = 0;
constexpr int Right = 1;
constexpr int Down = 2;
constexpr int Left = 3;

int R, C;
char tab[nax][nax];

int id[nax][nax][4];
int rid[nax * nax * 4];
int cid[nax * nax * 4];
int kid[nax * nax * 4];
int cnt_hash[nax * nax * 4];
int cnt_laser[nax * nax * 4];
int fut[nax * nax * 4];
int fuf(int w) { if (fut[w] == w) return w; return fut[w] = fuf(fut[w]); }
void fuu(int u, int v) {
  u = fuf(u); v = fuf(v);
  if (u == v) return;
  fut[u] = v;
  cnt_hash[v] += cnt_hash[u];
  cnt_laser[v] += cnt_laser[u];
}

void przyp() {
  vector<pair<int, int>> ors, xors;
  int nast_id = 0;
  scanf("%d%d", &R, &C);
  for (int r = 0; r <= R + 1; r++) {
    for (int c = 0; c <= C + 1; c++) {
      tab[r][c] = '#';
    }
  }
  for (int r = 1; r <= R; r++) {
    for (int c = 1; c <= C; c++) {
      scanf(" %c", &tab[r][c]);
    }
  }
  for (int r = 0; r <= R + 1; r++) {
    for (int c = 0; c <= C + 1; c++) {
      for (int i = 0; i < 4; i++) {
        rid[nast_id] = r;
        cid[nast_id] = c;
        kid[nast_id] = i;
        fut[nast_id] = nast_id;
        cnt_hash[nast_id] = (tab[r][c] == '#');
        cnt_laser[nast_id] = (tab[r][c] == '|' or tab[r][c] == '-');
        id[r][c][i] = nast_id;
        nast_id++;
      }
    }
  }
  for (int r = 0; r <= R + 1; r++) {
    for (int c = 0; c <= C + 1; c++) {
      const char ch = tab[r][c];
      if (ch == '.' or ch == '|' or ch == '-') {
        fuu(id[r][c][Up], id[r][c][Down]);
        fuu(id[r][c][Left], id[r][c][Right]);
        if (ch == '.') {
          ors.emplace_back(id[r][c][Up], id[r][c][Left]);
        } else {
          xors.emplace_back(id[r][c][Up], id[r][c][Left]);
        }
      } else if (ch == '/') {
        fuu(id[r][c][Up], id[r][c][Left]);
        fuu(id[r][c][Down], id[r][c][Right]);
      } else if (ch == '\\') {
        fuu(id[r][c][Up], id[r][c][Right]);
        fuu(id[r][c][Down], id[r][c][Left]);
      } else if (ch == '#') {
        // Nothing.
      } else {
        assert(false);
      }
    }
  }
  for (int r = 1; r <= R; r++) {
    for (int c = 1; c <= C; c++) {
      fuu(id[r][c][Up], id[r - 1][c][Down]);
      fuu(id[r][c][Down], id[r + 1][c][Up]);
      fuu(id[r][c][Left], id[r][c - 1][Right]);
      fuu(id[r][c][Right], id[r][c + 1][Left]);
    }
  }
  /*
  sat_or(2*0,2*1+1); //x_0 or !x_1
  sat_or(2*2+1,2*1); //!x_2 or x_1
  printf("%d\n",sat2(n));
  REP(i,2*n) printf("%d ",sat_val[i]);
  printf("\n");
  */
  Cygan::Clear(nast_id);
  for (int i = 0; i < nast_id; i++) {
    const int j = fuf(i);
    if (i != j) {
      // !x_i
      Cygan::sat_or(2 * i + 1, 2 * i + 1);
    } else {
      if (cnt_hash[j] == 2 and cnt_laser[j] == 2) {
        // Ok.
      } else {
        // !x_j
        Cygan::sat_or(2 * j + 1, 2 * j + 1);
      }
    }
  }
  for (const auto& p : ors) {
    const int a = fuf(p.first);
    const int b = fuf(p.second);
    Cygan::sat_or(2 * a, 2 * b);
  }
  for (const auto& p : xors) {
    const int a = fuf(p.first);
    const int b = fuf(p.second);
    Cygan::sat_or(2 * a, 2 * b);
    Cygan::sat_or(2 * a + 1, 2 * b + 1);
  }
  const bool result = Cygan::sat2(nast_id);
  if (!result) {
    printf("IMPOSSIBLE\n");
    return;
  }
  printf("POSSIBLE\n");
  for (int r = 1; r <= R; r++) {
    for (int c = 1; c <= C; c++) {
      if (tab[r][c] == '|' or tab[r][c] == '-') {
        const int left = fuf(id[r][c][Left]);
        const int up = fuf(id[r][c][Up]);
        assert(Cygan::sat_val[2 * left] or Cygan::sat_val[2 * up]);
        assert(!Cygan::sat_val[2 * left] or !Cygan::sat_val[2 * up]);
        if (Cygan::sat_val[2 * left]) {
          printf("-");
        } else {
          printf("|");
        }
      } else {
        printf("%c", tab[r][c]);
      }
    }
    printf("\n");
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    przyp();
  }
  return 0;
}
