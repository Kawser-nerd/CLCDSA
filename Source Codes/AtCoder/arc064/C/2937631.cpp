#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
const int N=1005;
const double INF=23333333333333.0;
double road[N][N];
double dist[N];
double x[N],y[N],r[N];
int xs,xt,ys,yt;
int n;
double D(double x,double y,double xx,double yy){
    return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
bool vis[N];
void Dijkstra(){
    for(int i=1;i<=n;i++)
        dist[i]=road[n-1][i];
    int u=n-1;
    int cnt=1;
    vis[u]=1;
    while(cnt<n){
        double minv=INF;
        int x;
        for(int i=1;i<=n;i++)
            if(!vis[i]){
                if(dist[i]>dist[u]+road[u][i]){
                    dist[i]=dist[u]+road[u][i];
                }
                if(dist[i]<minv)
                    minv=dist[i],x=i;
            }
        u=x;
        vis[u]=1;
        cnt++;
    }
}
int main()
{
    scanf("%d%d%d%d",&xs,&ys,&xt,&yt);
    scanf("%d",&n);
    memset(dist,-1,sizeof dist);
    for(int i=1;i<=n;i++)
        scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
    n++;
    x[n]=xs,y[n]=ys,r[n]=0;
    n++;
    x[n]=xt,y[n]=yt,r[n]=0;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++){
            double f=D(x[i],y[i],x[j],y[j]);
            if(f<r[i]+r[j]){
                f=0;
            }
            else
                f-=r[i]+r[j];
            road[i][j]=road[j][i]=f;
        }
    Dijkstra();
    printf("%.10lf",dist[n]);
}