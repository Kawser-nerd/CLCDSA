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
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)

const int oo=1000000;
const int maxsize=50000;

int n;
int f[maxsize][2];
int G[maxsize],C[maxsize],X[maxsize];

int calc(int x,int y,int op)
{
	if (op==1) return x&y;
	else return x|y;
}
int solve(int id,int exp)
{
	if (id>(n-1)/2) return (exp==X[id])?0:oo;
	int &ret=f[id][exp];
	if (ret!=-1) return ret;
	ret=oo;
	for (int left=0;left<2;left++)
		for (int right=0;right<2;right++)
		{
			if (calc(left,right,G[id])==exp)
				checkmin(ret,solve(id*2,left)+solve(id*2+1,right));
			if (C[id]==1 && calc(left,right,1-G[id])==exp)
				checkmin(ret,solve(id*2,left)+solve(id*2+1,right)+1);
		}
	return ret;
}
int main()
{
//	freopen("..\\input.txt","r",stdin);
//	freopen("..\\A-small-attempt0.in","r",stdin);freopen("..\\A-small-attempt0.out","w",stdout);
	freopen("..\\A-large.in","r",stdin);freopen("..\\A-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	int exp;
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		printf("Case #%d:",caseId);
		scanf("%d%d",&n,&exp);
		for (int i=1;i<=(n-1)/2;i++)
			scanf("%d%d",&G[i],&C[i]);
		for (int i=(n-1)/2+1;i<=n;i++)
			scanf("%d",&X[i]);
		memset(f,255,sizeof(f));
		int ret=solve(1,exp);
		if (ret==oo) 
			printf(" IMPOSSIBLE\n");
		else
			printf(" %d\n",ret);
		
	}
}