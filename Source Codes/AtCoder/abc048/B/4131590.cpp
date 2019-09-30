#include<iostream>
using namespace std;
int main(){
  long a,b,x,o,p,q;
  cin>>a>>b>>x;
  if(a==0){
      cout<<b/x+1<<endl;
  }
  else{
    o=(a-1)/x;
    p=b/x;
    cout<<p-o<<endl;
  }
}