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

int a[500][500];
int shortest[500];
int used[500];
char s[1000];
string ss;
int d[500][500];
vector<int> dd[500];

int main()
{
	//freopen("pd.in","r",stdin);
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
	int min,max,i,j,k,l,t,bi,x,y,jj,kk,o,p,best,ans,tmp,n,m,bj,oo;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d%d",&n,&m);
		memset(a,0,sizeof(a));
		for (i=0;i<m;i++)
		{
			scanf("%s",s);
			ss=s;
			p=ss.find_first_of(',');
			x=atoi(ss.substr(0,p).c_str());
			ss=ss.substr(p+1);
			y=atoi(ss.c_str());
			a[x][y]=1;
			a[y][x]=1;
		}
		for (i=0;i<n;i++) shortest[i]=2000000000;
		shortest[0]=0;
		memset(used,0,sizeof(used));
		for (i=0;i<n;i++)
		{
			min=2000000000;
			for (j=0;j<n;j++)
				if ((used[j]==0)&&(shortest[j]<min))
				{
					min=shortest[j];
					bj=j;
				}
			if (min==2000000000) break;
			used[bj]=1;
			max=min;
			for (j=0;j<n;j++)
				if (a[bj][j]==1)
					if (min+1<shortest[j])
						shortest[j]=min+1;
		}
		if (shortest[1]==1)
		{
			ans=1;
			best=0;
			for (i=0;i<n;i++)
				if (a[0][i]==1) best++;
			printf("Case #%d: %d %d\n",l+1,ans-1,best);
			continue;
		}
		memset(d,-1,sizeof(d));
		for (i=0;i<500;i++) dd[i].clear();
		for (i=0;i<n;i++)
			if (shortest[i]!=2000000000)
				dd[shortest[i]].push_back(i);
		for (i=0;i<dd[1].size();i++)
			if (a[0][dd[1][i]]==1)
				d[0][dd[1][i]]=1;
		ans=shortest[1];
		best=0;
		for (i=1;i+1<ans;i++)
		{
			for (j=0;j<dd[i-1].size();j++)
				for (k=0;k<dd[i].size();k++)
					if (d[dd[i-1][j]][dd[i][k]]!=-1)
					{
						jj=dd[i-1][j];
						kk=dd[i][k];
						for (o=0;o<dd[i+1].size();o++)
							if (a[kk][dd[i+1][o]]==1)
							{
								oo=dd[i+1][o];
								tmp=d[jj][kk];
								for (p=0;p<dd[i].size();p++)
									if ((a[jj][dd[i][p]]==1)||(a[kk][dd[i][p]]==1)||(a[oo][dd[i][p]]==1))
										tmp++;
								if ((d[kk][oo]==-1)||(tmp>d[kk][oo]))
									d[kk][oo]=tmp;
							}
					}
		}
		for (j=0;j<dd[ans-2].size();j++)
			for (k=0;k<dd[ans-1].size();k++)
				if ((d[dd[ans-2][j]][dd[ans-1][k]]!=-1)&&(a[dd[ans-1][k]][1]==1))
				{
					jj=dd[ans-2][j];
					kk=dd[ans-1][k];
					tmp=d[dd[ans-2][j]][dd[ans-1][k]];
					for (p=0;p<dd[ans-1].size();p++)
						if ((a[jj][dd[ans-1][p]]==1)||(a[kk][dd[ans-1][p]]==1))
							tmp++;
					for (p=0;p<dd[ans].size();p++)
						if ((a[jj][dd[ans][p]]==1)||(a[kk][dd[ans][p]]==1))
							tmp++;
					if (tmp-ans>best) best=tmp-ans;
				}
		printf("Case #%d: %d %d\n",l+1,ans-1,best);
	}
	return 0;
}

