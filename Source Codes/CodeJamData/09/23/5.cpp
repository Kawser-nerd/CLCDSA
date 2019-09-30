#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int i, j, k, m, n, l;
int good(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; }
char s[100][100];
const int Z = 500;
int have[251], le, q[10000];
int f[40][40][2*Z+1];
vector<int> ov[40][40], nv[40][40];
vector<int>::iterator it;
string d[40][40][2*Z+1];

void got(int k) {
	if (1 <= k && k <= 250)
		if (have[k]) {
			have[k] = 0;
			le--;
		}
}

int main() {

	freopen("C.in", "r", stdin);

//	freopen("X-small-attempt0.in", "r", stdin);
//	freopen("X-small-attempt0.out", "w", stdout);

//	freopen("X-large.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int tt, tn; cin >> tn;

	F1(tt,tn) {
		printf("Case #%d:\n", tt);

		scanf("%d%d\n", &n, &m);
		F0(i,n) gets(s[i]);
		
		le = 0;
		F1(i,251) have[i] = 0; 
		F0(i,m) { cin >> q[i]; if (!have[q[i]]) { have[q[i]] = 1; le++; } }

		memset(f, -1, sizeof(f));

		F0(i,n) F0(j,n) if (isdigit(s[i][j])) {
			nv[i][j].clear();
			k = s[i][j] - '0';
			f[i][j][k+Z] = 1;
			d[i][j][k+Z] = string(1, s[i][j]);
			got(k);
			nv[i][j].push_back(k);
		}
		
		string st;
		for (l = 2; le; l++) {
			F0(i,n) F0(j,n) ov[i][j] = nv[i][j];
			F0(i,n) F0(j,n) if (isdigit(s[i][j])) {
				for (it = ov[i][j].begin(); it != ov[i][j].end(); it++)
				F0(k,4) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (!good(x, y)) continue;
					int c = (s[x][y] == '+') ? 1 : -1;
					int ll;
					F0(ll,4) {
						int x2 = x + dx[ll];
						int y2 = y + dy[ll];
						if (!good(x2, y2)) continue;
						int dig = s[x2][y2] - '0';
						int v = *it + c * dig;
						if (v < -Z || v > Z) continue;
						if (f[x2][y2][v+Z] == -1) {
							f[x2][y2][v+Z] = l;
							got(v);
							nv[x2][y2].push_back(v);
							d[x2][y2][v+Z] = d[i][j][*it+Z] + string(1, s[x][y])+ string(1, s[x2][y2]);
						} else if (f[x2][y2][v+Z] == l) {
							st = d[i][j][*it+Z] + string(1, s[x][y])+ string(1, s[x2][y2]);
							if (st < d[x2][y2][v+Z]) d[x2][y2][v+Z] = st;
						}
					}
				}
			}
		}
		F0(l,m) {
			k = q[l];
			int bl = inf;
			string best;
			F0(i,n) {
				F0(j,n) if (f[i][j][k+Z] != -1) if (f[i][j][k+Z] < bl || (f[i][j][k+Z] == bl && d[i][j][k+Z] < best)) {
					bl = f[i][j][k+Z];
					best = d[i][j][k+Z];
				}
			}
			cout << best << endl;
		}

	}
	
	return 0;
}
