#include <stdio.h>
#include <stdlib.h>
#define INF 1e17
typedef long long ll;
typedef struct{
    int cnt;
    int to[1001];
    ll cost[1001];
} edge;

ll d[1001];
ll ans;
edge eg[1001];

int sol(int n,int s){
    int i;
    for(i=1;i<=n;i++){
        d[i]=INF;
    }
    d[s]=0;
    int f,t;
    for(i=0;i<n-1;i++){
        for(f=1;f<=n;f++){
            for(t=0;t<eg[f].cnt;t++){
                edge e=eg[f];
                if(d[f]!=INF&&d[e.to[t]]>d[f]+e.cost[t]){
                    d[e.to[t]]=d[f]+e.cost[t];
                }
            }
        }
    }
    ans=d[n];
    int flag[1001]={0};
    for(i=0;i<n;i++){
        for(f=1;f<=n;f++){
            for(t=0;t<eg[f].cnt;t++){
                edge e=eg[f];
                if(d[f]!=INF&&d[e.to[t]]>d[f]+e.cost[t]){
                    flag[e.to[t]]=1;
                }
                if(flag[f]){
                    flag[e.to[t]]=1;
                }
            }
        }
    }
    return flag[n];
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    int i,j;
    for(i=1;i<=1000;i++){
        eg[i].cnt=0;
    }
    for(i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        eg[a].to[eg[a].cnt]=b;
        eg[a].cost[eg[a].cnt]=-c;
        eg[a].cnt++;
    }
    int flag = sol(n,1);
    if(flag){
        puts("inf");
    }else{
        printf("%lld\n",-ans);
    }
} ./Main.c: In function ‘main’:
./Main.c:52:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&m);
     ^
./Main.c:60:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d",&a,&b,&c);
         ^