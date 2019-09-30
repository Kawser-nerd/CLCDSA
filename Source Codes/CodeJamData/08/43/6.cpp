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

struct Point {
	int x,y,z,p;
};

const int nMax = 1005;

Point tabN[nMax];

void testcase(int tNum) {

	int N;
	scanf("%d",&N);
	
	FOR(i,0,N)
		scanf("%d %d %d %d",&tabN[i].x,&tabN[i].y,&tabN[i].z,&tabN[i].p);
	
	double res = 0.0;
	
	FOR(i,0,N) FOR(j,i+1,N) res >?= (abs(tabN[i].x-tabN[j].x)+abs(tabN[i].y-tabN[j].y)+abs(tabN[i].z-tabN[j].z)) * 1.0 / (tabN[i].p+tabN[j].p);
	
	printf("Case #%d: %.6lf\n",tNum,res);
	
}

int main() {

	int t;
	scanf("%d",&t);
	FOR(i,0,t) testcase(i+1);
	
	return 0;
}
