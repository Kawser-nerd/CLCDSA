#include <stdio.h>

#define N 100001
#define setData(d,i,_from,_to,_cost,_next) do{(d)[i].from=(_from);(d)[i].to=(_to);(d)[i].cost=(_cost);(d)[i].next=(_next);}while(0);

typedef long long ll;

typedef struct _Data{
    int from;
    int to;
    ll cost;
    int next;
} Data;

Data d[N*2];
ll cost[N];
int tail[N];

int que[N];
int rp,wp;

int main(){
    int i;
    int n,a,b,c,q,k,x,y;
    int idx,to;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        tail[i]=0;
    }
    for(i=1;i<n;i++){
        scanf("%d %d %d",&a,&b,&c);
        setData(d,i,a,b,c,tail[a]);
        tail[a]=i;
        setData(d,N+i,b,a,c,tail[b]);
        tail[b]=N+i;
    }
    scanf("%d %d",&q,&k);
    for(i=0;i<=n;i++){
        cost[i]=-1;
    }
    cost[k]=0;
    que[0]=k;
    rp=0;
    wp=1;
    while(rp<wp){
        i=que[rp++];
        idx=tail[i];
        while(idx){
            to=d[idx].to;
            if(cost[to]<0){
                cost[to]=cost[i]+d[idx].cost;
                que[wp++]=to;
            }
            idx=d[idx].next;
        }
    }
    for(i=0;i<q;i++){
        scanf("%d %d",&x,&y);
        printf("%lld\n",cost[x]+cost[y]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:32:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d",&a,&b,&c);
         ^
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&q,&k);
     ^
./Main.c:59:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&x,&y);
         ^