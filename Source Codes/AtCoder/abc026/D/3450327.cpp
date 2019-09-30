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
  double A,B,C;

double f(double t){
  return 100.0-A*t-B*sin(C*t*M_PI);
}
int main(){
  cin>>A>>B>>C;
  double r=1.0/(2.0*C);
  // cout<<r<<endl;
  while(f(r)>0)r+=1.0/C;
  double l=r-1.0/C;
  // cout<<l<<r<<endl;
  // cout<<f(l)<<f(r)<<endl;
  while(f(l)>0.00000001){
    if(f((r+l)/2.0)<0)r=(r+l)/2.0;
    else l=(r+l)/2.0;
  }
  cout<<fixed<<setprecision(16)<<l<<endl;
  // cout<<f(l)<<endl;
  return 0;
}