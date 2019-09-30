#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  string s;
  cin>>s;
  if(s[0]>='a' and s[0]<='z')
    s[0]=s[0]+'A'-'a';
  for(int i=1;i<s.size();i++){
    if(s[i]>='A' and s[i]<='Z')
      s[i]=s[i]+'a'-'A';
  }
  cout<<s<<endl;
}