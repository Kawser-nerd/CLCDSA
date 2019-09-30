#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  long int n,a,b;
  cin>>n>>a>>b;
  if(a>b)
    cout<<0<<endl;
  else if(n==1){
    if(a!=b)
      cout<<0<<endl;
    else
      cout<<1<<endl;
  }
  else if(n==2 or a==b){
      cout<<1<<endl;
  }
  else{
    cout<<(b-a)*(n-2)+1<<endl;
  }
}