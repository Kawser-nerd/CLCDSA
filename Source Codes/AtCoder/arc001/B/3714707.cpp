#include <iostream>
#include <cmath>

using namespace std;

int main(){
 
  int a,b;
  cin>>a>>b;
  int dif=abs(a-b),result=dif/10;
  dif%=10;
  while(dif!=0){
    if(dif>=8){
      dif-=10;
    }else if(dif>=3){
      dif-=5;
    }else{
      dif--;
    }
    result++;
    dif=abs(dif);
  }
  cout<<result<<endl;
  return 0;
}