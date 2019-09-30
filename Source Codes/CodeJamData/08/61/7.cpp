#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<utility>

using namespace std;

const int inf = 2147483647;
const double eps =1e-7;

#define lowbit(x) ((x)&-(x))
inline int cnt(int x){int ret = 0; while(x){ret+=x%2;x/=2;} return ret;}

multimap<int,bool> X,Y,XX,YY;
multimap<int,bool>::iterator it,it2;
multimap<int,bool>::reverse_iterator itr;
int x[1000],y[1000];
char s[1000][20];
int n,m;

int main()
{
	freopen("p1.in","r",stdin);
	freopen("p1.out","w",stdout);
	int ntest;
	scanf("%d",&ntest);
	for(int test=1;test<=ntest;test++)
	{
		int v = 0;
		scanf("%d",&n); X.clear(); Y.clear(); XX.clear(); YY.clear();
		int Xmin=inf,Xmax=-inf,Ymin=inf,Ymax=-inf;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%s",&x[i],&y[i],&s[i]);
			if(*s[i]=='B')
			{
				if(x[i]<Xmin) Xmin=x[i];
				if(x[i]>Xmax) Xmax=x[i];
				if(y[i]<Ymin) Ymin=y[i];
				if(y[i]>Ymax) Ymax=y[i];
				v = 1;
			}
			else 
			{
				scanf("%*s");
			}
		}

		scanf("%d",&m);
		printf("Case #%d:\n",test);
		for(int i=0;i<m;i++)
		{
			int tx,ty;
			scanf("%d%d",&tx,&ty);
			int u = 2;
		
			if(v==0)
			{
				u=1;
				for(int i=0;i<n;i++)
				{
					if(x[i]==tx && y[i]==ty) u = 0;
				}
				if(u==2) printf("BIRD\n");
				else if(u==1) printf("UNKNOWN\n");
				else if(u==0) printf("NOT BIRD\n");
				continue;
			}

			if(tx>=Xmin && tx<=Xmax && ty>=Ymin && ty<=Ymax)
			{
				u = 2;
			}
			else
			{
				u = 1;
				for(int i=0;i<n;i++)
				{
					if(*s[i]=='N')
					{
						if(x[i]<=Xmin && y[i]<=Ymin)
						{
							if(tx<=x[i] && ty<=y[i]) u = 0;
						}
						else
						if(x[i]>=Xmax && y[i]<=Ymin)
						{
							if(tx>=x[i] && ty<=y[i]) u = 0;
						}
						else
						if(x[i]<=Xmin && y[i]>=Ymax)
						{
							if(tx<=x[i] && ty>=y[i]) u = 0;
						}
						else
						if(x[i]>=Xmax && y[i]>=Ymax)
						{
							if(tx>=x[i] && ty>=y[i]) u = 0;
						}
						else if(x[i]<Xmin)
						{
							if(tx<=x[i]) u = 0;
						}
						else if(x[i]>Xmax)
						{
							if(tx>=x[i]) u = 0;
						}
						else if(y[i]<Ymin)
						{
							if(ty<=y[i]) u = 0;
						}
						else if(y[i]>Ymax)
						{
							if(ty>=y[i]) u = 0;
						}
					}
				}
			}

			if(u==2) printf("BIRD\n");
			else if(u==1) printf("UNKNOWN\n");
			else if(u==0) printf("NOT BIRD\n");
		}
	}
	return 0;
}
