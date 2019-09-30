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

double eps=1e-10;

typedef long long lint;

using namespace std;

int main(){
  int N;
  cin>>N;
  lint x[N],y[N];
  REP(i,N)cin>>x[i]>>y[i];
  int ans[3]={0};
  REP(i,N){
    int temp[3]={0};
    vector<double> theta;
    REP(j,N){
      if(i==j)continue;
      theta.push_back(atan2(x[j]-x[i],y[j]-y[i]));
    }
    sort(ALL(theta));
    REP(i,N-1)theta.push_back(theta[i]+2.0*M_PI);
    int r=0;
    // REP(j,2*(N-1))cerr<<theta[j]*180.0/M_PI<<" ";
    // cerr<<endl;
    REP(l,N-1){
      while(theta[r+1]-theta[l]<(M_PI/2.0)+eps){
        r++;
      }
      if(r==l){
        r++;
        continue;
      }
      temp[0]+=r-l;
      if(theta[r]-theta[l]>(M_PI/2.0)-eps){
        temp[0]--;
        temp[1]++;
      }
      // cerr<<l<<" "<<r<<" "<<(theta[r]-theta[l])*180.0/M_PI<<endl;
      
    }
    temp[2]=((N-1)*(N-2))/2-temp[0]-temp[1];
    REP(j,3)ans[j]+=temp[j];
  }
  ans[0]-=2*(ans[1]+ans[2]);
  ans[0]/=3;
  cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
  return 0;
}