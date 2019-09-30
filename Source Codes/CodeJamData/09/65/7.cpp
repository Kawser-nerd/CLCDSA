#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

#define fi first
#define se second

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)

#define MP make_pair
#define pb push_back

#define sqr(x) ((x)*(x))

typedef pair<int,int> PII;

int n;
string s[55];
pair<int,int> a[55];
int f[55];

bool cmp(const pair<int,int> &p1, const pair<int,int> &p2) {
	return (p1.se - p1.fi) < (p2.se - p2.fi);
}

inline bool giao(PII p1, PII p2) {
	return max(p1.fi, p2.fi) <= min(p1.se, p2.se);
}

inline bool trong(PII p1, PII p2) {
	return (p2.fi <= p1.fi && p1.se <= p2.se);
}

int main() {
	int ntest;
	scanf("%d", &ntest);	
	for(int test=1;test<=ntest;++test) {
		scanf("%d", &n);
		for(int i=0;i<2*n;++i) cin >> s[i];
		map<string,int> ma;
		for(int i=0;i<n;++i) a[i].fi=-1;
		int d = 0;
		for(int i=0;i<2*n;++i) {
			if(!ma.count(s[i])) { ma[s[i]] = d++; }
			int id = ma[s[i]];
			if(a[id].fi == -1) a[id].fi = i;
			else a[id].se = i;
		}
		sort( a, a + n, cmp);
		// for(int i=0;i<n;++i) cout << a[i].fi << " " << a[i].se << endl;
		int best = 1000000;
		for(int b=0;b<(1<<n);++b) {
			bool ok = true;
			for(int i=0;i<n;++i) if((b&(1<<i))==0) {
				for(int j=i+1;j<n;++j) if((b&(1<<j))==0) {
					if(giao(a[i],a[j]) && !trong(a[i], a[j])) ok = false;
				}
				if(!ok) break;
			}
			for(int i=0;i<n;++i) if((b&(1<<i))!=0) {
				for(int j=i+1;j<n;++j) if((b&(1<<j))!=0) {
					if(giao(a[i],a[j]) && !trong(a[i], a[j])) ok = false;
				}
				if(!ok) break;
			}
			if(!ok) continue;
			
			int r1 = 0;
			int r2 = 0;
			memset( f, 0, sizeof(f));
			for(int i=0;i<n;++i) {
				f[i] = 1;
				for(int j=0;j<i;++j) if(((b>>i)&1) == ((b>>j)&1)) {
					if(trong(a[j], a[i])) {
						f[i] >?= f[j] + 1;
					}
				}
				if((b&(1<<i))!=0) r1 >?= f[i];
				else r2 >?= f[i];
			}
			best <?= r1 + r2;
		}
		if(best == 1000000) best = -1;
		cout << "Case #" << test << ": " << best << endl;
	}
	return 0;
}
