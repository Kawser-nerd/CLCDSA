#include<cstdio>
#include<cstring>
using namespace std;
int N,M;
int dist[105][105];
int Map[105][105];
bool vis[105][105];
const int inf=0x3f3f3f3f;
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        memset(dist,inf,sizeof(dist));
        memset(Map,0,sizeof(Map));
        int u,v,w;
        for(int i=0;i<M;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            Map[u][v]+=w;
            dist[u][v]=dist[v][u]=0;
            dist[u][v]+=w;
            dist[v][u]+=w;
        }
        for(int i=1;i<=N;i++)
        {
            dist[i][i]=0;
        }
        for(int k=1;k<=N;k++)
        {
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=N;j++)
                {
                    if(dist[i][j]>dist[i][k]+dist[k][j])
                    {
                        dist[i][j]=dist[i][k]+dist[k][j];
                        vis[i][j]=1;
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                //cout<<Map[i][j];
                if(Map[i][j])
                {
                    //cout<<'A'<<endl;
                    if((Map[i][j]>dist[i][j])&&vis[i][j])
                    {
                        ans++;
                    }
                }
            }
            //cout<<endl;
        }
        printf("%d\n",ans);
    }
}