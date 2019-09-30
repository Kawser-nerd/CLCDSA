#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=110;
int a[MAXN];
int f[MAXN][300];
int n,m,Dval,Ival,ans,num,tot;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("ou.txt","w",stdout);
    scanf("%d",&tot);
    num=0;
    while (tot--)
      {
        ++num;
        scanf("%d%d%d%d",&Dval,&Ival,&m,&n);
        for (int i=1;i<=n;++i)   scanf("%d",&a[i]);
        for (int i=0;i<256;++i)  f[0][i]=0;
        for (int i=1;i<=n;++i)
          for (int j=0;j<256;++j)
            {
              f[i][j]=2147483647;
              for (int k=0;k<256;++k)
                {
                  if (j==k && f[i][j]>f[i-1][k]+Dval)   f[i][j]=f[i-1][k]+Dval;
                  if (m!=0 && k!=j && f[i][j]>f[i-1][k]+((labs(k-j)-1)/m)*Ival+labs(j-a[i]))
                    f[i][j]=f[i-1][k]+((labs(k-j)-1)/m)*Ival+labs(j-a[i]);
                  if (labs(k-j)<=m && f[i][j]>f[i-1][k]+labs(j-a[i]))
                    f[i][j]=f[i-1][k]+labs(j-a[i]);
                }
            }
        ans=2147483647;
        for (int i=0;i<256;++i)
          if (f[n][i]<ans)
            ans=f[n][i];
        printf("Case #%d: %d\n",num,ans);
      }
}
