#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  int a,b,c,x;
  cin>>a>>b>>c;
  for(int i=0;i<c;i++){
    cin>>x;
    if(x>b)
      cout<<-1<<endl;
    else if(x<a)
      cout<<a-x<<endl;
    else
      cout<<0<<endl;
  }
}