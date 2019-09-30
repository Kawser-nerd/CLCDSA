#include <iostream>
#include <string>
using namespace std;

using ll = long long;

#define for_(i, a, b) for(int i = (a);i < (b);++i)
#define rfor_(i, a, b) for(int i = (b)-1;i >= (a);--i)
#define rep(i, n) for_(i, 0, n)
#define rrep(i, n) rfor_(i, 0, n)

string S;
int L;
bool c = true;

int main() {
  cin.tie(0);cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  cin>>S;
  
  L = S.length();
  
  c &= (S[0]=='A');
  
  int t = 0;
  for_(i, 2, L-1)if(S[i]=='C')t++;
  c &= (t==1);
  
  t = 0;
  rep(i, L)if('a' <= S[i] && S[i] <= 'z')t++;
  
  c &= (t==L-2);
  
  cout<<(c?"AC":"WA")<<endl;
  
  return 0;
}