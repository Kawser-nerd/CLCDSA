#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<bool> v(26,false);
  char c;
  while(cin>>c){
    v[c-'a']=!v[c-'a'];
  }
  for(int i=0;i<26;i++){
    if(v[i]){
      cout<<"No"<<endl;
      return 0;
    }
  
  }
  cout<<"Yes"<<endl;
  return 0;
}