#include<iostream>
using namespace std;

int main(){
  int n;
  bool flag=false;
  cin>>n;
  char color[n];
  for(int i=0;i<n;i++){
    cin>>color[i];
    if(color[i]=='Y'){
      flag=true;
    }
  }
  if(flag){
    cout<<"Four"<<endl;
  }else{
    cout<<"Three"<<endl;
  }
  return 0;
}