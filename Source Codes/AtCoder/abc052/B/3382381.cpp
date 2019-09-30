#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n;cin>>n;
  
  int now_num=0,result=0;
  
  char tmp;
  for(int i=0;i<n;i++){
    cin>>tmp;
    if(tmp=='I'){
      now_num++;
      result=max(result,now_num);
    }else{
    now_num--;
    }
  
  }


  cout<<result<<endl;
  return 0;
}