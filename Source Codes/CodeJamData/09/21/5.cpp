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

int i, j, k, m, n, l, T;
char c;
struct tree {
	double p;
	string name;
	int l, r;
};
tree t[10000];
void readtree(tree& a) {
	while (c != '(') {
		cin >> c;
	}
	c = '?';
	cin >> a.p;
	while (c != ')' && !isalpha(c)) cin >> c;
	
	if (c == ')') {
		a.l = a.r = -1;
		c = '?';
	} else {
		a.name = "";
		while (isalpha(c)) { a.name += c; cin >> c; }
		
		a.l = T++;
		readtree(t[a.l]);
		a.r = T++;
		readtree(t[a.r]);
		while (c != ')') {
			cin >> c;
		}
		c = '?';
	}

}


int main() {

	freopen("A.in", "r", stdin);

//	freopen("X-small-attempt0.in", "r", stdin);
//	freopen("X-small-attempt0.out", "w", stdout);

//	freopen("X-large.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int tt, tn; cin >> tn;

	F1(tt,tn) {
		printf("Case #%d:\n", tt);

		T = 1;
		cin >> l;
		c = '?';
		readtree(t[0]);

		cin >> m;
		while (m--) {
			string s;
			set<string> S;
			cin >> s;
			cin >> k;
			while (k--) {
				cin >> s;
				S.insert(s);
			}
			i = 0;
			double ans = 1.0;

			while (1) {
				ans *= t[i].p;
				if (t[i].l == -1) break;
				if (S.count(t[i].name)) {
					i = t[i].l;
				} else {
					i = t[i].r;
				}
			}
			printf("%.7lf\n", ans);
		}
	}
	
	return 0;
}
