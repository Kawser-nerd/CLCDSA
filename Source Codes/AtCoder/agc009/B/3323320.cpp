#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

#define MAXN 100000
int N;
int Height[MAXN+5];
vector<int> G[MAXN+5];

bool cmp(int x,int y){
    return Height[x]>Height[y];
}
void dfs(int u){
    for(int i=0;i<int(G[u].size());i++)
        dfs(G[u][i]);
    sort(G[u].begin(),G[u].end(),cmp);
    for(int i=0;i<int(G[u].size());i++)
        Height[u]=max(Height[u],Height[G[u][i]]+i+1);
}

int main(){
    scanf("%d",&N);
    for(int i=2;i<=N;i++){
        int fa;
        scanf("%d",&fa);
        G[fa].push_back(i);
    }
    dfs(1);
    printf("%d",Height[1]);
}