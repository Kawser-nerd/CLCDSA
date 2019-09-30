#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int sum(int x){
  int ans=0;
  while(x>0){
    ans+=x%10;
    x/=10;
  }
  return ans;
}

int main(){
  int num,a;
  cin>>num;
  a=sum(num);
  if(num%a==0)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}