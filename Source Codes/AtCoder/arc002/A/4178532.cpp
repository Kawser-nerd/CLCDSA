#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
using namespace std;
int main(){
  int n,a=0,b=0,c=0;
  cin>>n;
  if(n%4==0){
    a=1;
  }
  if(n%100==0){
    b=1;
  }
  if(n%400==0){
    c=1;
  }
  if(c==1){
    cout<<"YES"<<endl;
  }
  if(b==1 and c==0){
    cout<<"NO"<<endl;
  }
  if(a==1 and b==0 and c==0){
    cout<<"YES"<<endl;
  }
  if(a==0 and b==0 and c==0){
    cout<<"NO"<<endl;
  }
}