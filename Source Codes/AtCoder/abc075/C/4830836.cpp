#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> G;
vector<int> preorder;
vector<int> low;
using P = pair<int,int>;

void lowlink(int v,int prev, int &pre, vector<P>& ans){
  preorder[v]=pre;
  low[v]=pre;
  for(auto to:G[v]){
    if(preorder[to]==-1){
      lowlink(to,v,++pre,ans);
      if(low[to]==preorder[to]){
        ans.emplace_back(min(v,to),max(v,to));
      }
      low[v]=min(low[v],low[to]);
    }else if(to!=prev){
      low[v]=min(low[v],preorder[to]);
    }
  }
}

int main(){
  int V,E;
  cin>>V>>E;
  G.resize(V);
  preorder.resize(V,-1);
  low.resize(V);

  for(int i=0;i<E;i++){
    int s,t;
    cin>>s>>t;
    s--;t--;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  int p=1;
  vector<P> ans;
  lowlink(0,-1,p,ans);
  cout<<ans.size()<<endl;
}