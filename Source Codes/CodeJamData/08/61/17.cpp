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
#include <ctime> 

using namespace std;

int x[2000],y[2000];
char c[2000];

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);

	int i,j,l,t,m,n,maxx,minx,bmaxx,bminx,maxy,miny,bmaxy,bminy,b1,b2,xx,yy,b3,b4,b5;
	char s[1000];
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d",&n);
		maxx=-2000000;
		minx=2000000;
		maxy=-2000000;
		miny=2000000;
		b1=0;b2=0;
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			gets(s);
			j=0;
			while (s[j]==' ') j++;
			c[i]=s[j];
			if (c[i]=='B')
			{
				if (x[i]>maxx) maxx=x[i];
				if (x[i]<minx) minx=x[i];
				if (y[i]>maxy) maxy=y[i];
				if (y[i]<miny) miny=y[i];
			}
		}
		scanf("%d",&m);
		printf("Case #%d:\n",l+1);
		bmaxx=maxx;
		bminx=minx;
		bmaxy=maxy;
		bminy=miny;
		for (i=0;i<m;i++)
		{
			scanf("%d%d",&xx,&yy);
			b1=1;b2=1;
			if ((xx>=minx)&&(xx<=maxx)&&(yy>=miny)&&(yy<=maxy)) b2=0;
			if (xx>maxx) maxx=xx;
			if (xx<minx) minx=xx;
			if (yy>maxy) maxy=yy;
			if (yy<miny) miny=yy;
			for (j=0;j<n;j++)
				if (c[j]!='B')
				{
					if ((x[j]>=minx)&&(x[j]<=maxx)&&(y[j]>=miny)&&(y[j]<=maxy)) b1=0;
				}
			maxx=bmaxx;
			minx=bminx;
			maxy=bmaxy;
			miny=bminy;
			if ((b1==1)&&(b2==0))
			{
				printf("BIRD\n");
			}
			if ((b1==0)&&(b2==1))
			{
				printf("NOT BIRD\n");
			}
			if ((b1==1)&&(b2==1))
			{
				printf("UNKNOWN\n");
			}
		}
	}	
	return  0;
}