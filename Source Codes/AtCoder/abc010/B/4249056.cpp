#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  int count=0,n;
  cin>>n;
  int x[20];
  for(int i=0;i<n;i++){
    cin>>x[i];
    int y=x[i];
    if(y==2 or y==4 or y==8)
      count++;
    else if(y==5)
      count+=2;
    else if(y==6)
      count+=3;
  }
  cout<<count<<endl;
}