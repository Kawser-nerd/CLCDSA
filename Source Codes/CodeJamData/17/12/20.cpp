// '
#include <bits/stdc++.h>
// #include <bits/extc++.h>
using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld TAU=2*acos(-1);
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;

const int N=52;
int r[N],q[N][N],l[N];

void go(int tn) {
	int n,p; scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++) scanf("%d",r+i);
	for(int i=0;i<n;i++) for(int j=0;j<p;j++) scanf("%d",q[i]+j);
	for(int i=0;i<n;i++) sort(q[i],q[i]+p), reverse(q[i],q[i]+p), l[i]=p;

	int ans=0;
	for(int srv=1;srv<=1000111;srv++) {
		for(;;) {
			for(int i=0;i<n;i++) {
				ll lo=(1LL*r[i]*srv*9 + 9)/10;
				for(;l[i] && q[i][l[i]-1] < lo;) --l[i];
			}
			for(int i=0;i<n;i++) if(!l[i]) goto done;
			for(int i=0;i<n;i++) {
				ll hi=(1LL*r[i]*srv*11)/10;
				if(q[i][l[i]-1] > hi) goto skip;
			}

			++ans;
			for(int i=0;i<n;i++) --l[i];
			continue;
			skip:;
			break;
		}
	}

done:;
	printf("Case #%d: %d\n",tn,ans);
}




int32_t main() {
	int T; scanf("%d",&T); for(int i=1;i<=T;i++) {
		go(i);
	}
}
