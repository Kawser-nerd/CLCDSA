#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<numeric>
using namespace std;
int input(){
  int x;
  cin>>x;
  return x;
}
int abs(int x){
  if(x>=0){
    return x;
  }else{
    return -x;
  }
}
int gcd(int x, int y){
	if(x<y){
    return gcd(y,x);
  }
  if(y==0){
    return x;
  }
  return gcd(y,x%y);
}



int main() {
  int R=input();
  if(R<1200){
    cout<<"ABC"<<endl;
  }else if(R<2800){
    cout<<"ARC"<<endl;
  }else{
    cout<<"AGC"<<endl;
  }

  


  



  
  
  

  


}