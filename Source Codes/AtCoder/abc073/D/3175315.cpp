#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
  int n,m,r;
  cin>>n>>m>>r;
  vector<int> order;
  for(int i=0;i<r;++i) {
    int val;
    cin>>val;
    order.push_back(val);
  }
  sort(order.begin(),order.end());

  int d[201][201];
  for(int i=0;i<201;++i){
    for(int j=0;j<201;++j){
      d[i][j] = 1e9;
    }
  }
  for(int i=0;i<m;++i) {
    int a,b,c;
    cin>>a>>b>>c;
    d[a][b] = c;
    d[b][a] = c;
  }

  for(int k=1;k<n+1;++k){
    for(int i=1;i<n+1;++i){
      for(int j=1;j<n+1;++j){
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }

  int ret = 1e9;
  do{
    int tmp = 0;
    for(int i=0;i<r-1;++i){
      tmp += d[order[i]][order[i+1]];
    }
    ret = min(ret, tmp);
  }while(next_permutation(order.begin(), order.end()));
  cout<<ret<<endl;

  return 0;
}