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

int n;

typedef pair<int, int> P;

int a[11111][4], s[11111];

int main() {

int nt, tt=0; scanf("%d", &nt); while(nt--){
	scanf("%d", &n);
	FOR(i,0,n)scanf("%d%d", &a[i][0], &a[i][1]);
	FOR(i,0,n) s[i] = 0;

	int ns = 0;
	int ans = 0;

	bool did = true;
	while(did){
		did = false;

		bool tdid = true;
		while(tdid){
			tdid = false;
			FOR(i,0,n) if(s[i] < 2 && a[i][1] <= ns){
				ns += 2-s[i];
				s[i] = 2;
				ans ++;
				tdid = did = true;
			}
		}

		int mx = -1;
		FOR(i,0,n) if(s[i] == 0 && a[i][0] <= ns){
			if(mx < 0 || a[i][1] > a[mx][1]){
				mx = i;
			}
		}
		if(mx >= 0){
			ns ++;
			s[mx] = 1;
			ans++;
			did = true;
		}
	}

	bool bad = false;
	FOR(i,0,n) if(s[i] < 2) bad = true;

	printf("Case #%d: ", ++tt);

	if(bad) printf("Too Bad\n"); else printf("%d\n", ans);
}
	return 0;
}


