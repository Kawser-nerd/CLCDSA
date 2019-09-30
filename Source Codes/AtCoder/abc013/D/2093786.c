#include <stdio.h>
#include <stdlib.h>
int ans[200001][2];
int used[200001];
int g[200001];
int h[200001];
int c[200001];
int num=0;
int now=0;

void dfs(int s, int n, int cnt){
    g[n]=g[s];
    used[n]=1;
    ans[n][1]=cnt;
    h[now++]=n;
    if(ans[n][0]==s)return;
    dfs(s,ans[n][0],cnt+1);
}

void Swap(int a[],int x,int y){
    int tmp=a[x];
    a[x]=a[y];
    a[y]=tmp;
}

int main(){
    int n,m;
    long long d;
    scanf("%d %d %lld",&n,&m,&d);

    int tmp[200001];
    int i,j,k;
    for(i=1;i<=n;i++)tmp[i]=i;
    for(i=1;i<=n;i++)used[i]=0;
    //puts("a");
    for(i=0;i<m;i++){
        int t;
        scanf("%d",&t);
        Swap(tmp,t,t+1);
    }
    //puts("b");
    for(i=1;i<=n;i++){
        ans[tmp[i]][0]=i;
    }
    //puts("c");
    c[num++]=0;
    for(i=1;i<=n;i++){
        if(used[ans[i][0]]==0){
            g[ans[i][0]]=num-1;
            dfs(ans[i][0],ans[i][0],0);
            c[num++]=now;
        }
    }
    //puts("d");
    for(i=1;i<=n;i++){
        int start=c[g[ans[i][0]]];
        int end = c[g[ans[i][0]]+1];
        int q = (d+ans[i][1])%(end-start);
        printf("%d\n",h[start+q]);
    }
    //puts("e");
} ./Main.c: In function ‘main’:
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %lld",&n,&m,&d);
     ^
./Main.c:38:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&t);
         ^