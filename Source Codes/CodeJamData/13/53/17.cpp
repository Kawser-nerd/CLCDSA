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

int n,m,p,a[33],b[33],c[33],x[33],y[33],w[33],d[33],f[33],ans;

int path(int s){
	for (int i=0;i<n;i++)d[i] = 1e9, f[i] = 0;;
	d[s] = 0;
	for (int i=0;i<n;i++){
		int o = 1e9, l;
		for (int j=0;j<n;j++)if (!f[j] && d[j] < o) {
			o =d[j];
			l=j;
		}
		f[l] = 1;
		for (int j=0;j<m;j++)if (x[j] == l && d[y[j]] > o + c[j]) {
			d[y[j]] = o+c[j];
		}
	}
	return d[1];
}

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	int T=0;
	cin >> T;
	for (int E=1;E<=T;E++){
		cin >> n >> m >> p;
		for (int i=0;i<m;i++)scanf("%d%d%d%d",&x[i],&y[i],&a[i],&b[i]),x[i]--,y[i]--;
		for (int i=0;i<p;i++)cin >> w[i], w[i] --;
		ans = -1;
		for (int g=1;g<=p;g++){
			int ok =0;
			for (int o=0;o<pw(m);o++) {
				for (int i=0;i<m;i++)if (o&pw(i))c[i] = a[i];else c[i] = b[i];
				int ss = 0;
				for (int i=0;i<g;i++) ss += c[w[i]];
				if (path(0) == path(y[w[g-1]]) + ss ) {
					ok =1;
					break;
				}
			}
			if (!ok) {
				ans = w[g-1] + 1;
				break;
			}
			
		}
		cout << "Case #" << E << ": ";
		if (ans == -1)puts("Looks Good To Me");else cout << ans << endl;
	}
	return 0;
}


