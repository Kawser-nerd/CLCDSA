#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  long long int a,b;
  cin>>a>>b;
  if(a==0){
    if(b!=100)
      cout<<b<<endl;
    else
      cout<<101<<endl;
  }
  else if(a==1){
    if(b!=100)
      cout<<100*b<<endl;
    else
      cout<<10100<<endl;
    }
  else{
    if(b!=100)
      cout<<b*10000<<endl;
    else
      cout<<1010000<<endl;
  }   
}