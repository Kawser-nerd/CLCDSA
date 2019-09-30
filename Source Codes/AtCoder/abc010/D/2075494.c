#include <stdio.h>
#include <stdlib.h>
#define inf 1e9
typedef struct{
    int to,cap,rev;
}per;
per p[101][101];
int used[101];
int cnt[101];

int Min(int a,int b){
    return a<b?a:b;
}

void add_edge(int from, int to){
    p[from][cnt[from]].to=to;
    p[from][cnt[from]].cap=1;
    p[from][cnt[from]].rev=cnt[to];
    p[to][cnt[to]].to=from;
    p[to][cnt[to]].cap=1;
    p[to][cnt[to]].rev=cnt[from];
    cnt[from]++;cnt[to]++;
}

int dfs(int v, int t, int f){
    if(v==t)return f;
    used[v]=1;
    int i;
    for(i = 0;i<cnt[v];i++){
        per *e= &p[v][i];
        if(used[e->to] || e->cap<=0)continue;
        int d = dfs(e->to,t,Min(f,e->cap));
        if(d>0){
            e->cap-=d;
            p[e->to][e->rev].cap+=d;
            return d;
        }
    }
    return 0;
}

int ford_fulkerson(int s, int t){
    int flow =0,f;
    while(1){
        memset(used,0,sizeof(used));
        f=dfs(s,t,inf);
        if(f==0)return flow;
        flow+=f;
    }
}

int main(){
    per p[101][101];
    int n,g,e;
    scanf("%d %d %d",&n,&g,&e);
    int i,j;
    for(i=0;i<g;i++){
        int tmp;
        scanf("%d",&tmp);
        add_edge(tmp,100);
    }
    for(i=0;i<e;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        add_edge(a,b);
    }
    printf("%d\n",ford_fulkerson(0,100));
} ./Main.c: In function ‘ford_fulkerson’:
./Main.c:45:9: warning: implicit declaration of function ‘memset’ [-Wimplicit-function-declaration]
         memset(used,0,sizeof(used));
         ^
./Main.c:45:9: warning: incompatible implicit declaration of built-in function ‘memset’
./Main.c:45:9: note: include ‘<string.h>’ or provide a declaration of ‘memset’
./Main.c: In function ‘main’:
./Main.c:55:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&n,&g,&e);
     ^
./Main.c:59:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&tmp);
         ^
./Main.c:64:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&a,&b);
         ^