#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
using namespace std;
int main(){
  char s;
  string t;
  cin>>s>>t;
  for(int i=0;i<t.size();i++){
    if(s!=t[i]){
      cout<<t[i];
    }
  }
  cout<<endl;
}