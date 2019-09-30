#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  
  int a,b;
  cin>>a>>b;
  string s,t;
  cin>>s>>t;
  
  map<char,int> mps,mpt;
  for(char c='A';c<='Z';c++){
    mps[c]=0;
    mpt[c]=0;
  }
  for(int i=0;i<a;i++){
    mps[s[i]]++;
  }
  for(int i=0;i<b;i++){
    mpt[t[i]]++;
  }
  int result =0;
  for(char c='A';c<='Z';c++){
    if(mps[c]&&!mpt[c]){
      cout<<-1<<endl;
      return 0;
    }else if(mpt[c]){
      result=max(result,(mps[c]%mpt[c]>0)+mps[c]/mpt[c]);
    }
  }
  cout<<result<<endl;
  return 0;

}