#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cctype>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FORS(i,s) for(int i=0;(s)[i];i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back

int n, m;
double p[1111111];

int main() {

int nt, tt=0; scanf("%d", &nt); while(nt--){
	scanf("%d%d", &n, &m);
	FOR(i,0,n)scanf("%lf", &p[i]);

	double ans = 2.0 + m;

	double cp = 1.0;
	FOE(i,0,n){
		ans = min(ans, ((n-i)+(m-i)+1.0) + (1.0-cp)*(m+1.0));
		if(i==n) break;
		cp *= p[i];
	}

	printf("Case #%d: %.9f\n", ++tt, ans);
}
	return 0;
}


