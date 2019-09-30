#include <iostream>

using namespace std;

int main(){
  string str;
  cin>>str;

  if(str[str.length()-1]=='T') cout<<"YES"<<endl;
  else  cout<<"NO"<<endl;

  return 0;
}