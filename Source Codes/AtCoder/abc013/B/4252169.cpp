#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  int n,x;
  cin>>n>>x;
  if(abs(n-x)>=6)
    cout<<10-abs(n-x)<<endl;
  else
    cout<<abs(n-x)<<endl;
}