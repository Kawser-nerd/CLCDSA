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

int i, j, k, m, n, l;
char ss[1000];
int cnt[100], d[100], cnt2[100];

void solve() {
	for (i = 0; i < n; i++) {
		for (j = d[i]+1; j < 10; j++) {
			F0(k,10) cnt2[k] = 0;
			cnt2[j]++;
			for(k=i+1;k<n;k++) cnt2[d[k]]++;

			int f = 1, all = 0;
			F1(k,9) {
				cnt2[k] = cnt[k] - cnt2[k];
				all += cnt2[k];
				if (cnt2[k] < 0) break;
			}
			if (k < 10 || all > i) continue;
			all = i - all;
			d[i] = j;
			while (all--) {
				d[--i] = 0;
			}
			F1(k,9) {
				while (cnt2[k]--) {
					d[--i] = k;
				}
			}
			i = n;
			while (d[i] == 0) i--;
			for (k = i; k >= 0; k--)
				cout << d[k];
			return;
		}
	}
}

int main() {
	freopen("B.in", "r", stdin);

//	freopen("X-small-attempt0.in", "r", stdin);
//	freopen("X-small-attempt0.out", "w", stdout);

//	freopen("X-large.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int tt, tn; cin >> tn; gets(ss);
	F1(tt,tn) {
		printf("Case #%d: ", tt);
		
		gets(ss);
		n = strlen(ss);
		memset(d, 0, sizeof(d));
		F0(i,n) d[i] = ss[n-i-1] - '0';
		F0(i,10) cnt[i] = 0;
		F0(i,n) cnt[ss[i]-'0']++;

		n = 50;
	
		solve();

		printf("\n");
	}
	
	return 0;
}
