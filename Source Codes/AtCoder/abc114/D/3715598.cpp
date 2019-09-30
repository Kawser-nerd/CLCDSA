#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<vector<int>> a;
  for(int i=2;i<=N;++i){
    int k=i;
  	for(int j=2;j<=i;++j){
      if(k==1)break;
      if(k%j==0){
        auto f=find_if(a.begin(),a.end(),[&j](vector<int> aa){return aa[0]==j;});
        if(f!=a.end()){
          (*f)[1]++;
        }else{
          a.push_back(vector<int>{j,1});
        }
        k/=j;
        j--;
      }
    }
  }
  for(auto b:a){
    //cout<<b[0]<<" "<<b[1]<<endl; 
  }
  int num=0;
  for(auto b:a){
    if(b[1]<4)continue;
    for(auto c:a){
      if(c[1]<4)continue;
      if(b[0]>=c[0])continue;
      for(auto d:a){
        if(d[1]<2)continue;
        if(b[0]==d[0])continue;
        if(c[0]==d[0])continue;
        num++;
      }
    }
    if(b[1]<14)continue;
    for(auto c:a){
      if(b[0]==c[0])continue;
      if(c[1]<4)continue;
      num++;
    }
    if(b[1]<24)continue;
    for(auto c:a){
      if(b[0]==c[0])continue;
      if(c[1]<2)continue;
      num++;
    }
    if(b[1]>=74)num++;
  }
 
  cout<<num<<endl;
  return 0;
}