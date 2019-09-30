#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  int a,b,all=0;
  cin>>a>>b;
  int cost[a];
  for(int i=0;i<a;i++){
    cin>>cost[i];
    all+=cost[i];
  }
  sort(cost,cost+a);
  b-=all;
  b=b/cost[0];
  cout<<a+b<<endl;
}