#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define MAX 512+10           
char buf[MAX][MAX];
int flag[MAX][MAX]={0};
int f[MAX][MAX][MAX]={0};
int size[MAX],num[MAX],len;

void zhuanhua(int j,int k,char ch)
{
    int x,i;
    if (isdigit(ch)) x=ch-'0';
    else x=ch-'A'+10;
    for (i=k*4;i>=k*4-4+1;i--)
    {
        buf[j][i]=x%2;        
        x=x/2;
    }
}

void work(int min,int m,int n)
{
     int i,j,k,t;
//     memset(f,0,sizeof(f));
     for (i=1;i<=m;i++) for (j=1;j<=n;j++) for (k=1;k<=min;k++) f[i][j][k]=0;
     for (i=1;i<=m;i++) for (j=1;j<=n;j++) f[i][j][1]=1;
     for (i=1;i<=m-1;i++)
         for (j=1;j<=n-1;j++)
         {
             if (buf[i][j]==buf[i][j+1] || buf[i][j]==buf[i+1][j] || buf[i+1][j+1]==buf[i][j+1] || buf[i+1][j+1]==buf[i+1][j]) f[i][j][2]=0;
             else f[i][j][2]=1;
         }
     for (t=3;t<=min;t++)
     {
         for (i=1;i<=m-t+1;i++)
             for (j=1;j<=n-t+1;j++)
                 if (f[i][j][t-1] && f[i+1][j][t-1] && f[i][j+1][t-1] && f[i+1][j+1][t-1]) f[i][j][t]=1;
                 else f[i][j][t]=0;
     }
}

void find(int min,int m,int n)
{
    int i,j,ii,jj,t;
//    memset(flag,0,sizeof(flag));
    for (i=1;i<=m;i++) for (j=1;j<=n;j++) flag[i][j]=0;
    memset(size,0,sizeof(size));
    memset(num,0,sizeof(num));
    len=0;
    for (t=min;t>=1;t--)
    {
        for (i=1;i<=m-t+1;i++)
            for (j=1;j<=n-t+1;j++)
                if (f[i][j][t] && !flag[i][j] && !flag[i+t-1][j+t-1] && !flag[i+t-1][j] && !flag[i][j+t-1])
                {  
                    if (len==0)
                    {
                        len++;
                        size[len]=t;
                        num[len]++;
                    }
                    else if (len>0 && t==size[len])
                    {
                        num[len]++;
                    }
                    else if (len>0 && t<size[len])
                    {
                        len++;
                        size[len]=t;
                        num[len]++;
                    }
                    for (ii=i;ii<=i+t-1;ii++)
                        for (jj=j;jj<=j+t-1;jj++) flag[ii][jj]=1;
                }
    }
}

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int t,m,n,min;
    int i,j,k;
    char ch;
    scanf("%d",&t);
    for (i=1;i<=t;i++)
    {
        scanf("%d%d",&m,&n); getchar();
        min=m<n?m:n;
        for (j=1;j<=m;j++)
        {
            for (k=1;k<=n/4;k++) { ch=getchar(); zhuanhua(j,k,ch); }
            getchar();
        }
        work(min,m,n);
        find(min,m,n);
        printf("Case #%d: %d\n",i,len);
        for (k=1;k<=len;k++) printf("%d %d\n",size[k],num[k]);
    }
    return 0;
}
