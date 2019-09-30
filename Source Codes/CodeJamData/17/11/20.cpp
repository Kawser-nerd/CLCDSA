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

bool cute(const string &s) {
	for(char c:s) if(c!='?') return 1;
	return 0;
}

void improve(string &s) {
	assert(cute(s));
	char d='?';
	for(char c:s) if(c!='?') { d=c; goto ww; }
	assert(0);
ww:;
	for(char &c:s) {
		if(c!='?') d=c;
		c=d;
	}
}
void go(int tn) {
	printf("Case #%d:\n",tn);
	int n,m; cin>>n>>m;
	vector<string> grid;
	for(int i=0;i<n;i++) {
		string s; cin>>s;
		grid.pb(s);
	}
	string prev=grid[0];
	for(int i=0;i<n;i++) {
		if(cute(grid[i])) {
			prev=grid[i];
			goto qq;
		}
	}
	assert(0);
	qq:;

	for(int i=0;i<n;i++) {
		if(cute(grid[i])) prev=grid[i];
		grid[i]=prev;
		improve(grid[i]);
	}
	for(int i=0;i<n;i++) cout<<grid[i]<<endl;
}




int32_t main() {
	int T; scanf("%d",&T); for(int i=1;i<=T;i++) {
		go(i);
	}
}
