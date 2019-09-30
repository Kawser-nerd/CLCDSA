#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
using namespace std;
int main(){
  int n,count=0,a;
  cin>>n;
  for(int i=2;i<n;i++){
    a=n%i;
    if(a==0){
      count++;
      break;
    }
  }
  if(count==1)
    cout<<"NO"<<endl;
  else
    cout<<"YES"<<endl;
}