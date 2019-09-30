#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> numOfLetter(255,0);
  char tmp;
  while(cin>>tmp){
  numOfLetter[tmp]++;
  
  }
  
  for(int i=97;i<=122;i++){
    if(numOfLetter[i]%2){
      cout<<"No"<<endl;
      return 0;
    }
  
  }
  
  cout<<"Yes"<<endl;
  return 0;
  
  
}