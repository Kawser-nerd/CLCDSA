#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int n,q,k;
int m,head[300020],next[300020],to[300020];
long long len[300020],dis[300020];
bool visited[300020];

void dfs(int x,int y, long long d){
    dis[x]=d;
    visited[x]=true;
    for (int e=head[x]; e!=-1; e=next[e]){
        if (visited[to[e]]==false){
           if (to[e]==y) {
                continue;
            }
            dfs(to[e],x,len[e]+d);
            visited[to[e]]=false;
        }
    }
}

int main(void){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        head[i]=-1;
    }
    for (int i=0; i<n-1; i++){
        int a,b;
        long long c;
        scanf("%d%d%lld",&a,&b,&c);
        a--;
        b--;
        next[m]=head[a];
        head[a]=m;
        to[m]=b;
        len[m]=c;
        m++;
        next[m]=head[b];
        head[b]=m;
        to[m]=a;
        len[m]=c;
        m++;
    }
    scanf("%d%d",&q,&k);
    dfs(k-1,-1,0);
    for (int i=0; i<q; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",dis[x-1]+dis[y-1]);
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:32:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%lld",&a,&b,&c);
         ^
./Main.c:46:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&q,&k);
     ^
./Main.c:50:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&x,&y);
         ^