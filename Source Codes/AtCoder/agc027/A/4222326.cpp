#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  long int n,count=0,x,aa=0;
  cin>>n>>x;
  long int num[n];
  for(int i=0;i<n;i++){
    cin>>num[i];
    aa+=num[i];
  }
  sort(num,num+n);
  if(aa<x)
    cout<<n-1<<endl;
  else{
    for(int j=0;j<n;j++){
      if(x>=num[j]){
        count++;
        x-=num[j];
      }
    else
      break;
    }
    cout<<count<<endl;
  }
}