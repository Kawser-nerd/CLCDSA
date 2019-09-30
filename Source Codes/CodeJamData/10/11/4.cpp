#include<iostream>
using namespace std;
char a[60][60],b[60][60];
int t,cases,n,s;
int dx[]={1,1,1,0,-1,-1,-1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};
void init()
{
     scanf("%d%d",&n,&s);
     int i,j;
     for (i=0;i<n;i++)
     {
         getchar();
         for (j=0;j<n;j++)
             a[i][j]=getchar();
     }
}

void work()
{
     int i,j,k,l,x1,y1,ans;
     for (i=0;i<n;i++)
         for (j=0;j<n;j++) b[i][j]='.';
     for (i=0;i<n;i++)
     {
         k=0;
         for (j=n-1;j>=0;j--)
         {
             if (a[i][j]!='.') 
             {
                b[n-k-1][i]=a[i][j];
                k++;
             }
         }   
     }
     printf("Case #%d: ",t+1);
    /* for (i=0;i<n;i++)
     {
         for (j=0;j<n;j++)
         putchar(b[i][j]);
         putchar('\n');
     }*/
     ans=0;
     for (i=0;i<n;i++)
         for (j=0;j<n;j++)
         if (b[i][j]!='.')
            for (k=0;k<8;k++)
            {
                for (l=1;l<s;l++)
                {
                    x1=i+dx[k]*l;
                    y1=j+dy[k]*l;
                    if (x1<0||x1>=n||y1<0||y1>=n) break;
                    if (b[i][j]!=b[x1][y1]) break;
                }
                if (l==s)
                   if (b[i][j]=='B') ans|=1;
                   else ans|=2;
            }
     if (ans==0) puts("Neither");
     if (ans==1) puts("Blue");
     if (ans==2) puts("Red");
     if (ans==3) puts("Both");
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
