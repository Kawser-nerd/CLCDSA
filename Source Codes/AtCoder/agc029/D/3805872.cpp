#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>

#define FORi(N) for(LL i=0;i<N;++i)
#define FABi(a,b) for(LL i=a;i<=b;++i)

using namespace std;
using LL = long long;
using LD = long long;
using LLV = vector<LL>;
using LDV = vector<LD>;
using LLVV = vector<vector<LL> >;
int main(){
  LL H,W,N;
  cin>>H>>W>>N;
  if(N==0){
    cout<<H<<endl;
    return 0;
  }
  LLVV XY;
  FORi(N){
    LL  x,y;
    cin>>x>>y;
    if(x+1<y)continue;
    LLV xy{x,y};
    XY.push_back(xy);
  }
  if(XY.size()==0){
    cout<<H<<endl;
    return 0;
  }
  sort(XY.begin(),XY.end(),[](LLV a,LLV b){
    if(a[0]<b[0]){
      return true;
    }else if(a[0]==b[0]){
      return a[1]<b[1];
    }else{return false;}
  });
  LL x=2,y=2;
  LL b;
  bool flag=false;
  bool yflag=true;
  LL id=0;
  b=0;
  while(true){
    while(XY[id][0]==x){
      if(XY[id][1]<y){
        flag=true;
        break;
      }
      ++id;
      if(id>=XY.size()){
        flag=true;
        x=H+1;
        break;
      }
    }
    if(flag)break;
    id=b;
    yflag=true;
    while(XY[id][0]==x){
      if(XY[id][1]==y)yflag=false;
      ++id;
      if(id>=XY.size()){
        --id;
        break;
      }
    }
    //e=id-1;
    ++x;
    if(x>H){
      x=H+1;
      break;
    }
    if(yflag)++y;
    b=id;
  }
  cout<<x-1<<endl;
  return 0;
}