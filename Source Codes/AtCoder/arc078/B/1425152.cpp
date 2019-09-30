#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;

vector<int> G[100000];
int color[100000];//0:empty,1:black,-1:white
int N;

void dfs2(int v, int pre, int col){
    color[v]=col;
    for(auto to:G[v]){
        if(to!=pre&&color[to]==0) dfs2(to,v,col);
    }
    return;
}

int dfs1(int v, int pre, int depth){
    if(v==N-1){
        color[v]=-1;
        for(auto to:G[v]){
            if(to!=pre) dfs2(to,v,-1);
        }
        return depth;
    }
    if(G[v].size()==1&&v!=0) return -1;
    for(auto to:G[v]){
        if(to!=pre){
            int length = dfs1(to,v,depth+1);
            if(length!=-1){
                int col;
                if(depth<=length/2){
                    col=1;
                }else{
                    col=-1;
                }
                // cout<<v+1<<' '<<col<<endl;
                color[v]=col;
                for(auto to2:G[v]){
                    if(to2!=pre&&color[to2]==0) dfs2(to2,v,col);
                }
                return length;
            }
        }
    }
    return -1;
}

int main(){
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs1(0,-1,0);
    int cnt = 0;
    for(int i=0;i<N;i++){
        // cout<<i+1<<' '<<color[i]<<endl;
        cnt+=color[i];
    }
    // cout<<cnt<<endl;
    if(cnt>0){
        cout<<"Fennec"<<endl;
    }else{
        cout<<"Snuke"<<endl;
    }

    return 0;
}