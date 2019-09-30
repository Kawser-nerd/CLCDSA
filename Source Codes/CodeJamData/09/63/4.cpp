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
const int MOD = 10007;
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, ans;
char ss[1000002];
char s[16][16];

map<string, int> M[5][5];

int rec(int i, int j) {
	if (j >= n) return rec(i+1, 0);
	if (i >= m) return 1;
	if (s[i][j] != '.') return rec(i, j+1);

	string t = "";
	for (int k = 0; k < n; k++) {
		if (k < j) t += s[i][k];
		else {
			if (i > 0) t += s[i-1][k];
			else t += "a";
		}
	}
	if (M[i][j].count(t)) return M[i][j][t];
	int ret = 0;

	char c1 = 'a', c2 = 'z';
	if (i > 0) c1 = max(c1, s[i-1][j]);
	if (j > 0) c1 = max(c1, s[i][j-1]);
	for (int k = i; k < m; k++) 
		for (int l = j; l < n; l++) if (s[k][l] != '.') { c2 = min(c2, s[k][l]); }
	for (char ch = c1; ch <= c2; ch++) {
		s[i][j] = ch;
		ret = (ret + rec(i, j+1)) % MOD;
	}
	s[i][j] = '.';
	//cout << i << " " << j <<  " " << t << " " << ret << endl;
	M[i][j][t] = ret;
	return ret;
}

int main() {
//	freopen("c.in", "r", stdin);

	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

//	freopen("C-large.in", "r", stdin);
//	freopen("C-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		scanf("%d %d\n", &m, &n);
		F0(i,m) gets(s[i]);
		F0(i,5) F0(j,5) M[i][j].clear();
		int f = 0;
		F0(i,m) F0(j,n) if (s[i][j] != '.') {
			for(k=i;k<m;k++) for(l=j; l<n; l++)
				if (s[k][l] != '.' && s[k][l] < s[i][j]) f = 1;
		}
		ans = 0;
		if (!f) {
			ans = rec(0, 0);
		}

		printf("Case #%d: ", tt);
	
		cout << ans << endl;
	}
	
	return 0;
}
