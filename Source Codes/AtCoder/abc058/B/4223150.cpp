#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  for(int i=0;i<t.size();i++){
    cout<<s[i]<<t[i];
  }
  if(s.size()>t.size())
    cout<<s[s.size()-1]<<endl;
  else
    cout<<endl;
}