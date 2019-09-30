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

const int N=128;
char grid[N][N],orig[N][N];
void upg1(int i,int j) {
	if(grid[i][j]=='+') grid[i][j]='o'; else
	if(grid[i][j]=='.') grid[i][j]='x'; else
	assert(0);
}
void upg2(int i,int j) {
	if(grid[i][j]=='x') grid[i][j]='o'; else
	if(grid[i][j]=='.') grid[i][j]='+'; else
	assert(0);
}
pair<int,int> dec(int pd,int md) {
	int x=pd+md;
	if(x<0 || (x&1)) return {-1,-1};
	x>>=1;
	int y=pd-x;
	return {x,y};
}
void go(int tn) {
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) grid[i][j]='.';
	for(;m--;) {
		static char buf[4];
		int i,j;
		scanf("%s%d%d",buf,&i,&j);
		grid[i][j]=buf[0];
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) orig[i][j]=grid[i][j];

	vector<int> rs,cs;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) if(grid[i][j]=='x' || grid[i][j]=='o') goto j1;
		rs.pb(i);
		j1:;
	}
	for(int j=1;j<=n;j++) {
		for(int i=1;i<=n;i++) if(grid[i][j]=='x' || grid[i][j]=='o') goto j2;
		cs.pb(j);
		j2:;
	}
	vector<int> pd,md;
	for(int d=2;d<=n+n;d++) {
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
			if(i+j!=d) continue;
			if(grid[i][j]=='+' || grid[i][j]=='o') goto j3;
		}
		pd.pb(d);
		j3:;
	}
	for(int d=1-n;d<=n-1;d++) {
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
			if(i-j!=d) continue;
			if(grid[i][j]=='+' || grid[i][j]=='o') goto j4;
		}
		md.pb(d);
		j4:;
	}

	assert(rs.size() == cs.size());
	for(;rs.size() && cs.size();)
		upg1(rs.back(),cs.back()), rs.pop_back(),cs.pop_back();
	sort(md.begin(),md.end(),[](int a,int b){return abs(a)>abs(b); });
	set<int> bad;
	for(int x:md) {
		for(int y:pd) if(!bad.count(y)) {
			int i,j;
			tie(i,j)=dec(y,x);
			if(1<=i && i<=n && 1<=j && j<=n) {
				upg2(i,j);
				bad.insert(y);
				goto win;
			}
		}
		win:;
	}

	vector<pair<int,int> > ch;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(grid[i][j]!=orig[i][j])
		ch.pb({i,j});
	int sc=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
		if(grid[i][j]!='.') ++sc;
		if(grid[i][j]=='o') ++sc;
	}
	printf("Case #%d: %d %d\n",tn,sc,(int)ch.size());
	for(const auto &P:ch) printf("%c %d %d\n",grid[P.fi][P.se],P.fi,P.se);
}




int32_t main() {
	int T; scanf("%d",&T); for(int i=1;i<=T;i++) {
		go(i);
	}
}