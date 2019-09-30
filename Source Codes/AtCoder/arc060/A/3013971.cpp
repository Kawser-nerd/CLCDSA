#include<iostream>
#include<vector>
using namespace std;
using ull = unsigned long long;

int main() {
  int n,a;
  cin>>n>>a;
  vector<int> x;
  for (int i=0;i<n;++i) {
    int tmp;
    cin>>tmp;
    x.push_back(tmp);
  }

  vector<vector<vector<ull> > > dp
    = vector<vector<vector<ull> > >(n+1, vector<vector<ull> >(n+1, vector<ull>(n*a+1, 0)));

  dp[0][0][0] = 1;
  for (int j=0;j<n+1;++j) {
    for (int k=0;k<n+1;++k) {
      for (int s=0;s<n*a+1;++s) {
        if (j>0 && s<x[j-1]) {
          dp[j][k][s] = dp[j-1][k][s];
        } else if (j>0 && k>0 && s>=x[j-1]) {
          dp[j][k][s] = dp[j-1][k][s] + dp[j-1][k-1][s-x[j-1]];
        }
      }
    }
  }

  unsigned long long ret = 0;
  for (int k=1;k<n+1;++k) {
    ret += dp[n][k][k*a];
  }
  cout<<ret<<endl;
  return 0;
}