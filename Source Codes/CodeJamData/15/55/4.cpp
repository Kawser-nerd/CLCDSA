#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define repn(i,l,r,s) for (int i=(l); i<=(r); i+=s)
#define repdn(i,r,l,s) for (int i=(r); i>=(l); i-=s)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#ifdef DEBUG
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif

int n, d;
int inp[5010];
int prc[5010];
void lemon() {
	scanf("%d%d", &n, &d);
	int cnt = 0;
	rep(i,0,n-1) scanf("%d",&inp[i]);
	rep(i,0,n-2*d-1) {
		if (inp[i+2*d] != inp[i]) {
			puts("CHEATERS!");
			return;
		}
	}	
	int sum = 0;
	rep(i,0,2*d-1) sum += inp[i];
	if (sum % d) {
		puts("CHEATERS!");
		return;
	}
	for (int cv = d; cv > 0; cv /= 2) {
		inp[2*cv] = inp[0];
		//rep(i,0,2*cv) printf("%d ", inp[i]);
		//puts("");
		rep(i,0,cv-1) {
			if ((inp[i+1] - inp[i] + inp[cv+i] - inp[cv+i+1]) % 2) {
				puts("CHEATERS!");
				return;
			}
			int d = (inp[i+1] - inp[i] + (inp[cv+i] - inp[cv+i+1])) / 2;
			//printf("%d ", d);
			cnt += abs(d);
			rep(j,i+1,i+cv) inp[j] -= d;
		}
		//puts("");
	}
	debug(cnt);
	if (sum < cnt * d) {
		puts("CHEATERS!");
	} else {
		printf("%d\n", cnt);
	}
}

int main() {
    ios::sync_with_stdio(true);
    int n;
    scanf("%d", &n);
    rep(i,1,n) {
  	    printf("Case #%d: ", i);
  	    lemon();
    }
    return 0;
}