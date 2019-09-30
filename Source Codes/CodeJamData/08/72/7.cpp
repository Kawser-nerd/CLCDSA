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
const int mod = 10007;
int n;
int dat[1024];
int main() {
	int e = 0, T;
	freopen("B.in","r",stdin);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		FOR(i,0,n) scanf("%d",&dat[i]);
		bool unknown = false;
		int ans = 0;
		if (n==1 || n==2 || n==3) unknown = true;
		else if (n==4) {
			int v1 = dat[1]+dat[2];
			int v2 = dat[0]+dat[3];
			if(v1%mod == v2%mod) {
				unknown = true;
			} else {
				ans = (dat[3]+dat[2]-dat[1] + mod) % mod;
			}
		} else {
			int a, b, c, d, e;
			a = dat[0], b = dat[1], c = dat[2], d = dat[3], e = dat[4];
			int ba = (b-a+mod)%mod;
			int cb = (c-b+mod)%mod;
			int dc = (d-c+mod)%mod;
			int ed = (e-d+mod)%mod;
			if (cb==ed) {
				unknown = true;
			} else {
				if (ba==dc) {
					ans = (e + (b-a) + mod)%mod;
				}
			}
		}
		if(unknown)
			printf("Case #%d: UNKNOWN\n",++e);
		else {
			printf("Case #%d: %d\n",++e,ans);
		}
	}
	return 0;
}

