#include<cstdio>
#include<algorithm>
#define INF 300000
using namespace std;
int main(){
    int g[300][300]={},n,m,a,b,t,ans=INF,s;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            g[i][j]=INF;
            g[j][i]=INF;
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&t);
        a--;
        b--;
        g[a][b]=min(g[a][b],t);
        g[b][a]=min(g[a][b],t);
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        s=0;
        for(int j=0;j<n;j++){
            s=max(s,g[i][j]);
        }
        ans=min(ans,s);
    }
    printf("%d\n",ans);
}