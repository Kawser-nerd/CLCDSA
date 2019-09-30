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

vector<int> aa[110];

int a[400][400];
int liu[400][400];
int p[400];
int q[400];

int solve(int s,int t,int n) 
{ 
	int i,j,ans,top,bottom,x,y,max;
    int used[4000];
    int zhan[4000];
    int p[4000];
    ans=0;
    memset(liu,0,sizeof(liu));
    while (1)
    {
        memset(used,0,sizeof(used));
        used[s]=1;
        zhan[0]=s;
        top=0;bottom=1;
        while (top<bottom)
        {
            x=zhan[top];
            for (i=0;i<n;i++)
                if (used[i]==0)
                {
                    if ((liu[x][i]<a[x][i])||(liu[i][x]>0))
                    {
                        p[i]=x;
                        used[i]=1;
                        zhan[bottom]=i;
                        bottom++;
                    }
                }
            top++;
        }
        if (used[t]==0) break;
        max=10000;
        x=t;
        while (x!=s)
        {
            if (liu[x][p[x]]>0)
            {
                if (liu[x][p[x]]<max) max=liu[x][p[x]];
            }
            else
            {
                if (a[p[x]][x]-liu[p[x]][x]<max) max=a[p[x]][x]-liu[p[x]][x];
            }
            x=p[x];
        }
        x=t;
        while (x!=s)
        {
            if (liu[x][p[x]]>0)
            {
                liu[x][p[x]]-=max;
            }
            else
            {
                liu[p[x]][x]+=max;
            }
            x=p[x];
        }
        ans+=max;
    }
    return ans;
} 

int main()
{
    int i,j,k,l,t,m,n,b1,ans,x;
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&t);
    for (l=0;l<t;l++)
    {
        scanf("%d%d",&m,&n);
        for (i=0;i<m;i++)
        {
            aa[i].clear();
            for (j=0;j<n;j++)
            {
                scanf("%d",&x);
                aa[i].push_back(x);
            }
        }
        sort(aa,aa+m);
        memset(a,0,sizeof(a));
        for (i=0;i<m;i++)
        {
            a[0][i+1]=1;
            a[m+1+i][m+m+1]=1;
        }
        for (i=0;i<m;i++)
        {
            for (j=i+1;j<m;j++)
            {
                b1=1;
                for (k=0;k<n;k++)
                    if (aa[i][k]>=aa[j][k]) b1=0;
                if (b1==1)
                {
                    a[i+1][m+1+j]=1;
                }
            }
        }
        ans=solve(0,m+m+1,m+m+2);
        printf("Case #%d: %d\n",l+1,m-ans);
    }
	return 0;
}

