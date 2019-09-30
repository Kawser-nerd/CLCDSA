#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 55;
int a,n;
LL c[N][N*N];
int main(){
  scanf("%d%d",&n,&a);
  c[0][0]=1;
  for(int i=1;i<=n;++i){
    int x;scanf("%d",&x);
    for(int j=i;j>=1;--j){
      for(int k=2500;k>=x;--k)
        c[j][k]+=c[j-1][k-x];
    }
  }
  for(int i=1;i<=2500;++i){
    for(int j=1;j<=n;++j)c[j][i]+=c[j][i-1];
  }
  LL ret=0;
  for(int i=1;i<=n;++i){
    int l=i*a;
    ret+=c[i][l]-c[i][l-1];
  }
  cout<<ret<<endl;
  return 0;
}