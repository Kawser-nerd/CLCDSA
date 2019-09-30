#include<iostream>
using namespace std;
int dp[2][300],n,lim,cd,ci,t,cases,a[100],v[300];
void init()
{
     scanf("%d%d%d%d",&cd,&ci,&lim,&n);
     int i;
     for (i=0;i<n;i++) scanf("%d",&a[i]);     
}

void update(int x,int &y)
{
     if (y==-1) y=x;
     else y<?=x;
}

void work()
{
     int i,j,k,l,cur,ans;
     memset(dp[0],-1,sizeof(dp[0]));
     dp[0][256]=0;
     cur=0;
     for (i=0;i<n;i++)
     {
         cur=1-cur;
         memset(dp[cur],-1,sizeof(dp[cur]));
         memset(v,0,sizeof(v));
         while (1)
         {
               k=-1;
               for (j=0;j<=256;j++)
               if (!v[j])
                  if (k==-1) k=j;
                  else
                  if (dp[1-cur][k]==-1) k=j;
                  else
                  if (dp[1-cur][k]>dp[1-cur][j]) k=j;
               if (k==-1) break;
               if (dp[1-cur][k]==-1) break;
               v[k]=1;
               for (l=0;l<256;l++)
               if (k==256||abs(k-l)<=lim)
               update(dp[1-cur][k]+ci,dp[1-cur][l]);
         }
         for (j=0;j<=256;j++)
         if (dp[1-cur][j]!=-1)
         {
            update(dp[1-cur][j]+cd,dp[cur][j]);
            for (k=0;k<256;k++)
            if (j==256||abs(j-k)<=lim)
            update(dp[1-cur][j]+abs(a[i]-k),dp[cur][k]);
         }
     }    
     ans=-1;
     for (i=0;i<=256;i++)
     update(dp[cur][i],ans);
     printf("Case #%d: %d\n",t+1,ans);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for (scanf("%d",&cases),t=0;t<cases;t++)
    {
        init();
        work();
    }
    return 0;
}
