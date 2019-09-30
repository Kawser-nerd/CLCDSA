#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<c-(d-b)<<" "<<d+c-a<<" "<<a+b-d<<" "<<b+c-a<<endl;
}