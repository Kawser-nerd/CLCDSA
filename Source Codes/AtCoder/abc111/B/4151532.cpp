#include<iostream>
using namespace std;
int main(){
  int n,x,ans;
  cin>>n;
  x=n/111;
  if(n%111==0)
    cout<<x*111<<endl;
  else
    cout<<(x+1)*111<<endl;
}