#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ll<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n;
long long a[55];
long double ans,ss;
long long v,l,r,c,e;

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	int T=0;
	cin >> T;
	for (int E=1;E<=T;E++){
		cin >> v >> n;
		for (int i=0;i<37;i++)a[i] = 0;
		for (int i=0;i<n;i++)cin >> a[i];
		sort(a,a+37);
		ans = 0;
		for (int g=1;g<=37;g++) {
			l = 0;
			for (int i=0;i<g;i++)l=max(l,a[i]);
			r = 1e15;
			while (l<r) {
				c = (l+r+1)/2;
				e = 0;
				for (int i=0;i<g;i++) {
					e += c - a[i];
				}
				for (int i=g;i<37;i++) {
					if (a[i] <= c) e += c + 1 - a[i];
				}
				if (e > v) r = c - 1;else l = c;
			}
			c = l;
			e = 0;
			ss = 0;
			for (int i=0;i<g;i++) {
				e += c - a[i];
				ss += (c - a[i]) * 36;
			}
			for (int i=g;i<37;i++) {
				if (a[i] <= c) e += c + 1 - a[i];
			}
			if (e <= v) ans = max(ans, ss / g - e);
		}
		cout << "Case #" << E << ": ";
		printf("%.7lf\n",(double)ans);
	}
	return 0;
}


