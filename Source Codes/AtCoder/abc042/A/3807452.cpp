#include <iostream>
using namespace std;

int main(){
  int a, countF,countS;
  countF=countS=0;
  for(int i=0;i<3;i++){
    cin>>a;
    if(a==5){
      countF++;
    }
    else if(a==7){
      countS++;
    }
  }
  if(countF==2&&countS==1){
    cout<<"YES"<<endl;
   }
  else{
    cout<<"NO"<<endl;
  }
}