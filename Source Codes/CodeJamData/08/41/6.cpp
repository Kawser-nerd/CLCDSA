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

const int INF = 1000000000;

struct Node {
	int val;
	int t;		//1-and, 0-or
	int cost;
	int canC;
};

const int mMax = 10005;

Node tabM[mMax];
int M;

int go(int v) {
	int &res = tabM[v].cost;
	if(res!=-1) return res;
	res = INF;
	
	go(2*v); go(2*v+1);
	if(tabM[v].t==1)
		tabM[v].val = (tabM[2*v].val==1&&tabM[2*v+1].val==1)?1:0; else
		tabM[v].val = (tabM[2*v].val==1||tabM[2*v+1].val==1)?1:0;
	
	int val=tabM[v].val, t=tabM[v].t, canC=tabM[v].canC;
	
	if(val==t) {
		res <?= min(go(2*v), go(2*v+1));
	} else if(tabM[2*v].val!=tabM[2*v+1].val) {
		if(canC) res <?= 1;
		if(tabM[2*v].val!=t)
			res <?= go(2*v); else
			res <?= go(2*v+1);
	} else {
		if(canC) res <?= 1 + min(go(2*v), go(2*v+1));
		res <?= go(2*v)+go(2*v+1);
	}
	
	return res;
	
}

void testcase(int tNum) {

	int v;
	scanf("%d %d",&M,&v);
	FOR(i,1,(M-1)/2+1) {
		scanf("%d %d",&tabM[i].t,&tabM[i].canC);
		tabM[i].cost = tabM[i].val = -1;
	}
	FOR(i,(M-1)/2+1,M+1) {
		scanf("%d",&tabM[i].val);
		tabM[i].cost = INF;
	}
	
	int res;
	go(1);
	
	if(tabM[1].val == v)
		res = 0; else
		res = go(1);
		
	printf("Case #%d: ",tNum);
		
	if(res>=INF)
		printf("IMPOSSIBLE\n"); else
		printf("%d\n",res);
	
}

int main() {

	int t;
	scanf("%d",&t);
	FOR(i,0,t) testcase(i+1);
	
	return 0;
}
