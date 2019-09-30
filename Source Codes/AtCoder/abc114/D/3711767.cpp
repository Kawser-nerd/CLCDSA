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
  int N;
  cin>>N;
  int s[100]={0};
  REP(i,N){
    int k=i+1;
    FOR(j,2,k+1){
      while(k%j==0){
        k/=j;
        s[j]++;
      }
    }
  }
  // REP(i,10)cerr<<s[i]<<endl;
  int ans=0;
  REP(i,100)if(s[i]>=74)ans++;
  REP(i,100)REP(j,100){
    if(i==j)continue;
    if(s[i]>=2 and s[j]>=24)ans++;
    if(s[i]>=4 and s[j]>=14)ans++;
  }
  REP(i,100)REP(j,100)REP(k,j){
    if(i==j or i==k)continue;
    if(s[i]>=2 and s[j]>=4 and s[k]>=4)ans++;
  }
  cout<<ans<<endl;
  return 0;
}