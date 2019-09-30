#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<list>

#define FOR(i,a,b) for(int i=(a); i<(int)(b); ++i)
#define FORD(i,a,b) for(int i=(a)-1; i>=(int)(b); --i)
#define FORE(i,C) for(__typeof(C.begin()) i=C.begin(); i!=C.end(); ++i)
#define MP make_pair
#define FI first
#define SE second
#define PB push_back

using namespace std;

typedef long long LL;

void testcase(int tNum) {

	int n,m,a;
	scanf("%d %d %d",&m,&n,&a);
	
	printf("Case #%d: ",tNum);
	
	if(a>n*m) {
		printf("IMPOSSIBLE\n");
		return;
	}
	
	int k = a/m;
	int p = a%m;
	if(p>0) {
		printf("0 0 %d %d %d %d\n",m,1,m-p,k+1);
	} else
		printf("0 0 %d %d %d %d\n",m,0,0,k);
	
}

int main() {

	int t;
	scanf("%d",&t);
	FOR(i,0,t) testcase(i+1);
	
	return 0;
}
