#include <stdio.h>
#include <stdlib.h>
int N,Q;
int *cnt;
int *par[17];
int *depth;
int **tree;

void swap(int *a, int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void dfs(int v, int p, int d){
    par[0][v]=p;
    depth[v]=d;
    int i;
    for(i=0;i<cnt[v];i++){
        if(tree[v][i]!=p)dfs(tree[v][i],v,d+1);
    }
}

int lca(int a, int b){
    if (depth[a] > depth[b]) {
        swap(&a, &b);
    }
    int i;
    for(i=0;i<20;i++) {
        if ((depth[b] - depth[a]) >> i & 1) {
            b = par[i][b];
        }
    }
    if(a==b)return a;

    for(i=16;i>=0;i--){
        if(par[i][a]!=par[i][b]){
            a=par[i][a];
            b=par[i][b];
        }
    }
    return par[0][a];
}

int main(){
    int i,j;
    scanf("%d",&N);
    cnt = (int*)malloc(sizeof(int)*N);
    for(i=0;i<N;i++){
        cnt[i]=0;
    }
    for(i=0;i<17;i++){
        par[i] = (int*)malloc(sizeof(int)*N);
    }
    int (*in)[2] = (int*)malloc(sizeof(int)*N*2);
    depth = (int*)malloc(sizeof(int)*N);
    int x,y;
    for(i=0;i<N-1;i++){
        scanf("%d %d",&x,&y);
        x--;y--;
        in[i][0]=x;
        in[i][1]=y;
        cnt[x]++;
        cnt[y]++;
    }
    tree = (int**)malloc(sizeof(int*)*N);
    for(i=0;i<N;i++){
        tree[i]=(int*)malloc(sizeof(int)*cnt[i]);
    }
    int idx[100000]={0};
    for(i=0;i<N-1;i++){
        tree[in[i][0]][idx[in[i][0]]++] = in[i][1];
        tree[in[i][1]][idx[in[i][1]]++] = in[i][0];
    }
    dfs(0,-1,0);
    for(i=0;i<16;i++){
        for(j=0;j<N;j++){
            if(par[i][j]==-1){
                par[i+1][j]=-1;
            }else{
                par[i+1][j]=par[i][par[i][j]];
            }
        }
    }
    scanf("%d",&Q);
    for(i=0;i<Q;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        a--;b--;
        int c = lca(a,b);
        printf("%d\n",depth[a]+depth[b]-(2*depth[c])+1);
    }
} ./Main.c: In function ‘main’:
./Main.c:56:20: warning: initialization from incompatible pointer type [-Wincompatible-pointer-types]
     int (*in)[2] = (int*)malloc(sizeof(int)*N*2);
                    ^
./Main.c:48:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:60:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&x,&y);
         ^
./Main.c:86:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&Q);
     ^
./Main.c:89:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&a,&b);
         ^