#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  string s;
  int a=0,b=0,c=0,d=0,e=0,f=0;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='A')
      a++;
    else if(s[i]=='B')
      b++;
    else if(s[i]=='C')
      c++;
    else if(s[i]=='D')
      d++;
    else if(s[i]=='E')
      e++;
    else
      f++;
  }
  cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
}