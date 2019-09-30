#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  string x;
  char y;
  int ns=0,ew=0,n=0,e=0,w=0,s=0;
  cin>>x;
  for(int i=0;i<x.size();i++){
    y=x[i];
    if(y=='N')
      n++;
    else if(y=='E')
      e++;
    else if(y=='S')
      s++;
    else
      w++;
  }
  if(n!=0 and s!=0){
    ns++;
  }
  if(e!=0 and w!=0){
    ew++;
  }
  if(ns==1 and ew==1)
    cout<<"Yes"<<endl;
  else if(ns==0 and ew==0)
    cout<<"No"<<endl;
  else if(ns==1 and e==0 and w==0)
    cout<<"Yes"<<endl;
  else if(ew==1 and n==0 and s==0)
    cout<<"Yes"<<endl;
  else 
    cout<<"No"<<endl;
}