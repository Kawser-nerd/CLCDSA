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
const int MOD = 10009;
int i, j, k, m, n, l, u, ans[101], q;
int dict[101][101], ind[101], d[1<<4][101];
char ss[1000002];

int main() {
//	freopen("b.in", "r", stdin);

//	freopen("B-small-attempt0.in", "r", stdin);
//	freopen("B-small-attempt0.out", "w", stdout);

	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		printf("Case #%d:", tt);

		memset(dict, 0, sizeof(dict));

		string s;
		cin >> s; F0(i,SZ(s)) if (s[i] == '+') s[i] = ' '; stringstream is; is << s;
		cin >> k;
		F1(i,k) ans[i] = 0;
		cin >> n;
		F0(i,n) {
			cin >> s;
			F0(j,SZ(s))
				dict[i][s[j]-'a']++;
		}
		while (is >> s) {
			m = SZ(s);
			F0(i,m) {
				ind[i] = s[i] - 'a';
			}
			memset(d, 0, sizeof(d));

			F0(i,(1<<m)) {
				F0(j,n) {
					int pr = 1;
					F0(l,m) if ((1<<l)&i)
						pr = (pr * dict[j][ind[l]]) % MOD;
					d[i][1] = (d[i][1] + pr) % MOD;
				}
			}

			for (u = 2; u <= k; u++) {
				F0(i,(1<<m)) {
					F0(q,(1<<m)) if ((q&i)==q)
					F0(j,n) {
						int pr = 1, rem = 0;
						F0(l,m) if ((1<<l)&q)
							pr = (pr * dict[j][ind[l]]) % MOD;
						else if ((1<<l)&i) rem |= (1<<l);
						pr = (pr * d[rem][u-1]) % MOD;;
						d[i][u] = (d[i][u] + pr) % MOD;
					}
				}
			}
						
			F1(i,k) ans[i] = (ans[i] + d[(1<<m)-1][i]) % MOD;
		}
		F1(i,k) cout << " " << ans[i]; cout << endl;
	}
	
	return 0;
}
