#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=52;
const int dx[4]={1,1,1,0};
const int dy[4]={-1,0,1,1};
char a[MAXN][MAXN];
int n,m,ans;
int tot,num,val;

bool edge(int x,int y)
{
     return (x>=0 && y>=0 && x<n && y<n);
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("ou.txt","w",stdout);
    scanf("%d",&tot);
    num=0;
    while (tot--)
      {
        ++num;
        scanf("%d%d\n",&n,&m);
        for (int i=0;i<n;++i)
          {
            for (int j=0;j<n;++j)
              scanf("%c",&a[j][n-i-1]);
            scanf("\n");
          }
        for (int i=0;i<n;++i)
          {
            int k=n-1;
            for (int j=n-1;j>=0;--j)
              if (a[j][i]!='.')
                {
                  swap(a[k][i],a[j][i]);
                  --k;
                }
          }
        ans=0;
        for (int i=0;i<n;++i)
          for (int j=0;j<n;++j)
            for (int k=0;k<4;++k)
              if (a[i][j]!='.' && edge(i+dx[k]*(m-1),j+dy[k]*(m-1)))
                {
                  if (a[i][j]=='R')   val=1;
                  else     val=2;
                  bool ok=true;
                  for (int l=0;l<m;++l)
                    if (a[i+l*dx[k]][j+l*dy[k]]!=a[i][j])
                      {
                        ok=false;
                        break;
                      }
                  if (!ok)   continue;
                  ans|=val;
                }
        printf("Case #%d: ",num);
        if (ans==0)     printf("Neither");
        if (ans==1)     printf("Red");
        if (ans==2)     printf("Blue");
        if (ans==3)     printf("Both");
        printf("\n");
      }
}        
