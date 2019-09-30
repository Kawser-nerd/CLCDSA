#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
typedef double lld;

lld pow2(lld value){
  return value*value;
}

const lld PI=acos(-1);

int main(){
  int N,Q;
  cin>>N>>Q;
  int x[105];
  int r[105];
  int h[105];
  for(int i=0;i<N;i++){
    cin>>x[i]>>r[i]>>h[i];
  }
  for(int q=0;q<Q;q++){
    lld ans=0.0;
    int A,B;
    cin>>A>>B;
    for(int i=0;i<N;i++){
      if(B < x[i] || x[i]+h[i] < A) continue;
      int a = max(A,x[i]);
      int b = min(B,x[i]+h[i]);
      //      lld total=r[i]*r[i]*PI*h[i]/3;
      int ah=h[i]+x[i]-a;
      int bh=h[i]+x[i]-b;
      ans+=(pow2((lld)ah*r[i]/h[i])*PI*ah-pow2((lld)bh*r[i]/h[i])*PI*bh)/3;
      
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
  }
  return 0;
}