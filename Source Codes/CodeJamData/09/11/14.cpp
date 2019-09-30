#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<list>
#include<map>
#include<queue>

#define FOR(i,a,b) for(int i=(int)(a); i<(int)(b); ++i)
#define FORE(it,C) for(__typeof(C.begin()) it=C.begin(); it!=C.end(); ++it)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

using namespace std;

int vis[11][2000];

bool isHappy(int n, int k)
{
	if(n<2000) {
		if(vis[k][n]!=-1)
			return vis[k][n];
			
		if(n==1)
			return vis[k][n] = 1;
			
		vis[k][n] = 0;
	}
		
	int num = 0;
	int cur = n;
	while(cur) {
		int a = cur%k;
		cur /= k;
		num += a*a;
	}
	bool res = isHappy(num, k);
	
	if(n<2000)
		vis[k][n] = res;
	
	return res;
}

void testcase(int testNr) {
	
	vector<int> base;
	while(true) {
		int d;
		char c;
		scanf("%d%c",&d,&c);
		base.PB(d);
		if(c=='\n')
			break;
	}
	
	int cur = 2;
	while(true)
	{
		bool isOk = true;
		FORE(it,base) if(!isHappy(cur, *it)) {
			isOk = false;
			break;
		}
		if(isOk)
			break;
		else
			cur++;
	}
	
	printf("Case #%d: %d\n", testNr, cur);
	
}

int main() {
	memset(vis, -1, sizeof(vis));
	int t;
	scanf("%d",&t);
	FOR(i,0,t)
		testcase(i+1);
}
