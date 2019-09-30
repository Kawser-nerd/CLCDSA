#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<climits>
#include<cstdlib>
#include<map>
#include<math.h>
#include<utility>
#include<vector>
using namespace std ;
typedef long long ll;

// N K
// A_1, ..., A_N
int main(){
  int N, K ;
  cin >> N >> K ;

  vector<int> h ;
  for(int i=0; i!=N; ++i)
  {
    int tmp ;
    cin >> tmp ;
    h.push_back(tmp) ;
  }

  sort(h.begin(),h.end(),greater<int>());

  long long ans = 1000000010;
  for(int i=0; i != N-K+1; ++i){
    long long tmp = h[i] - h[i+K-1] ;
    if(ans>tmp)
      ans = tmp ;
  }
  cout << ans << endl ;
}