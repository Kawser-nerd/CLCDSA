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
typedef pair< int, vector<pii> > state;
int i, j, k, m, n, l, o, ans, w[101][101], vis[101];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int ok(int x, int y) { return 0 <= x && x < m && 0 <= y && y < n && !w[x][y]; }
char ss[1000002];
vector<pii> v1, v2, vv;

void dfs(int j) {
	vis[j] = 1;
	for (int i = 0; i < o; i++)
		if ((abs(vv[i].first-vv[j].first) + abs(vv[i].second-vv[j].second)) == 1 && (!vis[i])) dfs(i);
}

map< state, int> M;

int main() {
// freopen("a.in", "r", stdin);

//	freopen("A-small-attempt3.in", "r", stdin);
//	freopen("A-small-attempt3.out", "w", stdout);

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		printf("Case #%d: ", tt);
		scanf("%d%d\n", &m, &n);
		v1.clear(); v2.clear();
		memset(w, 0, sizeof(w));
		F0(i,m) {
			gets(ss);
			F0(j,n) if (ss[j] == 'o') {
				v1.push_back(pii(i,j));
			} else if (ss[j] == 'x') {
				v2.push_back(pii(i,j));
			} else if (ss[j] == 'w') {
				v1.push_back(pii(i,j));
				v2.push_back(pii(i,j));
			} else if (ss[j] == '#') {
				w[i][j] = 1;
			} else if (ss[j] == '.') {
			} else throw 9;
		}
		o = SZ(v1);
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		M.clear();
		queue<state> Q;
		M[state(0, v1)] = 0;
		Q.push( state(0, v1) );

		state s1, s2;

		ans = -1;
		if (v1 == v2) ans = 0; else
		while (!Q.empty()) {
			s1 = Q.front();
			Q.pop();

			int dist = M[s1] + 1;
			v1 = s1.second;

			int i, j, k;

			F0(i,o)	F0(k,4) if (ans == -1) {
				pii p1 = v1[i], p2 = v1[i];
				p1.first += dx[k]; p2.first -= dx[k];
				p1.second += dy[k]; p2.second -= dy[k];
				if (!ok(p1.first, p1.second)) continue;
				if (!ok(p2.first, p2.second)) continue;
				F0(j,o) if (j != i) if (p1 == v1[j] || p2 == v1[j]) break;
				if (j != o) continue;

				vv = v1;
				
				vv[i] = p1;
				sort(vv.begin(), vv.end());
				if (vv == v2) {
					ans = dist;
					break;
				}

				F0(j,o) vis[j] = 0;
				dfs(0);
				F0(j,o) if (!vis[j]) break;

				if (j == o) {
					s2 = state(0, vv);
					if (!M.count(s2)) {
						Q.push(s2);
						M[s2] = dist;
					}
				} else if (s1.first == 0) {
					s2 = state(1, vv);
					if (!M.count(s2)) {
						Q.push(s2);
						M[s2] = dist;
					}
				}

			}
		//	cout << SZ(M) << endl;
		}
		while (!Q.empty()) Q.pop();
		cout << ans << endl;
	}
	
	return 0;
}
