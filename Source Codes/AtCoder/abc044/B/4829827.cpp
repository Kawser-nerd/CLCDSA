#include <iostream>
#include <string>
 
using namespace std;
 
int main(){
  string S;
  cin>>S;
  int b=0;
  for(auto c:S){
    b^=(1<<(c-'a'));
  }
  cout<<(b?"No":"Yes")<<endl;
}