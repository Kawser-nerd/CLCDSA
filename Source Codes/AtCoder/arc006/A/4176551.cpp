#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
using namespace std;
int main(){
  int e[6];
  int l[6];
  int b,count=0,sum=0;
  for(int i=0;i<6;i++){
    cin>>e[i];
  }
  cin>>b;
  for(int j=0;j<6;j++){
    cin>>l[j];
  }
  for(int k=0;k<6;k++){
    for(int x=0;x<6;x++){
      if(e[k]==l[x]){
        count++;
      }
    }
  }
  sort(e,e+6);
  sort(l,l+6);
  for(int aa=0;aa<6;aa++){
    if(e[aa]!=l[aa]){
      if(l[aa]==b)
        sum++;
    }
  }
  if(count==6)
    cout<<1<<endl;
  else if(count==5){
    if(sum==1)
      cout<<2<<endl;
    else
      cout<<3<<endl;
  }
  else if(count==4)
    cout<<4<<endl;
  else if(count==3)
    cout<<5<<endl;
  else
    cout<<0<<endl;
}