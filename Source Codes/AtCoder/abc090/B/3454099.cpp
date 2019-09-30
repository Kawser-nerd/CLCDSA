#include <iostream>
#include <string>

using namespace std;

int main(){

  int a,b;
  cin>>a>>b;
  int result=0;
  string tmp;
  for(int i=a;i<=b;i++){
    tmp=to_string(i);
    if(tmp[0]==tmp[4]&&tmp[1]==tmp[3]){
      result++;
    }
    
  
  }
  cout<<result<<endl;
  return 0;
}