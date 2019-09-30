#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  int a,b,c=0;
  cin>>a>>b;
  for(int i=1;i<b-a;i++){
    c+=i;
  }
  cout<<c-a<<endl;
}