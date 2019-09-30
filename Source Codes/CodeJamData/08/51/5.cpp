#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
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

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

const int off = 3100;

bitset <2*off> b[2*off];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
	cin >> test;	
	int l;
	string s;
	int num;
	FOR (ntest, 1, test + 1) {
		cout << "Case #" << ntest << ": ";
		cin >> l;
		int x = off, y = off;
		int d = 0;
		vector <VI> wy (2 * off), wx(2 * off);

		REP (i, 2 * off)
			b[i].reset();	
				
		REP (i, l) {
			cin >> s >> num;
			REP (p, num) {
				REP (j, SZ (s)) {
					if (s[j] == 'L')
						d = (d + 3) % 4;
					else
					if (s[j] == 'R')
						d = (d + 1) % 4;
					else {
						if (d == 0)
							wy[y].pb (x);							
						if (d == 1)
							wx[x].pb (y);							
						if (d == 2)
							wy[y-1].pb (x);							
						if (d == 3)
							wx[x-1].pb (y);							
						x += dx[d];
						y += dy[d];
					}	
				}
			}
		}	
		REP (i, SZ (wy))
			SORT (wy[i]);
		REP (i, SZ (wx))
			SORT (wx[i]);
			
		int ans = 0;
		REP (i, SZ (wy)) {
			for (int j = 1; j+1 < SZ (wy[i]); j += 2)
				for (int k = wy[i][j]; k < wy[i][j+1]; ++k) 
					if (!b[i][k]) 
					{
						++ans;
						b[i][k] = 1;					
					}
		}			
		REP (i, SZ (wx)) {
			for (int j = 1; j+1 < SZ (wx[i]); j += 2) {
				for (int k = wx[i][j]; k < wx[i][j+1]; ++k) {
					if (!b[k][i]) 
					{
						++ans;
						b[k][i] = 1;					
					}
				}
			}
		}			
		cout << ans;
		cout << endl;		
	}	
	return 0;
}
