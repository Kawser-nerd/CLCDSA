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
char ss[1000002];

int main() {
//	freopen("d.in", "r", stdin);

	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);

//	freopen("D-large.in", "r", stdin);
//	freopen("D-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		printf("Case #%d: ", tt);
		string st;
		cin >> st;
		n = SZ(st);

		vector<int> v;
		ll s = 0;
		F0(i,n) if (st[i] == '?')
			v.push_back(i);
		else if (st[i] == '1')
			s += (1LL<<(n-i-1));
		
		m = SZ(v);
		F0(k,(1<<m)) {
			ll p = s;
			F0(i,SZ(v))
				if ((1<<i)&k)
					p += (1LL<<(n-v[i]-1));
			ll q = sqrt(1.0*p);
			if (q*q == p) {
				F0(i,SZ(v))
					if ((1<<i)&k)
						st[v[i]] = '1';
					else st[v[i]] = '0';
				cout << st << endl;
				break;
			}
		}

	}
	
	return 0;
}
