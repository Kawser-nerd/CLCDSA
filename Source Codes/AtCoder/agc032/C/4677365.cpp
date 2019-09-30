#include<cstdio>
#include<map>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int d[100001];
int n,m,a,b,f6=0,f4=0,f=0,cnt,flag[100000];
map<pair<int,int> ,int> ma;
vector<int> g[100001];
pair<int,int> e[100000];

int dfs(int x,int y,int z){
    int res;
    for(int i=0;i<g[x].size();i++){
        a=min(x,g[x][i]);
        b=max(x,g[x][i]);
        if(flag[ma[make_pair(a,b)]]==0){
            flag[ma[make_pair(a,b)]]=1;
            if(g[x][i]==z){
                return 1;
            }
            return dfs(g[x][i],x,z);
        }
    }
    return 0;
}

int main(){
    int x,y;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        d[a]++;
        d[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
        e[i]=make_pair(min(a,b),max(a,b));
        ma.insert(make_pair(e[i],i));
    }
    for(int i=1;i<=n;i++){
        f+=d[i]%2;
        if(d[i]>=6){
            f6=1;
        }
        if(d[i]==4){
            if(f4){
                y=i;
            }
            else{
                x=i;
            }
            f4++;
        }
    }
    if(f){
        printf("No\n");
    }
    else{
        if(f6||f4>=3){
            printf("Yes\n");
            return 0;
        }
        else if(f4<2){
            printf("No\n");
            return 0;
        }
        for(int i=0;i<4;i++){
            cnt+=dfs(x,-1,y);
        }
        if(cnt==2){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}