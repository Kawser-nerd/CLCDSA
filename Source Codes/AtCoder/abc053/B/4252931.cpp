#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  string s;
  int start=0,end;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='A'){
      start=i;
      break;
    }
  }
  for(int j=s.size()-1;j>=0;j--){
    if(s[j]=='Z'){
      end=j;
      break;
    }
  }
  cout<<end-start+1<<endl;
}