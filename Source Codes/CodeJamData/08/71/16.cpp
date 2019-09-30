#include <map>     
#include <set>     
#include <cmath>    
#include <cstdio>   
#include <vector>     
#include <string>     
#include <sstream>    
#include <iostream>    
#include <algorithm>     
using namespace std;     
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)     
#define FORE(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); ++it)     
#define SET(x, v) memset(x, v, sizeof (x))     
#define sz size()     
#define cs c_str()     
#define pb push_back     
#define mp make_pair
#define bpc __builtin_popcount
 
typedef long long ll;

map<string, int> mix;
vector<string> dat[1024];
int cach[1024];
int trav(int x) {
	int& ret = cach[x];
	if(ret!=-1) return ret;
	ret = 0;
	vector<int> sav;
	FOR(i,0,dat[x].sz) {
		int v = trav(mix[dat[x][i]]);
		sav.pb(v);
	}
	sort(sav.rbegin(), sav.rend());

	FOR(i,0,sav.sz) {
		int v = sav[i] + i;
		ret = max(v, ret);
	}	
	ret = max(ret, (int)dat[x].sz+1);
	return ret;
}
int main() {
	int e = 0, T;
	freopen("A.in","r",stdin);
	scanf("%d",&T);
	int n;
	while(T--) {
		scanf("%d",&n);
		char buf[128];
		mix.clear();
		FOR(i,0,n) {
			scanf("%s",buf);
			mix[buf] = i;
			dat[i].clear();
			int m;
			scanf("%d",&m);
			FOR(j,0,m) {
				scanf("%s",buf);
				if('A' <= buf[0] && buf[0] <='Z')
					dat[i].pb(buf);
			}
		}
		SET(cach, -1);
		int ans = trav(0);
		printf("Case #%d: %d\n", ++e, ans);
	}
	return 0;
}

