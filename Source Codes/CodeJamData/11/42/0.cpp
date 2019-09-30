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


#define ASSERT(X) {if (!(X)) {printf("\n assertion failed at line %d\n",__LINE__);exit(0);}}

const int maxsize=500+5;

int sx,sy,ed;
int a0[maxsize][maxsize],s0[maxsize][maxsize];
int a1[maxsize][maxsize],s1[maxsize][maxsize];
int a2[maxsize][maxsize],s2[maxsize][maxsize];
char s[maxsize][maxsize];

int getsum(int a[maxsize][maxsize],int s[maxsize][maxsize],int x1,int y1,int x2,int y2)
{
	int R=s[x2][y2]+s[x1-1][y1-1]-s[x1-1][y2]-s[x2][y1-1];
	R-=a[x1][y1]+a[x1][y2]+a[x2][y1]+a[x2][y2];
	return R;
}
int main()
{
//	freopen("B.in","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		printf("Case #%d: ",case_id);
		scanf("%d%d%d",&sx,&sy,&ed);
		for (int i=1;i<=sx;i++) scanf("%s",s[i]+1);
		memset(s0,0,sizeof(s0));
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		for (int x=1;x<=sx;x++) for (int y=1;y<=sy;y++)
		{
			a0[x][y]=s[x][y]-'0';
			a1[x][y]=(s[x][y]-'0')*x;
			a2[x][y]=(s[x][y]-'0')*y;
			s0[x][y]=s0[x][y-1]+s0[x-1][y]-s0[x-1][y-1]+a0[x][y];
			s1[x][y]=s1[x][y-1]+s1[x-1][y]-s1[x-1][y-1]+a1[x][y];
			s2[x][y]=s2[x][y-1]+s2[x-1][y]-s2[x-1][y-1]+a2[x][y];
		}
		int R=-1;
		for (int k=min(sx,sy);k>=3;k--)
		{
			bool ok=false;
			for (int x=1;!ok && x<=sx-k+1;x++) for (int y=1;!ok && y<=sy-k+1;y++)
			{
				int g0=getsum(a0,s0,x,y,x+k-1,y+k-1);
				int g1=getsum(a1,s1,x,y,x+k-1,y+k-1);
				int g2=getsum(a2,s2,x,y,x+k-1,y+k-1);
				if (g1+g1==g0*(x+x+k-1) && g2+g2==g0*(y+y+k-1))
					ok=true;
			}
			if (ok) { R=k; break;}
		}
		if (R<0) printf("IMPOSSIBLE\n");
		else printf("%d\n",R);
		fflush(stdout);
	}
	return 0;
}
