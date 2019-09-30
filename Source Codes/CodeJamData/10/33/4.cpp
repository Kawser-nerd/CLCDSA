#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())
#define sqr(a) (a)*(a)

typedef long long int64;
typedef pair<int,int> pii;

const int inf = (int)1E+9;
const double eps = 1e-9;

const string task = "c";
const string inp = task + ".in";
const string oup = task + ".out";

const int nmax = 550;

int n,m;
int a[nmax][nmax];
int r[nmax][nmax];
int p[nmax][nmax];
int b[nmax][nmax];
int res[nmax];

void read(){
	cin >> n >> m;
	forn(i,n){
		string s;
		cin >> s;
		forn(j,s.size()){
			int q = isdigit(s[j]) ? s[j] - '0' : s[j] - 'A' + 10;
//			cerr << q << " ";
			forn(k,4){
				a[i][(j+1)*4 -k - 1] = q & 1;
				q /= 2;
			}
		}
	}
/*	forn(i,n){
		forn(j,m)
			cout << a[i][j];
		cout << endl;
	}
*/}

void kill(int x, int y){
	for (int i = x; i >= 0; i--){
		for (int j = y; j >= 0; j--){
			if (b[i][j] <= y - j)
				break;
			b[i][j] = min(b[i][j], max(x - i, y - j));
		}
	}
}

void calc(){
	memset(r,0,sizeof r);
	memset(p,0,sizeof p);
	forn(i,n){
		ford(j,m){
			r[i][j] = r[i][j+1] + 1;
			if (a[i][j] == a[i][j+1])
				r[i][j] = 1;
		}
	}
	forn(i,n)
		forn(j,m){
			int now = r[i][j];
			for (int k = i; k < n; k++){
				now = min(now, r[k][j]);
				p[i][j] = max(p[i][j], min(now, k - i + 1));
				if (a[k+1][j] == a[k][j]) break;
			}
//			forn(k,p[i][j])
//				p[i][j] = min(p[i][j], p[i+k][j]);
		}
/*	forn(i,n){
		forn(j,m)
			cerr << p[i][j] << " ";
		cerr << endl;
	}
*/	memset(res,0,sizeof res);
	set <pair <int, pii> > h;
	forn(i,n)
		forn(j,m)
			h.insert(mp(-p[i][j], mp(i,j)));
	forn(i,n)
		forn(j,m)
			b[i][j] = n + m;
	while (h.size() > 0){
		int x = h.begin() ->second.first;
		int y = h.begin() ->second.second;
		int f = -h.begin() ->first;
		h.erase(h.begin());
		if (b[x][y] == 0) continue;
		if (f > b[x][y]){
			h.insert(mp(-b[x][y],mp(x,y)));
			continue;
		}
//		if (f > 1)
//			cerr << x << " " << y << " " << f << endl;

/*		if (f == 1){
			forn(i,n){
				forn(j,m)
					cout << b[i][j] << " ";
				cout << endl;
			}
			cout << endl;
		}
*/		
//		if (f <= 4) break;
		res[f]++;
//		forn(i,f){
//			kill(x+i,y);
//			kill(x,y+i);
//		}
		forn(i,f)
			forn(j,f)
				//b[x+i][y+j] = 0;
				kill(x+i,y+j);
	}
			
}

void solve(){
	read();
	calc();
	vector<pii> a;
	ford(i,nmax)
		if (res[i] > 0)
			a.pb(mp(i,res[i]));
	cout << a.size() << endl;
	forn(i,a.size())
		printf("%d %d\n", a[i].fs, a[i].sc);
}

int main(){
	freopen(inp.data(), "rt", stdin);
	freopen(oup.data(),"wt", stdout);

	int tst;
	cin >> tst;
	forn(i,tst){
		printf("Case #%d: ", i+1);
		solve();
	}

	return 0;
}
