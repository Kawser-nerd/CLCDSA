#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define Rep(i,n) for(int i=0;i<n;++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define MP make_pair
#define pb push_back

typedef vector<int> VI;
typedef pair<int,int> PII;

typedef long long LL;

int n;
LL a[33];
LL res = -1;
LL maxi;

int sign(LL x) {
	return x < 0 ? -1 : 1;	
}

void dfs(int i, int s, LL total) {
	if(s == (1<<n)-1) {
		total += abs(a[i]-a[0]);
		if(total <= maxi) {
			res >?= total;
		}
		return;
	}
	Rep(j,n) if((s&(1<<j))==0) {
		dfs( j, s | (1<<j), total + abs(a[i]-a[j]));
	}
}

int main() {
	int ntest;
	scanf("%d", &ntest);

	For(test,1,ntest) {
		cerr << "test = " << test << endl;
		
		scanf("%d",&n);
		Rep(i,n) cin >> a[i];
		cin >> maxi;
		
		res = -1;
		
		dfs( 0, 1, 0);
		
		printf("Case #%d: ", test);
		if(res == -1) cout << "NO SOLUTION" << endl;
		else cout << res << endl;
		fflush(stdout);
	}
    return 0;
}
