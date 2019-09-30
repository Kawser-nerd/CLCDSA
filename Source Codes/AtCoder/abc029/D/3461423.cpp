#include <iostream>
#include <math.h>
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

lint pow10(int k){
  lint ans=1;
  REP(i,k)ans*=10;
  return ans;
}

int main(){
  lint N;
  cin>>N;
  lint ans=0;
  REP(i,10){
    if((N/pow10(i))%10==0)ans+=(N/pow10(i+1))*pow10(i);
    else if((N/pow10(i))%10==1)ans+=N%pow10(i)+1+(N/pow10(i+1))*pow10(i);
    else ans+=(N/pow10(i+1)+1)*pow10(i);
  }
  cout<<ans<<endl;
  return 0;
}