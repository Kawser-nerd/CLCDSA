#include <iostream>
#include <cmath>

using namespace std;

int main(){

  long long int x,y;
  cin>>x>>y;
  
  int i=1;
  while(x*((long long int)pow(2,i))<=y){
    i++;
  }
  cout<<i<<endl;


  return 0;
}