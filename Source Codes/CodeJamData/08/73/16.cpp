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
const double eps = 1.e-9;
typedef long long ll;
multiset<double> cand;
double dat[32][4];
int main() {
	int e= 0, T;
	freopen("C.in","r",stdin);
	scanf("%d",&T);
	int M, Q;
	while(T--) {
		bool ever_removed = false;
		scanf("%d%d",&M,&Q);
		cand.clear();
		FOR(i,0,Q) {
			scanf("%lf%lf%lf%lf",&dat[i][0],&dat[i][1],&dat[i][2],&dat[i][3]);
		}
		int qq = (1<<(Q*2));
		FOR(i,0,qq) {
			double v = 1.0;
			int x = i;
			FOR(j,0,Q) {
				v *= dat[j][x%4];
				x/=4;
			}
			if (v<eps)continue;
			cand.insert(v);
			if (cand.sz > M) {
				cand.erase(cand.begin());
				ever_removed = true;
			}
		}
		double ans = 0.0;
		FORE(i,cand)
			ans+= *i;
		if(ever_removed) {
			printf("Case #%d: %.6lf\n",++e, ans);
		} else {
			printf("Case #%d: %.6lf\n",++e,1.0);
		}
	}
	return 0;
}

