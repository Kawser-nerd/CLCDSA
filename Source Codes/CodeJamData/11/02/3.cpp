#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;
typedef unsigned __int64 ULL;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

clock_t start=clock();

int main()
{
	freopen("b2.in","r",stdin);
	freopen("b2.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		int i,j,k;
		int c;
		scanf("%d",&c);
		char sc[111][5];
		for(i=0;i<c;i++)
			scanf("%s",sc[i]);
		int d;
		scanf("%d",&d);
		char sd[111][5];
		for(i=0;i<d;i++)
			scanf("%s",sd[i]);
		int n;
		char s[111];
		scanf("%d%s",&n,s);
		char w[111];
		int len=0;
		for(j=0;j<n;j++)
		{
			w[len++]=s[j];w[len]=0;
			while(len>=2)
			{
				for(i=0;i<c;i++)
					if(sc[i][0]==w[len-2] && sc[i][1]==w[len-1] || 
						sc[i][1]==w[len-2] && sc[i][0]==w[len-1])
					{
						len--;
						w[len-1]=sc[i][2];w[len]=0;
						break;
					}
				if(i==c)
				{
					for(i=0;i<d;i++)
					{
						for(k=0;k<len-1;k++)
							if(sd[i][0]==w[k] && sd[i][1]==w[len-1] ||
								sd[i][1]==w[k] && sd[i][0]==w[len-1])
							{
								len=0;w[len]=0;
								break;
							}
						if(len==0) break;
					}
					if(i==d) break;
				}
			}
		}
		printf("[");
		for(i=0;w[i];i++)
			printf("%c%s",w[i],w[i+1]?", ":"]\n");
		if(i==0) puts("]");
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
