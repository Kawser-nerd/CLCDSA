#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int px[] = {-1, 0, 1, 0};
int py[] = {0, -1, 0, 1};

const int nmax = 70;

int n, m;
int used[nmax][nmax];
char a[nmax][nmax];
vector<pair<int, pii> > res;
set<long long> hsh;

void dfs(int x, int y){
	used[x][y] = 1;
	forn(i, 4){
		int nx = x + px[i];
		int ny = y + py[i];
		if (nx > x) continue;
		if (a[nx][ny] != '#' && !used[nx][ny])
			dfs(nx, ny);
	}
}

bool move(pii &a1, int dr){
	pii b = a1;
	b.fs += px[dr];
	b.sc += py[dr];
	if (a[b.fs][b.sc] == '#')
		return 0;
	a1 = b;
	return 1;
}

bool down(vector<pii> &a){
	bool res = 0;
	forn(i, a.size())
		if (move(a[i], 2))
			res = 1;
	return res;
}

long long hash(vector<pii> now){
	long long res = 0;
	forn(i, now.size()){
		res = res * 239017 + now[i].fs;
		res = res * 239017 + now[i].sc;
	}
	return res;
}

bool go(vector<pii> now, int x, int y){
	forn(i, now.size())
		if (!used[now[i].fs][now[i].sc]) return 0;
	sort(all(now));
	now.erase(unique(all(now)), now.end());
	if (now.size() == 1) return 1;
	long long w = hash(now);
	if (hsh.count(w)) return 0;
	hsh.insert(w);

	vector<pii> a = now;
	if (down(a) && go(a, x, y)) return 1;

		for (int dst = 1; dst <= 3; dst += 2){
			vector<pii> nxt = now, a;
			while(1){
				bool mv = 0;
				forn(i,nxt.size())
					if (move(nxt[i], dst)) mv = 1;
				if (!mv) break;
				if (go(nxt, x, y)) return 1;
			}
		}
	return 0;
}

pii solve(int x, int y){
	hsh.clear();
//	cerr << x << " " << y << endl;
	memset(used, 0, sizeof used);
	dfs(x, y);
	vector<pii> a;
	forn(i, n)
		forn(j, m)
			if (used[i][j])
				a.pb(mp(i, j));
	pii res = mp(0, 0);
	res.fs = a.size();

	a.clear();
	forn(i, n)
		forn(j, m)
			if (used[i][j] && !used[i][j-1])
				a.pb(mp(i, j));

	res.sc = go(a, x, y);
	return res;
}

void solve(){
	res.clear();
	cin >> n >> m;
	forn(i, n)
		forn(j, m)
			cin >> a[i][j];
	forn(i, n)
		forn(j, m)
			if (isdigit(a[i][j])){
				pii now = solve(i, j);
				res.pb(mp(a[i][j] - '0', now));
			}
	sort(all(res));
	forn(i, res.size()){
		printf("%d: %d ", res[i].fs, res[i].sc.fs);
		if (res[i].sc.sc)
			puts("Lucky");
		else
			puts("Unlucky");
	}
}

int main ()
{
	int n;
	cin >> n;

	forn(i, n){
		cerr << i << endl;
		printf("Case #%d:\n", i + 1);
		solve();
	}

	
	return 0;
}
