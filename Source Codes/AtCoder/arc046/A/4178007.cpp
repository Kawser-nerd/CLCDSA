#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
using namespace std;
int main(){
  int n,a,b;
  cin>>n;
  a=n/9;
  b=n%9;
  if(b==0){
    for(int i=0;i<a;i++){
      cout<<9;
    }
  }
  else{
    for(int j=0;j<a+1;j++){
      cout<<b;
    }
  }
  cout<<endl;
}