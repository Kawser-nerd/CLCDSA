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

template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}

#define ASSERT(X) {if (!(X)) {printf("\n assertion failed at line %d\n",__LINE__);exit(0);}}

const int maxn=400+5;
const int maxm=2000+5;

int n,m;
bool e[maxn][maxn];
int deg[maxn],g[maxn][maxn];
int d[maxn],q[maxn];
int f[maxn][maxn];

int solve(int a,int b)
{
	if (a==0) return 0;
	int &ret=f[a][b];
	if (ret>=0) return ret;
	ret=0;
	for (int p=0;p<deg[a];p++) 
	{
		int key=g[a][p];
		if (d[key]<0 || d[key]+1!=d[a]) continue;
		int cnt=0;
		for (int i=0;i<deg[key];i++)
		{
			int other=g[key][i];
			if (other==a) continue;
			if (a!=1 && e[a][other]) continue;
			if (b!=1 && e[b][other]) continue;
			cnt++;
		}
		checkmax(ret,cnt+solve(key,a));
	}
	return ret;
}
int main()
{
//	freopen("D.in","r",stdin);
	freopen("D-small-attempt0.in","r",stdin);freopen("D-small-attempt0.out","w",stdout);
//	freopen("D-small-attempt1.in","r",stdin);freopen("D-small-attempt1.out","w",stdout);
//	freopen("D-small-attempt2.in","r",stdin);freopen("D-small-attempt2.out","w",stdout);
//	freopen("D-large.in","r",stdin);freopen("D-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		printf("Case #%d: ",case_id);
		memset(deg,0,sizeof(deg));
		memset(e,false,sizeof(e));
		scanf("%d%d",&n,&m);
		for (int i=0;i<m;i++)
		{
			char str[1024];
			scanf("%s",str);
			for (int j=0;str[j];j++) if (str[j]==',') str[j]=' ';
			int a,b;
			sscanf(str,"%d%d",&a,&b);
			g[a][deg[a]++]=b;
			g[b][deg[b]++]=a;
			e[a][b]=e[b][a]=true;
		}
		for (int i=0;i<n;i++) d[i]=-1;
		d[0]=0;
		int sizeq=0;
		q[sizeq++]=0;
		for (int cl=0;cl<sizeq;cl++) for (int key=q[cl],i=0;i<n;i++) if (e[key][i] && d[i]<0)
			d[i]=d[key]+1,q[sizeq++]=i;
		memset(f,255,sizeof(f));
		int r1=d[1]-1;
		int r2=solve(1,1)+1;
		printf("%d %d\n",r1,r2-r1);
		fflush(stdout);
	}
	return 0;
}
