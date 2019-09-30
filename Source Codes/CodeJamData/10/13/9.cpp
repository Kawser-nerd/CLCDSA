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

typedef long long int64;

const int M=1000000+5;

int g[M];
int64 h[M];

bool solve(int a,int b)
{
	if (a==0 || b==0) return true;
	if (a>b) return solve(b,a);
	if (g[b]>=0) return a<g[b];
	if (b-a>=a) return true;
	return !solve(a,b-a);
}
int64 calc(int a,int b)
{
	if (a<b) swap(a,b);
	int64 r=h[b];
	for (int i=b+1;i<=a;i++) r+=min(g[i]-1,b);
	return r;
}
int main()
{
//	freopen("C.in","r",stdin);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	memset(g,255,sizeof(g));
	for (int a=1;a<M;a++)
	{
		int low=0;
		int high=a;
		for (;low+1<high;)
		{
			int b=low+(high-low)/2;
			if (solve(a,b))
				low=b;
			else
				high=b;
		}
		g[a]=high;
	}
	h[0]=0;
	for (int a=1;a<M;a++) h[a]=h[a-1]+(g[a]-1)*2;
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		printf("Case #%d:",caseId);
		int a1,b1,a2,b2;
		scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
		a1--;
		b1--;
		int64 r=calc(a2,b2)+calc(a1,b1)-calc(a1,b2)-calc(a2,b1);
		printf(" %lld\n",r);
		fflush(stdout);
	}
	return 0;
}
