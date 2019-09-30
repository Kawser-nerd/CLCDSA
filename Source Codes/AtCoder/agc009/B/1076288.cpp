#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100000
vector<int> A;
vector<int> G[MAX_N];

int ans;

int min_depth(int a){
    if(G[a].size()==0) return 0;
    vector<int> M;
    for(auto to:G[a]){
        M.push_back(min_depth(to));
    }
    sort(M.begin(),M.end(),greater<int>());
    int ret = 0;
    for(int i=0;i<M.size();i++){
        ret = max(ret,M[i]+i+1);
    }
    return ret;
}

int main(){
    int N;
    cin>>N;
    for(int i=1;i<N;i++){
        int a;
        cin>>a;
        a--;
        A.push_back(a);
        G[a].push_back(i);//a?i??????
    }
    cout<<min_depth(0)<<endl;
    return 0;
}