#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  int n;
  int count=0,y=0,x=0,a=0;
  string name[1100];
  int num[1100]; 
  int ans[1100];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>name[i]>>num[i];
    y+=num[i];
    ans[i]=num[i];
    x=max(num[i],a);
    if(num[i]>=a)
      a=num[i];
  }
  for(int j=0;j<n;j++){
    if(x==num[j]){
      break;
    }
    else
      count++;
  }
  if((y-x)<x)
    cout<<name[count]<<endl;
  else
    cout<<"atcoder"<<endl;
}