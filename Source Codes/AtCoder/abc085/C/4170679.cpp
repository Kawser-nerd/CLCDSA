#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
  int n,x,sum,cc=-1,aa=-1,bb=-1;
  cin>>n>>x;
  for(int i=0;i<=n;i++){
    for(int j=0;i+j<=n;j++){
    sum=i*10000+j*5000+(n-i-j)*1000;
    if(sum==x){
      aa=i;
      bb=j;
      cc=n-i-j;
    }
    }
  }
  cout<<aa<<" "<<bb<<" "<<cc<<endl;
}