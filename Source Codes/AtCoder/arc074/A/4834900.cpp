#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
using P=pair<int64_t,int64_t>;

P maxmin(int64_t H, int64_t W){//2?????????????
  if(H%2==0||W%2==0){
    return P(H*W/2,H*W/2);
  }else{
    if(H<W) swap(H,W);//then H>=W
    return P((H/2)*W,(H/2+1)*W);
  }
}

int main(){
  int64_t H,W;
  cin>>H>>W;
  int64_t ans=1000000;
  for(int64_t h=1;h<H;h++){
    int64_t S1,S2;
    tie(S1,S2)=maxmin(H-h,W);
    int64_t Smax = max({h*W,S1,S2});
    int64_t Smin = min({h*W,S1,S2});
    ans=min(ans,Smax-Smin);
  }
  swap(H,W);
  for(int64_t h=1;h<H;h++){
    int64_t S1,S2;
    tie(S1,S2)=maxmin(H-h,W);
    int64_t Smax = max({h*W,S1,S2});
    int64_t Smin = min({h*W,S1,S2});
    ans=min(ans,Smax-Smin);
  }
  cout<<ans<<endl;
  return 0;
}