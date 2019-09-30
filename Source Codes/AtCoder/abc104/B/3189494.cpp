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
  string S;
  cin>>S;
  if(S.at(0)=='A'){
    int sum=0;
    int x=0;
    for(int i=2;i<S.size()-1;i++){
      if(S.at(i)=='C'){
        sum++;
      }
    }
    for(int i=1;i<S.size();i++){
      if(S.at(i)>='A'&&S.at(i)<='Z'){
        x++;
      }
    }
    if(sum==1&&x==1){
      cout<<"AC"<<endl;
    }else{
      cout<<"WA"<<endl;
    }
    


  }else{
    cout<<"WA"<<endl;
  }


  


  



  
  
  

  


}