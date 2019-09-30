#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  long long int a,b,c,d,e;
  cin>>a>>b>>c;
  d=(a%1000000007)*(b%1000000007);
  e=(d%1000000007)*(c%1000000007);
  cout<<e%1000000007<<endl;
}