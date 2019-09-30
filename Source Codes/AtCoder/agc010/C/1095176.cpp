#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> G[100000];
int64_t A[100000];
int N;

bool flag = true;

int64_t rec(int v, int parent){
    // cout<<v<<endl;
    if(!flag) return 0;
    vector<int64_t> f;
    for(auto c:G[v]){
        if(c!=parent) f.push_back(rec(c,v));
    }
    if(!flag) return 0;
    if(!f.size()) return A[v];
    int64_t F = 0;
    for(auto e:f) F+=e;
    int64_t G = A[v];
    int64_t down = F-G;
    int64_t up = G-down;
    int64_t ret = up;
    if(up<0||down<0){
        flag = false;
        return 0;
    }
    f.push_back(up);
    //???????????
    if(down){
        sort(f.begin(), f.end(),greater<int64_t>());
        F+=up;
        if(F%2||f[0]>F/2){
            // cout<<v<<'C'<<endl;
            flag = false;
            return 0;
        }
    }
    return ret;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    for(auto &g:G) g.clear();
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(rec(0,-1)&&G[0].size()!=1)flag=false;
    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}