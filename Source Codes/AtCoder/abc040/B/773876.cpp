#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int n;
  int a, b, c, d;
  int m=1<<31;
  cin>>n;
  m--;
  a=1;
  d=int(sqrt(n));
  while(a<=d){
    b=n/a;
    c=n-a*b;
    if(m>abs(a-b)+c){
      m=abs(a-b)+c;
    }
    a++;
  }
  cout<<m<<endl;
  
  return 0;
}