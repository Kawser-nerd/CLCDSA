#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  lint N,M;
  cin>>N>>M;
  lint S=0;
  map<lint,lint> m;
  m[0]=1;
  REP(i,N){
    int A;
    cin>>A;
    S+=A;
    S%=M;
    m[S]+=1;
  }
  lint ans=0;
  for(auto e:m){
    // cerr<<e.first<<" "<<e.second<<endl;
    ans+=(e.second*(e.second-1))/2;
  }
  cout<<ans<<endl;
  return 0;
}