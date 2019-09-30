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

namespace Mateusz {

const int nax=505;

int prze[nax][nax];
int flow[nax][nax];
long long kosz[nax][nax];

vector <int> graf[nax];

long long wkosz;

int guj;

long long odl[nax];
int aktu[nax];

int bylo[nax];

void clear(int roz)
{
  //debug() << "Clear()";
	for (int i=0; i<=roz; i++)
		for (int j=0; j<=roz; j++)
			prze[i][j]=flow[i][j]=kosz[i][j]=0;
  for (int i = 0; i <= roz; i++)
    graf[i].clear();
	wkosz=0;
}

void add_edge(int z, int dok, int przep, int koszt)
{
  //debug() << "add_edge(" << imie(z) << imie(dok) << imie(przep) << imie(koszt) << ")";
	kosz[z][dok]=koszt;
	kosz[dok][z]=-koszt;
	graf[z].push_back(dok);
	graf[dok].push_back(z);
	prze[z][dok]=przep;
}

void spfa(int n, int zr)
{
	for (int i=1; i<=n; i++)
	{
		odl[i]=1e17;
		aktu[i]=1;
	}
	aktu[zr]=0;
	odl[zr]=0;
	queue <int> kol;
	kol.push(zr);
	while(!kol.empty())
	{
		int v=kol.front();
		kol.pop();
		if (aktu[v])
			continue;
		aktu[v]=1;
    for (int j = 0; j < (int) graf[v].size(); j++) {
      auto i = graf[v][j];
		//for (auto i : graf[v])
		//{
			if (prze[v][i] && odl[v]+kosz[v][i]<odl[i])
			{
				odl[i]=odl[v]+kosz[v][i];
				aktu[i]=0;
				kol.push(i);
			}
		}
	}
	for (int i=1; i<=n; i++)
		bylo[i]=0;
}

int dfs(int v)
{
	if (v==guj)
		return 1;
	bylo[v]=1;
  for (int j = 0; j < (int) graf[v].size(); j++) {
    auto i = graf[v][j];
	//for (auto i : graf[v])
	//{
		if (prze[v][i] && !bylo[i] && odl[i]==odl[v]+kosz[v][i] && dfs(i))
		{
			flow[v][i]++;
			
			while(flow[v][i] && flow[i][v])
			{
				flow[v][i]--;
				flow[i][v]--;
			}
			
			wkosz+=kosz[v][i];
			prze[v][i]--;
			prze[i][v]++;
			
			return 1;
		}
	}
	return 0;
}

pair < int, long long> go_flow(int n, int zr, int uj)
{
  debug() << "go_flow(" << imie(n) << imie(zr) << imie(uj) << ")";
	guj=uj;
	int ret=0;
	while(1)
	{
		spfa(n, zr);
		int zm=dfs(zr);
		ret+=zm;
		if (!zm)
			return {ret, wkosz};
	}
}

}  // namespace Mateusz

using ll = long long;
using ld = long double;

constexpr int nax = 105;
constexpr int infty = 1000 * 1000 * 1000 + 5;
constexpr int mod = 1000 * 1000 * 1000 + 7;

int C, R, M, S, T;
char tab[nax][nax];
int sid[nax][nax];
int tid[nax][nax];
int odl[nax][nax];
set<int> zbior[nax][nax];
set<int> widzi[nax][nax];

set<int> Suma(const set<int>& a, const set<int>& b) {
  if (a.size() < b.size()) return Suma(b, a);
  auto ca = a;
  for (int x : b) {
    ca.insert(x);
  }
  return move(ca);
}

void Bfs(int r, int c) {
  for (int r = 1; r <= R; r++) {
    for (int c = 1; c <= C; c++) {
      odl[r][c] = R * C + 100;
      zbior[r][c].clear();
    }
  }
  odl[r][c] = 0;
  vector<pair<int, int>> kol;
  kol.emplace_back(r, c);
  for (int i = 0; i < (int) kol.size(); i++) {
    r = kol[i].first;
    c = kol[i].second;
    const int o = odl[r][c];
    constexpr int dr[4] = {-1, 0, 1, 0};
    constexpr int dc[4] = {0, -1, 0, 1};
    for (int j = 0; j < 4; j++) {
      const int nr = r + dr[j];
      const int nc = c + dc[j];
      if (tab[nr][nc] != '#' and odl[nr][nc] > odl[r][c] + 1) {
        odl[nr][nc] = odl[r][c] + 1;
        zbior[nr][nc] = Suma(zbior[r][c], widzi[r][c]);
        kol.emplace_back(nr, nc);
      }
    }
  }
}

vector<pair<int, pair<int, set<int>>>> graph[nax];

int nast_grat;
int id_grat[nax];
bool odw_grat[nax];
vector<int> grat[nax];

