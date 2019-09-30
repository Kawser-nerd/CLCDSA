#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second
#define DEBUG(x) cout << #x << " = " << x << endl;

#define INF 1000000000

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef pair <int, VI> PIVI;
typedef long long ll;

string s[100];
int a[100][100];
int b[100][100];
bool vis[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void relax (int y, int x, int cost) {
	if (s[y][x] == '#')
		return;
	a[y][x] <?= cost;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
	cin >> test;	
	int n, m;
	FOR (ntest, 1, test + 1) {
		cout << "Case #" << ntest << ": ";
		cin >> n >> m;
		REP (i, n) {
			cin >> s[i+1];		
			s[i+1] = '#' + s[i+1] + '#';
		}
		s[0] = string (m+2, '#');
		s[n+1] = string (m+2, '#');
		
		n += 2;
		m += 2;

		int x1, y1, x2, y2;
		
		REP (i, n)
			REP (j, m) {
				if (s[i][j] == 'O')
					y1 = i, x1 = j;
				if (s[i][j] == 'X')
					y2 = i, x2 = j;					
				a[i][j] = INF;
				b[i][j] = INF;
			}
		a[y1][x1] = 0;
		
		REP (i, n)
			REP (j, m)
				REP (y, n)
					REP (x, m)
						if (s[y][x] == '#') {
							b[i][j] <?= abs (y - i) + abs (x - j);
						}
		
		memset (vis, 0, sizeof (vis));
		while (true) {
			int best = INF;
			int y, x;
			REP (i, n)
				REP (j, m)
					if (a[i][j] < best && !vis[i][j]) {
						best = a[i][j];
						y = i;
						x = j;
					}
			if (best == INF)
				break;
			vis[y][x] = true;

			REP (vec, 4) {
				relax (y + dy[vec], x + dx[vec], 1 + a[y][x]);
				
				int ny = y, nx = x;

				while (true) {
					int ky = dy[vec] + ny;
					int kx = dx[vec] + nx;
					
					if (s[ky][kx] == '#')
						break;
						
					ny = ky;
					nx = kx;
				}


				relax (ny, nx, b[y][x] + a[y][x]);				
			}
		}

		if (a[y2][x2] == INF)
			cout << "THE CAKE IS A LIE";
		else
			cout << a[y2][x2];	
		cout << endl;		
	}	
	return 0;
}
