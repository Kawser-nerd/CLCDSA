#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  int n,a=1;
  cin>>n;
  if(n==1)
    cout<<1<<endl;
  else{
    for(int i=0;i<100;i++){
      a*=2;
      if(a>n)
        break;
    }
    cout<<a/2<<endl;
  }
}