void DfsGrat(int w) {
  if (odw_grat[w]) return;
  odw_grat[w] = true;
  for (int v : grat[w]) {
    DfsGrat(v);
  }
  id_grat[w] = nast_grat++;
}

void Skojarz() {
  Mateusz::clear(S + T + 5);
  for (int s = 1; s <= S; s++) {
    Mateusz::add_edge(0, s, 1, 0);
    for (const auto& p : graph[s]) {
      assert(1 <= p.first and p.first <= T);
      Mateusz::add_edge(s, S + p.first, 1, p.second.first);
    }
  }
  for (int t = 1; t <= T; t++) {
    Mateusz::add_edge(S + t, S + T + 1, 1, 0);
  }
  auto res = Mateusz::go_flow(S + T + 5, 0, S + T + 1);
  const int rozmiar = res.first;
  vector<pair<int, int>> wynik;
  for (int t = 1; t <= T; t++) {
    odw_grat[t] = false;
    grat[t].clear();
  }
  for (int s = 1; s <= S; s++) {
    debug() << imie(s) << imie(graph[s]);
    for (const auto& p : graph[s]) {
      if (Mateusz::flow[s][S + p.first]) {
        wynik.emplace_back(s, p.first);
        for (int t : p.second.second) {
          assert(p.first != t);
          grat[p.first].push_back(t);
        }
      }
    }
  }
  nast_grat = 1;
  for (int t = 1; t <= T; t++) {
    DfsGrat(t);
  }
  sort(wynik.begin(), wynik.end(),
      [&](const pair<int, int>& a, const pair<int, int>& b) -> bool {
        return id_grat[a.second] < id_grat[b.second];
      });
  debug() << imie(wynik) << imie(rozmiar);
  assert(rozmiar == (int) wynik.size());
  printf("%d\n", rozmiar);
  for (const auto& p : wynik) {
    printf("%d %d\n", p.first, p.second);
  }
}

void przyp() {
  scanf("%d%d%d", &C, &R, &M);
  S = T = 0;
  for (int r = 0; r <= R + 1; r++) {
    for (int c = 0; c <= C + 1; c++) {
      tab[r][c] = '#';
      widzi[r][c].clear();
    }
  }
  for (int r = 1; r <= R; r++) {
    for (int c = 1; c <= C; c++) {
      scanf(" %c", &tab[r][c]);
      if (tab[r][c] == 'S') {
        sid[r][c] = ++S;
      }
      if (tab[r][c] == 'T') {
        tid[r][c] = ++T;
      }
    }
  }
  for (int r = 1; r <= R; r++) {
    for (int c = 1; c <= C; c++) {
      if (tab[r][c] == 'T') {
        int t = tid[r][c];
        const int Or = r;
        const int Oc = c;
        auto Dodaj = [t, Or, Oc](int r, int c) -> bool {
          if (tab[r][c] == '#') return true;
          widzi[r][c].insert(t);
          return false;
        };
        for (int nr = r; nr >= 1; nr--) if (Dodaj(nr, c)) break;
        for (int nr = r; nr <= R; nr++) if (Dodaj(nr, c)) break;
        for (int nc = c; nc >= 1; nc--) if (Dodaj(r, nc)) break;
        for (int nc = c; nc <= C; nc++) if (Dodaj(r, nc)) break;
      }
    }
  }
  for (int r = 1; r <= R; r++) {
    for (int c = 1; c <= C; c++) {
      //debug() << imie(r) << imie(c) << imie(widzi[r][c]);
    }
  }
  for (int s = 1; s <= S; s++) {
    graph[s].clear();
  }
  for (int r = 1; r <= R; r++) {
    for (int c = 1; c <= C; c++) {
      if (tab[r][c] == 'S') {
        Bfs(r, c);
        for (int nr = 1; nr <= R; nr++) {
          for (int nc = 1; nc <= C; nc++) {
            if (tab[nr][nc] == 'T') {
              bool ok = (odl[nr][nc] <= M);
              int o = R * C;
              set<int> z;
              auto Spr = [&ok, &o, &z](int r, int c) -> bool {
                if (tab[r][c] == '#') return true;
                if (odl[r][c] <= M) {
                  ok = true;
                  if (odl[r][c] < o) {
                    o = odl[r][c];
                    z = zbior[r][c];
                  }
                }
                return false;
              };
              for (int xr = nr - 1; xr >= 1; xr--) {
                if (Spr(xr, nc)) break;
              }
              for (int xr = nr + 1; xr <= R; xr++) {
                if (Spr(xr, nc)) break;
              }
              for (int xc = nc - 1; xc >= 1; xc--) {
                if (Spr(nr, xc)) break;
              }
              for (int xc = nc + 1; xc <= C; xc++) {
                if (Spr(nr, xc)) break;
              }
              if (ok) {
                graph[sid[r][c]].emplace_back(tid[nr][nc], make_pair(o, z));
              }
            }
          }
        }
      }
    }
  }
  Skojarz();
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
