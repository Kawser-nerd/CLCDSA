#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
using namespace std;
int main(){
  int n,x;
  cin>>n>>x;
  if(n<=0 and x>=0){
    cout<<"Zero"<<endl;
  }
  else if(n>0 and x>0){
    cout<<"Positive"<<endl;
  }
  else{
    int count;
    count=abs(n-x)+1;
    if(count%2==0){
      cout<<"Positive"<<endl;
    }
    else{
      cout<<"Negative"<<endl;
    }
  }
}