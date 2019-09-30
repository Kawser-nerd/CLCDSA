#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  long long int a,b=0,aa=1,bb=3;
  cin>>a;
  if(a==1)
    cout<<1<<endl;
  else if(a==2)
    cout<<3<<endl;
  else{
    for(int i=2;i<a;i++){
      b=aa+bb;
      aa=bb;
      bb=b;
    }
    cout<<b<<endl;
  } 
}