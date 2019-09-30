#include <cstdio>
#include <cstdlib>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define INF (1<<30)
#define EPS 1e-8
#define LLD long long int
#define PB push_back
#define VI vector<int>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
using namespace std;

struct vect{
	double x, y;
};

int n, t;
int T[15];
double lo, hi, ret, a[15], b[15];
double mid;
vect p[30];

void solve(int tc){
	scanf("%d", &n);
	FOR(i,0,n) scanf("%d", &T[i]);

	lo = 0, hi = 100;
	ret = 100;
	FOR(i,0,200){
		mid = (lo + hi) * .5;
		t = 0;
		FOR(j,0,n){
			a[j] = T[j] - mid;
			b[j] = T[j] + mid;
			p[t++] = (vect){a[j], j};
			p[t++] = (vect){b[j], j};
		}

		int succ = 0;
		FOR(j,0,t) FOR(k,0,t) if (p[j].y != p[k].y){
			int ok = 1;
			double s = (p[k].x - p[j].x) / (p[k].y - p[j].y);
			FOR(r,0,n){
				double x = (r - p[j].y) * s + p[j].x;
				if (x < a[r] - EPS || x - EPS > b[r]) ok = 0;
			}
			if (ok) succ = 1;
		}
		if (succ) ret = mid, hi = mid;
		else lo = mid;
	}

	printf("Case #%d: %.9f\n", tc, ret + 1e-8);
}
int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
