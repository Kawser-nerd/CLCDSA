#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  string s[20];
  string a;
  int count=0;
  for(int j=0;j<20;j++){
    cin>>s[j];
  }
  for(int i=0;i<20;i++){
    a=s[i];
    for(int k=0;k<a.size();k++){
      if(a[k]=='r'){
        count++;
        break;
      }
    }
  }
  cout<<count<<endl;
}