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

char a[600][600];
int a1[600][600];
int a2[600][600];
int a3[600][600];
_int64 a4[600][600][2];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
	int i,j,k,l,t,m,n,x,o,p,st,b1,tmp1,tmp2;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d%d%d",&m,&n,&x);
		for (i=0;i<m;i++)
			scanf("%s",a[i]);
		st=m;
		if (n<m) st=n;
		b1=0;
		for (i=st;i>=3;i--)
		{
			for (j=0;j+i<=m;j++)
				for (k=0;k<n;k++)
				{
					if (j==0)
					{
						a1[j][k]=0;
						for (o=0;o<i;o++)
							a1[j][k]+=a[j+o][k]-'0';
					}
					else
					{
						a1[j][k]=a1[j-1][k];
						a1[j][k]-=a[j-1][k]-'0';
						a1[j][k]+=a[j+i-1][k]-'0';
					}
				}
			for (j=0;j<m;j++)
				for (k=0;k+i<=n;k++)
				{
					if (k==0)
					{
						a3[j][k]=0;
						for (o=0;o<i;o++)
							a3[j][k]+=a[j][k+o]-'0';
					}
					else
					{
						a3[j][k]=a3[j][k-1];
						a3[j][k]-=a[j][k-1]-'0';
						a3[j][k]+=a[j][k+i-1]-'0';
					}
				}
			for (j=0;j+i<=m;j++)
				for (k=0;k+i<=n;k++)
				{
					if (k==0)
					{
						a2[j][k]=0;
						for (o=0;o<i;o++)
							a2[j][k]+=a1[j][k+o];
					}
					else
					{
						a2[j][k]=a2[j][k-1];
						a2[j][k]-=a1[j][k-1];
						a2[j][k]+=a1[j][k+i-1];
					}
				}
			for (j=0;j+i<=m;j++)
			{
				for (k=0;k+i<=n;k++)
				{
					if ((j==0)||(k==0))
					{
						a4[j][k][0]=0;a4[j][k][1]=0;
						for (o=0;o<i;o++)
						{
							a4[j][k][0]+=a1[j][k+o]*(o*2-i+1);
							a4[j][k][1]+=a3[j+o][k]*(o*2-i+1);
						}
					}
					else
					{
						a4[j][k][0]=a4[j][k-1][0];
						a4[j][k][0]-=a2[j][k-1]*2;
						a4[j][k][0]-=a1[j][k-1]*(-2-i+1);
						a4[j][k][0]+=a1[j][k+i-1]*(i-1);

						a4[j][k][1]=a4[j-1][k][1];
						a4[j][k][1]-=a2[j-1][k]*2;
						a4[j][k][1]-=a3[j-1][k]*(-2-i+1);
						a4[j][k][1]+=a3[j+i-1][k]*(i-1);
					}
					tmp1=a4[j][k][0];tmp2=a4[j][k][1];
					tmp1-=(a[j][k]-'0')*(0-i+1);
					tmp2-=(a[j][k]-'0')*(0-i+1);
					tmp1-=(a[j][k+i-1]-'0')*(i-1);
					tmp2-=(a[j][k+i-1]-'0')*(0-i+1);
					tmp1-=(a[j+i-1][k]-'0')*(0-i+1);
					tmp2-=(a[j+i-1][k]-'0')*(i-1);
					tmp1-=(a[j+i-1][k+i-1]-'0')*(i-1);
					tmp2-=(a[j+i-1][k+i-1]-'0')*(i-1);
					if ((tmp1==0)&&(tmp2==0))
					{
						b1=1;break;
					}

				}
				if (b1==1) break;
			}
			if (b1==1) break;
		}
		printf("Case #%d: ",l+1);
		if (i<3) printf("IMPOSSIBLE\n");
		else printf("%d\n",i);
	}
	return 0;
}

