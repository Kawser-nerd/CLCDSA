#include<iostream>
#include <string>
using namespace std;
int main(){
  string s;
  cin>>s;
  cout<<((s.size()%2==0)==(s[0]==s[s.size()-1])?"First":"Second")<<endl;
}