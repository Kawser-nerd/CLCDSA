#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<bool> v(26,false);
  char c;
  while(cin>>c){
    v[c-'a']=true;
  }
  for(int i=0;i<26;i++){
    if(!v[i]){
      cout<<(char)('a'+i)<<endl;
      return 0;
    }
  
  }
  cout<<"None"<<endl;
  return 0;
}