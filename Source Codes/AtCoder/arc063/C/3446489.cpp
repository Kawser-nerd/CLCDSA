#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int SIZE=100005;
const int INF=100000005;

vector<int> mp[SIZE];
int id[SIZE],L[SIZE],R[SIZE];
bool ok=true;

void solve(int v,int p){
    if(id[v]==-1){
        L[v]=-INF;
        R[v]=INF;
    }
    else{
        L[v]=R[v]=id[v];
    }
    for(int i=0;i<mp[v].size();i++){
        int to=mp[v][i];
        if(to==p) continue;
        solve(to,v);
        if(L[to]<-INF/2) continue;
        if(!(L[v]<-INF/2)){
            if(L[to]%2==L[v]%2){
                ok=false;
                return;
            }
        }
        L[v]=max(L[to]-1,L[v]);
        R[v]=min(R[to]+1,R[v]);
        if(L[v]>R[v]){
            ok=false;
            return;
        }
    }
}

void make(int v,int p){
    for(int i=0;i<mp[v].size();i++){
        int to=mp[v][i];
        if(to==p) continue;
        if(id[to]==-1){
            if(L[to]<=id[v]+1 && id[v]+1<=R[to]) id[to]=id[v]+1; else id[to]=id[v]-1;
        }
        make(to,v);
    }
}

int main(){
    int n,k;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        mp[a].push_back(b);
        mp[b].push_back(a);
        id[i]=-1;
    }
    id[n-1]=-1;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int v,p;
        scanf("%d%d",&v,&p);
        v--;
        id[v]=p;
    }
    solve(0,-1);
    if(!ok) puts("No");
    else{
        puts("Yes");
        id[0]=L[0];
        make(0,-1);
        for(int i=0;i<n;i++) printf("%d\n",id[i]);
    }
    return 0;
}