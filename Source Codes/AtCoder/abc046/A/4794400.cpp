#include <iostream>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int N,K,X,ans;
  cin >> N;
  cin >> K;
  cin >> X;
  ans=1;
  if(N!=K)ans++;
  if(N!=X&&K!=X)ans++;
  cout << ans<<endl;
  
    return 0;
}