#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
  int n,k,a,x=0;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>a;
    if(a>=abs(k-a)){
      x+=(abs(k-a))*2;
    }
    else
      x+=a*2;
  }
  cout<<x<<endl;
}