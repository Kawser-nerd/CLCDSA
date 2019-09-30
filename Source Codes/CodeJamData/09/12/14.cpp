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

int d[30][30][4];
int a[30][30][4];
int used[30][30][4];

int getearly(int t,int x,int y)
{
    int tmp;
    tmp=t;
    t-=a[x][y][2];
    t+=a[x][y][3];
    t%=a[x][y][3];
    if (t<a[x][y][0]) return tmp;
    else return a[x][y][3]-t+tmp;
}

int getearly1(int t,int x,int y)
{
    int tmp;
    tmp=t;
    t-=a[x][y][2];
    t+=a[x][y][3];
    t%=a[x][y][3];
    if (t>=a[x][y][0]) return tmp;
    else return a[x][y][0]-t+tmp;
}

int main()
{
    int i,j,k,bi,bj,bk,tmp,m,n,l,t,min;
    //freopen("pb.in","r",stdin);
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&t);
    for (l=0;l<t;l++)
    {
        scanf("%d%d",&m,&n);
        for (i=0;i<m;i++)
            for (j=0;j<n;j++)
            {
                for (k=0;k<3;k++)
                {
                    scanf("%d",&a[i][j][k]);
                }
                a[i][j][3]=a[i][j][0]+a[i][j][1];
                a[i][j][2]%=a[i][j][3];
            }
        memset(used,0,sizeof(used));
        for (i=0;i<m;i++)
            for (j=0;j<n;j++)
                for (k=0;k<4;k++)
                    d[i][j][k]=2000000000;
        d[m-1][0][0]=0;
        while (1)
        {
            min=2000000000;
            for (i=0;i<m;i++)
                for (j=0;j<n;j++)
                    for (k=0;k<4;k++)
                        if ((used[i][j][k]==0)&&(d[i][j][k]<min))
                        {
                            min=d[i][j][k];
                            bi=i;bj=j;
                            bk=k;
                        }
            if (min==2000000000) break;
            used[bi][bj][bk]=1;
            if (bk%2==0)
            {
                if (bj>0)
                {
                    if (min+2<d[bi][bj-1][bk+1])
                        d[bi][bj-1][bk+1]=min+2;
                }
                tmp=getearly1(min,bi,bj)+1;
                if (tmp<d[bi][bj][bk+1])
                    d[bi][bj][bk+1]=tmp;
            }
            if (bk%2==1)
            {
                if (bj+1<n)
                    if (min+2<d[bi][bj+1][bk-1])
                        d[bi][bj+1][bk-1]=min+2;
                tmp=getearly1(min,bi,bj)+1;
                if (tmp<d[bi][bj][bk-1])
                    d[bi][bj][bk-1]=tmp;
            }
            if (bk/2==0)
            {
                if (bi+1<m)
                    if (min+2<d[bi+1][bj][bk+2])
                        d[bi+1][bj][bk+2]=min+2;
                tmp=getearly(min,bi,bj)+1;
                if (tmp<d[bi][bj][bk+2])
                    d[bi][bj][bk+2]=tmp;
            }
            if (bk/2==1)
            {
                if (bi>0)
                    if (min+2<d[bi-1][bj][bk-2])
                        d[bi-1][bj][bk-2]=min+2;
                tmp=getearly(min,bi,bj)+1;
                if (tmp<d[bi][bj][bk-2])
                    d[bi][bj][bk-2]=tmp;
            }
        }
        printf("Case #%d: %d\n",l+1,d[0][n-1][3]);
    }
	return 0;
}

