#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  int n,count=0,x=0;
  int y[1000];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>y[i];
    x+=y[i];
    if(y[i]!=0)
      count++;
  }
  cout<<(x+count-1)/count<<endl;
}