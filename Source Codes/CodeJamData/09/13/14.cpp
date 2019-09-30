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

double d[100];
double a[100][100];
double ans[100];
double cc[100][100];

int main()
{
    int i,j,k,n,c,l,t,o,p;
    double pp;
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    for (i=0;i<=50;i++)
    {
        cc[i][0]=1;
        cc[i][i]=1;
        for (j=1;j<i;j++)
            cc[i][j]=cc[i-1][j]+cc[i-1][j-1];
    }
    scanf("%d",&t);
    for (l=0;l<t;l++)
    {
        scanf("%d%d",&c,&n);
        ans[c]=0;
        
        for (i=c-1;i>=0;i--)
        {
            o=c-i;
            p=i;
            ans[i]=0;
            for (j=1;j<=n;j++)
            {
                if (j>o) continue;
                if (n-j>p) continue;
                pp=cc[o][j]*cc[p][n-j]/cc[c][n];
                ans[i]+=pp*(1+ans[i+j]);
            }
            if (n<=p)
            {
                pp=cc[o][0]*cc[p][n]/cc[c][n];
                ans[i]=(ans[i]+pp)/(1-pp);
            }
        }
        printf("Case #%d: %.7lf\n",l+1,ans[0]);
    }
	return 0;
}

