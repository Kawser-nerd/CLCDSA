#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
const int N=1e4+50;
const long long INF=0x3f3f3f3f3f3f3f3f;
typedef long long ll;
long double length[N][N];
long double d[N];
bool vis[N];
int n;
struct circular
{
   long double x,y;
   long double r=0;
}c[N];
void dijkstra(int s)
{
    for(int i=0;i<=n+1;i++)
        d[i]=INF;
    d[s]=0;
    while(1)
    {
        int v=-1;
        for(int i=0;i<=n+1;i++)
        {
            if(!vis[i]&&(v==-1||d[i]<d[v]))
                v=i;
        }
        if(v==-1)
         break;
        vis[v]=1;
        for(int i=0;i<=n+1;i++)
        d[i]=min(d[i],d[v]+length[v][i]);
    }
}
int main()
{
    long double x1,y1;
    scanf("%llf%llf%llf%llf",&c[0].x,&c[0].y,&x1,&y1);
    scanf("%d",&n);
    c[n+1].x=x1;
    c[n+1].y=y1;
    for(int i=1;i<=n;i++)
    {
        scanf("%llf%llf%llf",&c[i].x,&c[i].y,&c[i].r);
    }
    for(int i=0;i<=n+1;i++)
    {
        for(int j=i+1;j<=n+1;j++)
        {
           length[i][j]=(long double)sqrt((long double)(c[i].x-c[j].x)*(c[i].x-c[j].x)+(long double)(c[i].y-c[j].y)*(c[i].y-c[j].y));
            length[i][j]-=c[i].r+c[j].r;
            if(length[i][j]<0)
             length[i][j]=0;
            length[j][i]=length[i][j];
        }
    }
    dijkstra(0);
    printf("%.9Lf\n",d[n+1]);
    return 0;
} ./Main.cpp:44:13: warning: length modifier 'll' results in undefined behavior or no effect with 'f' conversion specifier [-Wformat]
    scanf("%llf%llf%llf%llf",&c[0].x,&c[0].y,&x1,&y1);
           ~^~~
./Main.cpp:44:17: warning: length modifier 'll' results in undefined behavior or no effect with 'f' conversion specifier [-Wformat]
    scanf("%llf%llf%llf%llf",&c[0].x,&c[0].y,&x1,&y1);
               ~^~~
./Main.cpp:44:21: warning: length modifier 'll' results in undefined behavior or no effect with 'f' conversion specifier [-Wformat]
    scanf("%llf%llf%llf%llf",&c[0].x,&c[0].y,&x1,&y1);
                   ~^~~
./Main.cpp:44:25: warning: length modifier 'll' results in undefined behavior or no effect with 'f' conversion specifier [-Wformat]
    scanf("%llf%llf%llf%llf",&c[0].x,&c[0].y,&x1,&y1);
                       ~^~~
./Main.cpp:50:17: warning: length modifier 'll' results in undefined behavior or no effect with 'f' conversion specifier [-Wformat]
        scanf("%llf%llf%llf",&c[i].x,&c[i].y,&c[i].r);
 ...