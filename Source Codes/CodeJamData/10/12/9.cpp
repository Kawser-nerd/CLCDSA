#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}

const int maxn=100+5;

int cD,cI,n,m,A[maxn];
int f[maxn][300];

int getCost(int last,int key)
{
	if (last<0) return 0;
	int d=abs(last-key);
	return (d==0)?0:((m==0)?100000000:(d-1)/m*cI);
}
int solve(int depth,int last)
{
	if (depth>=n) return 0;
	int &ret=f[depth][last+1];
	if (ret>=0) return ret;
	ret=100000000;
	if (last<0 || abs(last-A[depth])<=m) checkmin(ret,solve(depth+1,A[depth]));
	//Delete
	checkmin(ret,solve(depth+1,last)+cD);
	//Insert & Change
	for (int key=0;key<256;key++)
		checkmin(ret,solve(depth+1,key)+getCost(last,key)+abs(key-A[depth]));
	return ret;
}
int main()
{
//	freopen("B.in","r",stdin);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.ans","w",stdout);
	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		printf("Case #%d:",caseId);
		scanf("%d%d%d%d",&cD,&cI,&m,&n);
		for (int i=0;i<n;i++) scanf("%d",&A[i]);
		memset(f,255,sizeof(f));
		int r=solve(0,-1);
		printf(" %d\n",r);
		fflush(stdout);
	}
	return 0;
}
