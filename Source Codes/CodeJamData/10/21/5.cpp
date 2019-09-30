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

int i, j, k, m, n, l, ans;
string s;


struct tree {
	map<string, tree> M;
};

char ss[1000002];
tree *T, *H;

int main() {
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);

//	freopen("A-small-attempt0.in", "r", stdin);
//	freopen("A-small-attempt0.out", "w", stdout);

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		T = new tree();
		ans = 0;
		cin >> n >> m;
		F0(j,n) {
			cin >> s;
			F0(i,SZ(s)) if (s[i] == '/') s[i] = ' ';
			istringstream is(s);
			H = T;
			while (is >> s) {
				if (H->M.count(s)) {
				} else {
					H->M[s] = tree();
				}
				H = &H->M[s];
			}
		}
		F0(j,m) {
			cin >> s;
			F0(i,SZ(s)) if (s[i] == '/') s[i] = ' ';
			istringstream is(s);
			H = T;
			while (is >> s) {
				if (H->M.count(s)) {
				} else {
					ans++;
					H->M[s] = tree();
				}
				H = &H->M[s];
			}
		}

		printf("Case #%d: ", tt);

		cout << ans << endl;
	}

	return 0;
}
